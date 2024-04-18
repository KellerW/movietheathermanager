#include <iostream>
#include <crow.h>
#include "models.cpp"
#include "relations.cpp"

using namespace std;

 int main (int argc, char *argv [])
 {
   crow::SimpleApp app;
   
   CROW_ROUTE(app, "/")
   ([]() {
      return crow::mustache::load("cinemas.html").render();
   });
   CROW_ROUTE(app, "/api/cinemas")
   ([]() {
      crow::json::wvalue result = {};
      for (auto item : cinemas)
      {
         auto id_cinema = to_string(item.first);
         auto cinema = item.second;
         result[id_cinema] = cinema.nome;
      }
      
      return result;
   });
   
   CROW_ROUTE(app, "/cinema")
   ([](const crow::request& req) 
   {
      auto id_cinema = req.url_params.get("id_cinema");
      crow::mustache::context ctx({
         {"id_cinema", id_cinema },
         {"nome_cinema", cinemas[stoi(id_cinema)].nome }
      });
      return crow::mustache::load("cinema.html").render(ctx);
   });
   CROW_ROUTE(app, "/api/filmes")
   ([](const crow::request& req) {
      crow::json::wvalue result = {};
      auto url_id_cinema = stoi(req.url_params.get("id_cinema"));
      int index = 0;
      for (auto item : room_filme) {
         auto id_room = item.first;
         auto id_filme = item.second;
         auto id_cinema = rooms[id_room].id_cinema;
         if (id_cinema == url_id_cinema) {
            auto filme = filmes[id_filme];
            result[index] = { 
               { "id_room", id_room },
               { "nome_filme", filme.nome },
               { "descricao_filme", filme.descricao }
            };
            index++;
         }
      }
      return result;
   });

   CROW_ROUTE(app, "/room")
   ([](const crow::request& req) 
   {
      auto id_room = stoi(req.url_params.get("id_room"));
      auto id_filme = room_filme[id_room].second;
      auto filme = filmes[id_filme];
      crow::mustache::context ctx({
         {"id_room", id_room },
         {"nome_filme", filme.nome }
      });
      return crow::mustache::load("room.html").render(ctx);
   });

   
    app.port(8888).multithreaded().run();
    return 0;
 }
#include <iostream>
#include <crow.h>
#include "models.cpp"
#include "relations.cpp"

using namespace std;
std::mutex mtx;

 int main (int argc, char *argv [])
 {
   crow::SimpleApp app;
   

   CROW_ROUTE(app, "/")
   ([]() {
      return crow::mustache::load("filmes.html").render();
   });
   CROW_ROUTE(app, "/api/filmes")
   ([]() {
      crow::json::wvalue result = {};
      for (auto item : filmes)
      {
         auto id_filmes = to_string(item.first);
         auto filme = item.second;
         result[id_filmes] = {
            { "nome", filme.nome },
            { "poster", filme.poster }
         };
      }
      
      return result;
   });
   
    CROW_ROUTE(app, "/cinemas")
    ([](const crow::request& req) 
    {
      auto id_filme = req.url_params.get("id_filme");
      auto filme = filmes[stoi(id_filme)];
      crow::mustache::context ctx({
         {"id_filme", id_filme },
         {"nome_filme", filme.nome },
         {"descricao_filme", filme.descricao },
         {"poster_filme", filme.poster }
      });
      return crow::mustache::load("cinemas.html").render(ctx);
   });
   CROW_ROUTE(app, "/api/cinemas")
   ([](const crow::request& req) {
      crow::json::wvalue result = {};
      auto url_id_filme = stoi(req.url_params.get("id_filme"));
      int index = 0;
      for (auto item : room_filme) {
         auto id_room = item.first;
         auto id_filme = item.second;
         auto id_cinema = rooms[id_room].id_cinema;
         if (id_filme == url_id_filme) {
            auto cinema = cinemas[id_cinema];
            result[index] = { 
               { "id_room", id_room },
               { "nome_cinema", cinema.nome },
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
      auto id_filme = 0;
      for(auto item : room_filme) {
         if (item.first == id_room) {
            id_filme = item.second;
            break;
         }
      }
      if (id_filme == 0) {
         return crow::response(404);
      }
      auto room = rooms[id_room];
      auto cinema = cinemas[room.id_cinema];
      auto filme = filmes[id_filme];
      crow::mustache::context ctx({
         {"id_room", id_room },
         {"nome_filme", filme.nome },
         {"poster_filme", filme.poster },
         {"nome_cinema", cinema.nome }
      });
      return crow::response(crow::mustache::load("room.html").render(ctx));
   });

   CROW_ROUTE(app, "/api/room")
   ([](const crow::request& req) {
      crow::json::wvalue result = {};
      auto url_id_room = stoi(req.url_params.get("id_room"));
      auto room = rooms[url_id_room];
      int index = 0;
      for (auto chair : room.chairs) {
         result[index] = chair;
         index++;
      }
      return result;
   });

   CROW_ROUTE(app, "/api/reserve-seat")
   ([](const crow::request& req) {
      crow::json::wvalue result = {};
      auto url_id_room = stoi(req.url_params.get("id_room"));
      auto url_chair_index = stoi(req.url_params.get("chair_index"));
      std::lock_guard<std::mutex> guard(mtx);
      auto room = rooms[url_id_room];
      room.chairs[url_chair_index] = true;
      rooms[url_id_room] = room;
      return 204;
   });
   
    app.port(8888).multithreaded().run();
    return 0;
 }
/*********************************************************************
 * @file  Controller.cpp
 * 
 * @brief Implementation of the class Controller.
 *********************************************************************/

#include "Controller.hpp"

void Controller::setupRoutes() 
{       
        /**
         * @brief Handles requests to the / endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
        
        CROW_ROUTE(app, "/")
        ([]() {
            return crow::mustache::load("filmes.html").render();
        });
        /**
         * @brief Handles requests to the /api/filmes endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
        
        CROW_ROUTE(app, "/api/filmes")
        ([&]() {
            crow::json::wvalue result = {};
            for (auto item : data.filmes) {
                auto id_filme = std::to_string(item.first);
                auto filme = item.second;
                result[id_filme] = {
                    { "nome", filme.nome },
                    { "poster", filme.poster }
                };
            }
            return result;
        });

       /**
         * @brief Handles requests to the /cinemas endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
        
        CROW_ROUTE(app, "/cinemas")
        ([&](const crow::request& req) {
            auto id_filme = req.url_params.get("id_filme");
            auto filme = data.filmes.at(std::stoi(id_filme));
            crow::mustache::context ctx({
                {"id_filme", id_filme },
                {"nome_filme", filme.nome },
                {"descricao_filme", filme.descricao },
                {"poster_filme", filme.poster }
            });
            return crow::mustache::load("cinemas.html").render(ctx);
        });

        /**
         * @brief Handles requests to the /api/cinemas endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
        
        CROW_ROUTE(app, "/api/cinemas")
        ([&](const crow::request& req) {
            crow::json::wvalue result = {};
            auto url_id_filme = std::stoi(req.url_params.get("id_filme"));
            int index = 0;
            for (auto item : data.room_filme) {
                auto id_room = item.first;
                auto id_filme = item.second;
                auto id_cinema = data.rooms.at(id_room).id_cinema;
                if (id_filme == url_id_filme) {
                    auto cinema = data.cinemas[id_cinema];
                    result[index] = { 
                        { "id_room", id_room },
                        { "nome_cinema", cinema.nome },
                    };
                    index++;
                }
            }
            return result;
        });
        
        /**
         * @brief Handles requests to the /room endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
       
        CROW_ROUTE(app, "/room")
        ([&](const crow::request& req) {
            auto id_room = std::stoi(req.url_params.get("id_room"));
            auto id_filme = 0;
            for(auto item : data.room_filme) {
                if (item.first == id_room) {
                    id_filme = item.second;
                    break;
                }
            }
            if (id_filme == 0) {
                return crow::response(404);
            }
            auto room = data.rooms[id_room];
            auto cinema = data.cinemas[room.id_cinema];
            auto filme = data.filmes[id_filme];
            crow::mustache::context ctx({
                {"id_room", id_room },
                {"nome_filme", filme.nome },
                {"poster_filme", filme.poster },
                {"nome_cinema", cinema.nome }
            });
            return crow::response(crow::mustache::load("room.html").render(ctx));
        });

        /**
         * @brief Handles requests to the /api/room endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
        
        CROW_ROUTE(app, "/api/room")
        ([&](const crow::request& req) {
            crow::json::wvalue result = {};
            auto url_id_room = std::stoi(req.url_params.get("id_room"));
            auto room = data.rooms[url_id_room];
            int index = 0;
            for (auto chair : room.chairs) {
                result[index] = chair;
                index++;
            }
            return result;
        });

        /**
         * @brief Handles requests to the /api/reserve-seat endpoint and constructs a JSON response with film data.
         *
         * @param req The request object (not used in this function)
         * @return A JSON object containing film data
        */
        
        CROW_ROUTE(app, "/api/reserve-seat")
        ([&](const crow::request& req) {
            crow::json::wvalue result = {};
            auto url_id_room = std::stoi(req.url_params.get("id_room"));
            auto url_chair_index = std::stoi(req.url_params.get("chair_index"));
            std::lock_guard<std::mutex> guard(mutex);
            auto room = data.rooms[url_id_room];
            room.chairs[url_chair_index] = true;
            data.rooms[url_id_room] = room;
            return 204;
        });

    /**
     * @brief Run the server.
    */
   
    app.port(8888).multithreaded().run();
}

/**
 * @file DataBuilder.cpp
 * @author Wagner Keller (wagner.keller@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <map>
#include "DataBuilder.hpp"

    DataBuilder::DataBuilder ()
    {
        this->cinemas = buildCinemas();
        this->filmes =  buildFilmes();
        this->rooms = buildRooms();
        this->room_filme = buildRoomFilme();
    }

    std::map<int, Cinema> DataBuilder::buildCinemas() 
    {
        std::map<int, Cinema> cinemas;
        cinemas.emplace(1, Cinema(1, "Cinemark"));
        cinemas.emplace(2, Cinema(2, "Grande Ecrã"));
        cinemas.emplace(3, Cinema(3, "Cine Santana"));
        return cinemas;
    }
    std::map<int, Filme> DataBuilder::buildFilmes()
    {
        std::map<int, Filme> filmes;
        filmes.emplace(1, Filme(1, "Avatar", "The films follow a U.S. Marine named Jake Sully (Sam Worthington) who becomes part of a program in which human colonizers explore and exploit an alien world called Pandora. The humans interact with a humanoid species called the Na'vi by inhabiting genetically engineered “avatar” bodies that resemble those of the Na'vi", "https://www.justwatch.com/images/poster/8730058/s166/avatar-2009"));
        filmes.emplace(2, Filme(2, "Um Morto Muito Louco", "Dois grandes amigos, Larry Wilson e Richard Parker, trabalham para Bernie Lomax em uma companhia de seguros. Ao fazer um trabalho extra no fim de semana, eles descobrem uma fraude de US$ 2 milhões. Na segunda vão até Lomax, que após ouvir a explicação deles demonstra uma enorme gratidão e os convida para ir até sua casa de praia, onde conversarão com mais calma sobre o assunto, que até lá deve ficar em total sigilo.", "https://images.justwatch.com/poster/250140739/s718/um-morto-muito-louco.%7Bformat%7D"));
        filmes.emplace(3, Filme(3, "Predator", "Dutch é contratado pelo governo dos Estados Unidos para resgatar políticos presos na Guatemala. Mas quando ele e sua equipe chegam na América Central, logo percebem que há algo errado. Depois de descobrir vários cadáveres, a equipe descobre que está sendo caçada por uma criatura brutal com força sobre-humana e uma capacidade surpreendente de se camuflar.", "https://images.justwatch.com/poster/295973376/s718/predator.%7Bformat%7D"));
     //   filmes.emplace(4, Filme(3, "JAVA", "Dutch é contratado pelo governo dos Estados Unidos para resgatar políticos presos na Guatemala. Mas quando ele e sua equipe chegam na América Central, logo percebem que há algo errado. Depois de descobrir vários cadáveres, a equipe descobre que está sendo caçada por uma criatura brutal com força sobre-humana e uma capacidade surpreendente de se camuflar.", "https://images.justwatch.com/poster/295973376/s718/predator.%7Bformat%7D"));
        return filmes;

    }
    std::map<int, Room> DataBuilder::buildRooms()
    {
        std::map<int, Room> rooms;
        rooms.emplace(100, Room(100, 1, size_room)); // Assuming cinema id 1 for room100
        rooms.emplace(101, Room(101, 1, size_room)); // Assuming cinema id 1 for room101
        rooms.emplace(102, Room(102, 1, size_room)); // Assuming cinema id 1 for room102
        rooms.emplace(200, Room(200, 2, size_room)); // Assuming cinema id 2 for room200
        rooms.emplace(201, Room(201, 2, size_room)); // Assuming cinema id 2 for room201
        rooms.emplace(300, Room(300, 3, size_room)); // Assuming cinema id 3 for room300
        return rooms;

    }
    std::vector<std::pair<int, int>> DataBuilder::buildRoomFilme()
    {
        return 
            {
                {100, 1}, // Room 100 playing Filme 1
                {101, 2}, // Room 101 playing Filme 2
                {102, 3}, // Room 102 playing Filme 3
                {200, 1}, // Room 200 playing Filme 1
                {201, 2}, // Room 201 playing Filme 2
                {300, 3}  // Room 300 playing Filme 3
            };
    }

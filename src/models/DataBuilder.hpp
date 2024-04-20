#pragma once
#include <map>
#include "Cinema.hpp"
#include "Filme.hpp"
#include "Room.hpp"

class DataBuilder 
{
private: 
    unsigned int size_room = 20;
public:
    DataBuilder();
    std::map<int, Cinema> buildCinemas(); 
    std::map<int, Filme> buildFilmes();
    std::map<int, Room> buildRooms();
    std::vector<std::pair<int, int>> buildRoomFilme();
    std::map<int, Cinema> cinemas;
    std::map<int, Filme> filmes;
    std::map<int, Room> rooms; 
    std::vector<std::pair<int, int>> room_filme; 
};
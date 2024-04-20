#pragma once
#include <vector>
/**
 * @brief 
 * 
 */
class Room 
{
   public: 
        Room() = default;
        Room(int id_r, int id_cinema, int size);
        int id_room;
        int id_cinema;
        std::vector<bool> chairs;
};
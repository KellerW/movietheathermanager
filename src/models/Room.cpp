#include "Room.hpp"
/**
 * @file Room.cpp
 * 
 * @brief Implements of the Room class.
 */

Room::Room(int id_r, int id_cinema, int size) 
{
    id_room = id_r;
    this->id_cinema = id_cinema;
    for (int i = 0; i < size; i++) 
    {
        chairs.emplace_back(false);
    }
}

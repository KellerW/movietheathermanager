#include "Room.hpp"
/**
 * @brief Construct a new Room:: Room object
 * 
 * @param id_r 
 * @param id_cinema 
 * @param size 
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

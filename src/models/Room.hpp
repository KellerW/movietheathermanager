/**
 * @file Room.hpp
 * 
 * @brief Declaration of the Room class.
 */
#pragma once
#include <vector>

class Room 
{
/**
 * @brief Represents a Room object.
 */
   public: 
   /**
     * @brief Constructs a new Room object with the given parameters.
     * 
     * @param id_r The ID of the room.
     * @param id_cinema The ID of the cinema to which the room belongs.
     * @param size The size of the room, representing the number of chairs.
     */
        Room() = default; /**< Default constructor. */
        Room(int id_r, int id_cinema, int size);
        int id_room; /**< The ID of the room. */
        int id_cinema; /**< The ID of the cinema to which the room belongs. */
        std::vector<bool> chairs; /**< A vector representing the chairs in the room, where true indicates a reserved 
                                   * chair and false indicates an available chair. */
};
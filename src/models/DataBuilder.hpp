/**
 * @file DataBuilder.hpp
 * 
 * @brief Implementation of the Builder design pattern.
 */
#pragma once
#include <map>
#include "Cinema.hpp"
#include "Filme.hpp"
#include "Room.hpp"

class DataBuilder 
{
private: 
    unsigned int size_room = 20; // Assuming a default room size
public:
    /**
     * @brief Construct a new DataBuilder object.
     */
    DataBuilder();
    /**
     * @brief Builds a map of cinemas.
     * 
     * @return A map containing cinemas, where the key is the cinema ID and the value is the Cinema object.
     */
    std::map<int, Cinema> buildCinemas(); 
     /**
     * @brief Builds a map of films.
     * 
     * @return A map containing films, where the key is the film ID and the value is the Filme object.
     */
    std::map<int, Filme> buildFilmes();
    /**
     * @brief Builds a map of rooms.
     * 
     * @return A map containing rooms, where the key is the room ID and the value is the Room object.
     */
    std::map<int, Room> buildRooms();
    /**
     * @brief Builds a vector of pairs representing the association between rooms and films.
     * 
     * @return A vector of pairs, where each pair represents a room-film association (room ID, film ID).
     */
    std::vector<std::pair<int, int>> buildRoomFilme(); 

    std::map<int, Cinema> cinemas; /**< Map containing cinemas. */
    std::map<int, Filme> filmes;    /**< Map containing films. */
    std::map<int, Room> rooms;  /**< Map containing rooms. */
    std::vector<std::pair<int, int>> room_filme; /**< Vector containing room-film associations. */
   
};
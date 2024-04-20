/**
 * @brief The Cinema class represents a cinema entity.
 * @file Cinema.hpp
 */

#pragma once 
#include <string>

class Cinema 
{
   public: 
    /**
     * @brief Default Construct a new Cinema object.
     */
    Cinema() = default;

    /**
     * @brief Construct a new Cinema object.
     * 
     * @param id The ID of the cinema.
     * @param nome The name of the cinema.
     */
    Cinema(int id, std::string nome);

    int id_cinema; /**< The ID of the cinema. */
    std::string nome; /**< The name of the cinema. */
};
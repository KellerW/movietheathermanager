/**
 * @brief Construct a new Cinema object
 * @file Cinema.cpp
 * @param id The ID of the cinema
 * @param nome The name of the cinema
 */
#include "Cinema.hpp"

Cinema::Cinema(int id, std::string nome) 
{
    id_cinema = id;
    this->nome = nome;
}

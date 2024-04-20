/**
 * @file Filme.hpp
 * 
 * @brief Declaration of the Filme class.
 */

#include "Filme.hpp"

/**
 * @brief Constructs a new Filme object with the given parameters.
 * 
 * @param id The ID of the film.
 * @param nome The name of the film.
 * @param descricao The description of the film.
 * @param poster The URL of the film's poster image.
 */

Filme::Filme(int id, std::string nome, std::string descricao, std::string poster) 
{
    id_filme = id;
    this->nome = nome;
    this->descricao = descricao;
    this->poster = poster;
}

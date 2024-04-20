#include "Filme.hpp"
/**
 * @brief Construct a new Filme:: Filme object
 * 
 * @param id 
 * @param nome 
 * @param descricao 
 * @param poster 
 */
Filme::Filme(int id, std::string nome, std::string descricao, std::string poster) 
{
    id_filme = id;
    this->nome = nome;
    this->descricao = descricao;
    this->poster = poster;
}

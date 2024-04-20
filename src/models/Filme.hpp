#pragma once
#include <string>
/**
 * @brief 
 * 
 */
class Filme 
{
   public: 
    Filme() = default;
    Filme(int id, std::string nome, std::string descricao, std::string poster);
    int id_filme;
    std::string nome;
    std::string descricao;
    std::string poster;
};
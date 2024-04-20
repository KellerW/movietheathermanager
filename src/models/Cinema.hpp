#pragma once 
#include <string>
/**
 * @brief 
 * 
 */
class Cinema 
{
   public: 
    Cinema() = default;
    Cinema(int id, std::string nome);
    int id_cinema;
    std::string nome;
};
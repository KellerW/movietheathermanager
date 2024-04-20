/**
 * @file Filme.hpp
 * 
 * @brief Declaration of the Filme class.
 */
#pragma once
#include <string>
/**
 * @brief Represents a Filme object.
 */
class Filme 
{
   public:
   /**
     * @brief Constructs a new Filme object with the given parameters.
     * 
     * @param id The ID of the film.
     * @param nome The name of the film.
     * @param descricao The description of the film.
     * @param poster The URL of the film's poster image.
     */ 
    Filme() = default;
    Filme(int id, std::string nome, std::string descricao, std::string poster);
    int id_filme; /**< The ID of the film. */
    std::string nome; /**< The name of the film. */
    std::string descricao; /**< The description of the film. */
    std::string poster; /**< The URL of the film's poster image. */
};
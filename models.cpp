#pragma once

using namespace std;

class Cinema {
   public: 
   Cinema() = default;
   Cinema(int id, string nome) {
      id_cinema = id;
      this->nome = nome;
   }
   int id_cinema;
   string nome;
};

class Filme {
   public: 
   Filme() = default;
   Filme(int id, string nome, string descricao, string poster) {
      id_filme = id;
      this->nome = nome;
      this->descricao = descricao;
      this->poster = poster;
   }
    int id_filme;
    string nome;
    string descricao;
    string poster;
};

class Room {
   public: 
   Room() = default;

   Room(int id_r, int id_cinema, int size) {
      id_room = id_r;
      this->id_cinema = id_cinema;
      for (int i = 0; i < size; i++) {
         chairs.emplace_back(false);
      }
   }
    int id_room;
    int id_cinema;
    vector<bool> chairs;
};
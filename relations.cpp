#pragma once

#include "models.cpp"

using namespace std;

auto cinema1 = Cinema(1, "Cinema 1");
auto cinema2 = Cinema(2, "Cinema 2");
auto cinema3 = Cinema(3, "Cinema 3");

map<int, Cinema> cinemas = {
   { cinema1.id_cinema, cinema1},
   { cinema2.id_cinema, cinema2},
   { cinema3.id_cinema, cinema3},
};

auto filme1 = Filme(1, "Filme 1", "Descrição Filme 1");
auto filme2 = Filme(2, "Filme 2", "Descrição Filme 2");
auto filme3 = Filme(3, "Filme 3", "Descrição Filme 3");
//cdca
map<int, Filme> filmes = {
   { filme1.id_filme, filme1 },
   { filme2.id_filme, filme2 },
   { filme3.id_filme, filme3 },
};

auto room100 = Room(100, cinema1.id_cinema, 20);
auto room101 = Room(101, cinema1.id_cinema, 20);
auto room200 = Room(200, cinema2.id_cinema, 20);

map<int, Room> rooms = {
   { room100.id_room, room100 },
   { room101.id_room, room101 },
   { room200.id_room, room200 },
};

vector<pair<int,int>> room_filme = {
   {room100.id_room, filme1.id_filme}, 
   {room101.id_room, filme3.id_filme}, 
   {room200.id_room, filme2.id_filme},
};
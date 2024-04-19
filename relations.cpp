#pragma once

#include "models.cpp"

using namespace std;

auto cinema1 = Cinema(1, "Cinemark");
auto cinema2 = Cinema(2, "Grande Ecrã");
auto cinema3 = Cinema(3, "Cine Santana");

map<int, Cinema> cinemas = {
   { cinema1.id_cinema, cinema1},
   { cinema2.id_cinema, cinema2},
   { cinema3.id_cinema, cinema3},
};

auto filme1 = Filme(1, "Avatar", "The films follow a U.S. Marine named Jake Sully (Sam Worthington) who becomes part of a program in which human colonizers explore and exploit an alien world called Pandora. The humans interact with a humanoid species called the Na'vi by inhabiting genetically engineered “avatar” bodies that resemble those of the Na'vi", "https://www.justwatch.com/images/poster/8730058/s166/avatar-2009");
auto filme2 = Filme(2, "Um Morto Muito Louco", "Dois grandes amigos, Larry Wilson e Richard Parker, trabalham para Bernie Lomax em uma companhia de seguros. Ao fazer um trabalho extra no fim de semana, eles descobrem uma fraude de US$ 2 milhões. Na segunda vão até Lomax, que após ouvir a explicação deles demonstra uma enorme gratidão e os convida para ir até sua casa de praia, onde conversarão com mais calma sobre o assunto, que até lá deve ficar em total sigilo.", "https://images.justwatch.com/poster/250140739/s718/um-morto-muito-louco.%7Bformat%7D");
auto filme3 = Filme(3, "Predator", "Dutch é contratado pelo governo dos Estados Unidos para resgatar políticos presos na Guatemala. Mas quando ele e sua equipe chegam na América Central, logo percebem que há algo errado. Depois de descobrir vários cadáveres, a equipe descobre que está sendo caçada por uma criatura brutal com força sobre-humana e uma capacidade surpreendente de se camuflar.", "https://images.justwatch.com/poster/295973376/s718/predator.%7Bformat%7D");

map<int, Filme> filmes = {
   { filme1.id_filme, filme1 },
   { filme2.id_filme, filme2 },
   { filme3.id_filme, filme3 },
};

auto room100 = Room(100, cinema1.id_cinema, 20);
auto room101 = Room(101, cinema1.id_cinema, 20);
auto room102 = Room(102, cinema1.id_cinema, 20);
auto room200 = Room(200, cinema2.id_cinema, 20);
auto room201 = Room(201, cinema2.id_cinema, 20);
auto room300 = Room(300, cinema3.id_cinema, 20);

map<int, Room> rooms = {
   { room100.id_room, room100 },
   { room101.id_room, room101 },
   { room102.id_room, room102 },

   { room200.id_room, room200 },
   { room201.id_room, room201 },

   { room300.id_room, room300 },
};

vector<pair<int,int>> room_filme = {
   {room100.id_room, filme1.id_filme}, 
   {room101.id_room, filme2.id_filme}, 
   {room102.id_room, filme3.id_filme},

   {room200.id_room, filme1.id_filme},
   {room201.id_room, filme2.id_filme},

   {room300.id_room, filme3.id_filme},
};


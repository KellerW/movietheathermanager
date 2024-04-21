#pragma once

#include <map>
#include "../src/models/DataBuilder.hpp"
#include "gmock/gmock.h"

class MockDataBuilder : public DataBuilder {
public:
    // Constructor to initialize mock data
    MockDataBuilder() {
        // Initialize mock data
        this->cinemas = this->buildCinemas();
        this->filmes = this->buildFilmes();
        this->rooms = this->buildRooms();
        this->room_filme = this->buildRoomFilme();
    }

private:
    // Override the buildCinemas method to return mock cinema data
    std::map<int, Cinema> buildCinemas() override {
        std::map<int, Cinema> cinemas;
        cinemas.emplace(1, Cinema(1, "MockCinema1"));
        cinemas.emplace(2, Cinema(2, "MockCinema2"));
        return cinemas;
    }
    // Override the buildFilmes method to return mock film data
    std::map<int, Filme> buildFilmes() override {
        std::map<int, Filme> filmes;
        filmes.emplace(1, Filme(1, "MockFilm1", "Description1", "PosterURL1"));
        filmes.emplace(2, Filme(2, "MockFilm2", "Description2", "PosterURL2"));
        return filmes;
    }

    // Override the buildRooms method to return mock room data
    std::map<int, Room> buildRooms() override {
        std::map<int, Room> rooms;
        rooms.emplace(100, Room(100, 1, 50)); // Assuming cinema id 1 for room100
        rooms.emplace(101, Room(101, 1, 50)); // Assuming cinema id 1 for room101
        return rooms;
    }

    // Override the buildRoomFilme method to return mock room-film associations
    std::vector<std::pair<int, int>> buildRoomFilme() override {
        return {
            {100, 1}, // Room 100 playing Filme 1
            {101, 2}, // Room 101 playing Filme 2
        };
    }
};

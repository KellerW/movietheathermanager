#include <gtest/gtest.h>
#include "../src/models/DataBuilder.hpp"

// Test fixture for DataBuilder class
class DataBuilderTest : public ::testing::Test {
protected:
    DataBuilder dataBuilder;
};

// Test case to check the size of cinemas map
TEST_F(DataBuilderTest, CinemasSize) {
    ASSERT_EQ(dataBuilder.cinemas.size(), 3); // Expected 3 cinemas
}

// Test case to check the size of filmes map
TEST_F(DataBuilderTest, FilmesSize) {
    ASSERT_EQ(dataBuilder.filmes.size(), 3); // Expected 3 filmes
}

// Test case to check the size of rooms map
TEST_F(DataBuilderTest, RoomsSize) {
    ASSERT_EQ(dataBuilder.rooms.size(), 6); // Expected 6 rooms
}

// Test case to check the size of room_filme vector
TEST_F(DataBuilderTest, RoomFilmeSize) {
    ASSERT_EQ(dataBuilder.room_filme.size(), 6); // Expected 6 room-filme associations
}
cmake_minimum_required(VERSION 3.10)
project(MyProjectTests)

# Locate GTest package
find_package(GTest REQUIRED)

# Include directories for the project
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

# Add the source files for the models
set(MODEL_SOURCES 
${CMAKE_SOURCE_DIR}/src/models/DataBuilder.cpp ${CMAKE_SOURCE_DIR}/src/models/DataBuilder.hpp
${CMAKE_SOURCE_DIR}/src/models/Cinema.cpp ${CMAKE_SOURCE_DIR}/src/models/Cinema.hpp 
${CMAKE_SOURCE_DIR}/src/models/Filme.cpp ${CMAKE_SOURCE_DIR}/src/models/Filme.hpp
${CMAKE_SOURCE_DIR}/src/models/Room.cpp ${CMAKE_SOURCE_DIR}/src/models/Room.hpp)

# Create a target for the model tests
add_executable(ModelTests ../tests/ModelTest.cpp ${MODEL_SOURCES})

# Link ModelTests with GTest and pthread library
target_link_libraries(ModelTests GTest::GTest GTest::Main pthread)

# Add the test to CTest
enable_testing()
add_test(NAME ModelTests COMMAND ModelTests)
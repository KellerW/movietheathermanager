cmake_minimum_required(VERSION 3.6)
project(MovieManager VERSION 0.1.0 LANGUAGES C CXX)
find_package(PkgConfig)
find_package(Crow)
#include(CTest)
#enable_testing()


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Crow::Crow)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
file(COPY templates DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND cp -rf
   ${CMAKE_SOURCE_DIR}/templates/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/templates/)

#include(CPack)


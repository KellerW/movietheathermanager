cmake_minimum_required(VERSION 3.22)
project(MovieManager VERSION 0.1.0 LANGUAGES C CXX)

set(EXECUTABLE_NAME MovieManager)

set(LIBRARY_MODELS Models)
set(LIBRARY_BUILDER Builder)
set(LIBRARY_CONTROLLER Controller)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(Crow REQUIRED)
find_package(GTest CONFIG REQUIRED)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Crow::Crow ${LIBRARY_MODELS} ${LIBRARY_CONTROLLER})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})



file(COPY templates DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND cp -rf
   ${CMAKE_SOURCE_DIR}/templates/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/templates/)
   
add_subdirectory(src)



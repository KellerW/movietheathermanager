set(LIBRARY_SOURCES "Cinema.cpp" "Filme.cpp" "Room.cpp" "DataBuilder.cpp")
set(LIBRARY_HEADERS "Cinema.hpp" "Filme.hpp" "Room.hpp" "DataBuilder.hpp")

add_library(${LIBRARY_MODELS} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})
    target_include_directories(${LIBRARY_MODELS} PUBLIC "./")
   
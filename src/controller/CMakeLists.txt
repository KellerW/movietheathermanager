set(LIBRARY_SOURCES "Controller.cpp")
set(LIBRARY_HEADERS "Controller.hpp")

add_library(${LIBRARY_CONTROLLER} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})
    target_include_directories(${LIBRARY_CONTROLLER} PUBLIC "./")
   

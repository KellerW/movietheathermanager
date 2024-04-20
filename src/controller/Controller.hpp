#include <crow.h>
#include <map>
#include <string>
#include "../models/DataBuilder.hpp"


class Controller 
{
    private:
        DataBuilder data;
        crow::SimpleApp app;
        std::mutex mutex;
    public:
        Controller() 
    {
        setupRoutes();
    }

    void setupRoutes(); 
};
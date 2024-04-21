/***********************************************************************
 * @file  Controller.hpp
 *
 * @brief Controller class for managing routes and handling requests.
 **********************************************************************/
#include "crow.h"
#include <map>
#include <string>
#include "../models/DataBuilder.hpp"
class Controller 
{
    private:
        DataBuilder data; /**< Instance of DataBuilder for accessing data. */
        crow::SimpleApp app; /**< Instance of SimpleApp for managing routes. */
        std::mutex mutex; /**< Mutex for ensuring thread safety. */
      
    public:
    /**
     * @brief Default constructor for creating a new Controller object.
    */
    Controller() 
    {
        setupRoutes();
    }
    /**
     * @brief Set up routes and manage requests.
    */
    void setupRoutes(); 
};
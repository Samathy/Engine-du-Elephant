/************************************
map class.
*************************************/
#ifndef MAP_HEADER_H
#define MAP_HEADER_H

#include <boost/thread/mutex.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "entity_header.h"

class map
{
    boost::mutex entityMap_mtx;
    boost::mutex boolMap_mtx;

    public:
        map(int, int, std::string); //constructer, load the map.
        base_entity* entityStack[200]; //array of entity pointers.
        int return_number_of_entities(); //returns all the entities currently initialised.
        void destroy_map();
    private:
        std::string lines[512]; //string array to hold the contents of our map file.
        std::string mapName; //string for the name of our current map to go into.
        bool read_map_file(int, int, std::string); //read the map file.
        void entity_init(int); //func to initialise all the members.
        int currentEntities; //int storing the amount of initialised entities. (includes entities that re invisible etc)
        
};

#endif


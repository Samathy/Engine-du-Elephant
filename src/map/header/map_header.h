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
#include "all_entities.h"

class map
{
    boost::mutex entityMap_mtx;
    boost::mutex boolMap_mtx;
    boost::mutex returnEntitiesmtx;

    public:
        map(int, int, std::string, lua_State* ); //constructer, load the map.
base_entity* entityStack[200]; //array of entity pointers.
        int return_number_of_entities(); //returns all the entities currently initialised.
        void destroy_map();
    private:
        int mem_amount; //the amount of memory allocated for entities.
        int no_entities; //the number of entities found to be defined in the map file.
        std::string lines[512]; //string array to hold the contents of our map file.
        std::string mapName; //string for the name of our current map to go into.
        bool read_map_file(int, int, std::string); //read the map file.
        void entity_init(int); //func to initialise all the members.
        int currentEntities; //int storing the amount of initialised entities. (includes entities that re invisible etc)
        
};

#endif



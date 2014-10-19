/**************************************************
map.cpp contains stuff for the map class.
***************************************************/
#include "all_header.h"
#include "map_header.h"
#include "all_entities.h"

//class map
//{
//    boost::mutex entityMap_mtx;
//    boost::mutex boolMap_mtx;

//    public:
//        map(int, int, std::string); //constructer, load the map.
//        base_entity* entityMap[16][9]; //array of entity pointers.
//        bool boolMap[16][9]; //array of bools
//        int return_number_of_entities(); //returns all the entities currently initialised.
//    private:
//        std::string lines[512]; //string array to hold the contents of our map file.
//        std::string mapName; //string for the name of our current map to go into.
//        bool read_map_file(int, int, std::string); //read the map file.
//        void entity_init(int); //func to initialise all the members.
//        void object_factory(int, int, std::string, std::string); //function which creates all the entities.
//        int pixPerElement_w; //stores the pixels per grid element width.
//        int pixPerElement_h; //stores the pixels per grid element height.
//        int currentEntities; //int storing the amount of initialised entities. (includes entities that re invisible etc)
//};

char* get_entity_script_path(lua_state* L, const char* key, int table_size)
{
    const char* result;
    lua_pushstring(L, key);
    lua_gettable(L, -2);
    if (!lua_isnumber(L,-1))
        {
            std::cout << "Error, Item isnt valid table.";
        }
     result = lua_tostring(L, -1);
     lua_pop(L, 1);

    return result;
}

int map::return_number_of_entities() //returns the current amount of instantiated entities.
{
    returnEntitiesmtx.lock(); //lock mutex
    int number = currentEntities; //tem variable with amount of entities.
    returnEntitiesmtx.unlock(); //unlock.
    return number; //ret
    
}

void map::destroy_map() //destroy all humans (by that i mean entity objects;-)
{

            for (int i = 0; i>map::return_number_of_entities(); ++i) //loop for however many 
            {
                delete entityStack[i]; //delete entities entities.
            }

return;

}

void map::entity_init(int i)
{

    
    return;

}


bool map::read_map_file (int width, int height, std::string filename, lua_State* L )
{

    luaL_loadfile(L, filename) || lua_pcall(L, 0,0,0);
    lua_getglobal(L, "name"); //get the map name
    const char* mapname = lua_tostring(L, -1);
    int table_size = lua_getglobal(L, "tbl_size");
    lua_getglobal(L, "entitiesT"); //get the table containing entity scripts.
    get_entity_path(L,"key", lua_tostring(L, -2)); 
}    

return true;

}

map::map (int width, int height, std::string fileName , lua_State* L)
{
	std::cout << "started map reading object\n\n";
    map::currentEntities = 0;
    map::read_map_file(width, height, fileName, L);
	std::cout << "Map initialised\n";
    return;
}


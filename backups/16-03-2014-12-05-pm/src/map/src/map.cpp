/**************************************************
map.cpp contains stuff for the map class.
***************************************************/
#include "all_header.h"
#include "map_header.h"

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


int map::return_number_of_entities()
{

    return map::currentEntities;

}

void map::destroy_map() //destroy all humans (by that i mean entity objects;-)
{

            for (int i = 0; i>map::return_number_of_entities(); ++i) //loop for however many 
            {
                //delete entityStack[i]; //delete entities entities.
            }

return;

}

void map::entity_init(int i)
{
    unsigned strPos; 
    std::string cmpEndDec("%");
    std::string cmpEndSet("#");
    std::string objectName;
    GLfloat Xf;
    GLfloat Yf;

    int colourR; //colours.
    int colourG;
    int colourB;
    int colourA;
//    
//    if (i >= 400)
//    {
//        std::cout <<"i = > 400 >.< \n I= " << i <<" \n";
//        std::terminate();
//    }
    
    //std::cout <<  "lines = " << lines[i] << " on line 41\n\n";
    //std::cout << "i = "<< i <<" on line 42 of map.cpp\n\n";
    

    strPos = map::lines[i].find("#"); //try and find a # to show end of file.
    //std::cout << "strPos == " << strPos << " on line 45\n\n";
    if (strPos == std::string::npos || strPos == 0 || strPos < 0)
    {
        std::cout << "Found end of file.\n\n";
        return;
    }
    
        //i=i+1;
    //std::cout << "At line 42, map::lines["<<i<<"]" << "\n\n";
    
    //std::cout <<  "at line 44, i = " << i << "\n\n";
    
    objectName = map::lines[i]; //assign objectName the next line in the map file.
    i= i+1;
    //std::cout << "objectName = " << objectName << "\n\n";
    //std::cout << "i = " << i << "\n\n";
    Xf = atof(map::lines[i].c_str()); //get the GL coords of the entity
    i = i+1;
    Yf = atof(map::lines[i].c_str());
    i = i+1;
    //std::cout << "i = " << i << "\n\n\n";

    std::cout << "Initialising entity with the following params:" << " at X= " << Xf << " Y= " << Yf <<"\n"; //initialise enities.
    
    std::cout << "Current entity number " << map::currentEntities << "\n\n";
    int entitys = map::currentEntities;
    map::entityStack[entitys] = new base_entity (Xf, Yf); //initialise a new entity on the entity stack at element
    std::cout << "Object created\n\n";
    
    
    map::currentEntities = map::currentEntities + 1; //increment the amount of entities
    
    
    std::cout << "Current entities incremented. \nNow current entity count is: " << map::currentEntities << "\n\n";
    

    strPos = map::lines[i].find("%"); //try and find % to show end of params
    if (strPos != std::string::npos)
    {
        i = i+1;
        std::cout << "Returning and reading next area\n\n";
        //return;
        map::entity_init(i);
    }
    
        strPos = map::lines[i].find("#"); //try and find a # to show end of file.
    if (strPos == std::string::npos || strPos == 0 || strPos < 0)
    {
        std::cout << "Found end of file.\n\n";
        return;
    }
    
    if (strPos >= std::string::npos)
    {
    std::cout << "Map file missing closing % on line " << i << " \nIgnoring that for now, but that might change in the future.\n\n";
    i = i+1;
    std::cout << "returning and reading next area\n\n";
    map::entity_init(i);
    }
    
    if (i >= 25) //if looped more than 25 times there probable an error, so return.
    {
        std::cout <<"i = > 20 >.< \n I= " << i <<" \n";
        return;
    }
    
    return;

}


bool map::read_map_file (int width, int height, std::string filename)
{
    unsigned strPos; //temp for the result of tring operations like .find().
    int i = 0;

    std::ifstream map_file (filename.c_str());// open file.

    

        if (!map_file)
        {
        // Check the stream is in a good state,
        // which here pretty much just means open
        std::cout<< "Cant open map file. Common cause is not having admin privilages.\n";
        return false;
        }

        std::cout << "Opening map file....\n\n";
        std::cout << "Map file contents: \n";

        std::string line;
        
        while (std::getline(map_file, line))
        // read and immediately check it worked.
        {
            //std::cout << line << '\n';
            map::lines[i] = line;
            std::cout << "lines["<<i<<"] = " << map::lines[i] << "\n";
            i= i+1;
        }
        
    if (map::lines[0].empty() == true) //if the string is empty then either the map file is corrupt or something went wrong.
    {
        std::cout << "Empty\n";
        return false;
    }




    std::string cmp ("Name"); //var with comparason strings in.

    std::size_t found = map::lines[0].find(cmp);
    
    if (found != std::string::npos)
    {
        cmp.assign ("=");
        strPos = map::lines[0].rfind(cmp); // find the last instance of = in the string.
        std::string tmp = map::lines[0].substr(5); //create a new string starting at = to end of string.
        std::cout << "\n" << tmp << " <--Tempory string\n";
        //tmp.erase (0,1); //erase the = symbol
        
        map::mapName.assign(tmp);

        std::cout << "\n\nEventual map name = " << mapName << "\n";
    }
    std::cout <<"\n Now to read the next declaration\n\n";
    //std::cout << lines[2];




    if (map::lines[1].empty() == true) //check if the line[1] is empty.
    {
        std::cout << "Empty\n";
        return 0; //return if its empty
    }

    cmp.assign ("%");
    strPos = map::lines[1].find(cmp);
    
    if (strPos != std::string::npos)
    {
        std::cout << "Found entity declarations start\n\n";
        std::cout << map::lines[2]<< "\n";
        map::entity_init(2); //go to init entities.
        return true;
    }
    else
    {
    return false;
    }

    std::cout << map::lines[1];

return true;

}

map::map (int width, int height, std::string fileName)
{
    
//        for (int i=0; i<200; i++) //for loop 16 times.
//        {            
//                    map::entityStack[i] = NULL ; //and make sure that the entity map's pointers are all null.
//        }
    map::currentEntities = 0;
    map::read_map_file(width, height, fileName);
    return;
}


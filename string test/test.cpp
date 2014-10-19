#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>


std::string lines[512];

void entity_init(int i)
{
    unsigned strPos; 
    std::string cmp("%");
    std::string objectName;
    int X;
    int Y;

    std::cout << lines[i] < "\n\n";
    
    std::cout << "i = " << i << "\n\n";
    
    objectName = lines[i]; //assign objectName the next line in the map file.
    i= i+1;
    std::cout << "objectName = " << objectName << "\n\n";
    std::cout << "i = " << i << "\n\n";
    X = atoi(lines[i].c_str()); //get the next line as X co-ord.
    i = i+1;
    std::cout << "i = " << i << "\n\n";
    Y = atoi(lines[i].c_str()); //get next line as Y co-ord.
    i = i+1;
    std::cout << "i = " << i << "\n\n\n";
    std::cout << "Initialising entity with the following params: Name= "<< objectName << " at X= " << X << " Y= " << Y <<"\n"; //initialise enities.
    
    strPos = lines[i].find(cmp); //try and find % to show end of params
    if (strPos != std::string::npos)
    {
        i = i+1;
        std::cout << "Returning and reading next area\n\n";
        return;
        //entity_init(i);
    }
    if (strPos == std::string::npos)
    {
    std::cout << "Map file missing closing % on line " << i << " \nIgnoring that for now, but that might change in the future.\n\n";
    i = i+1;
    std::cout << "returning and reading next area\n\n";
    //entity_init(i);
    }
    return;

}

int main( int argc, char* argv[])
{
    int i =  0; //count integer
    std::string line; //temp string for the lines read from the text file.
   // std::string lines[144];
    std::string mapName;
    unsigned strPos;

    std::ifstream map_file ("file.txt"); // open file.



        if (!map_file)
        {
        // Check the stream is in a good state,
        // which here pretty much just means open
        std::cout<< "Cant open map file. Common cause is not having admin privilages.\n";
        return 0;
        }

        std::cout << "Opening map file....\n\n";
        std::cout << "Map file contents: \n";

        while (std::getline(map_file, line))
        // read and immediately check it worked.
        {
            //std::cout << line << '\n';
            lines[i] = line;
            std::cout << "lines["<<i<<"] = " << lines[i] << "\n";
            i= i+1;
        }
        
    if (lines[0].empty() == true) //if the string is empty then either the map file is corrupt or something went wrong.
    {
        std::cout << "Empty\n";
        return 0;
    }


    

    std::string cmp ("Name"); //var with comparason strings in.

    std::size_t found = lines[0].find(cmp);
    
    if (found != std::string::npos)
    {
        cmp.assign ("=");
        strPos = lines[0].rfind(cmp); // find the last instance of = in the string.
        std::string tmp = lines[0].substr(5); //create a new string starting at = to end of string.
        std::cout << "\n" << tmp << " <--Tempory string\n";
        //tmp.erase (0,1); //erase the = symbol
        
        mapName.assign(tmp);

        std::cout << "\n\nEventual map name = " << mapName << "\n";
    }
    std::cout <<"\n Now to read the next declaration\n\n";
    //std::cout << lines[2];




    if (lines[1].empty() == true) //check if the line[1] is empty.
    {
        std::cout << "Empty\n";
        return 0; //return if its empty
    }

    cmp.assign ("%");
    strPos = lines[1].find(cmp);
    
    if (strPos != std::string::npos)
    {
        std::cout << "Found entity declarations start\n\n";
        std::cout << lines[2];
        entity_init(3); //go to init entities.
        //return 0;
    }
    else
    {
    return 0;
    }

    std::cout << lines[1];

return 1;

}


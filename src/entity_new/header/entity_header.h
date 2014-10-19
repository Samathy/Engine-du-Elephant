/*************************************************
 * Entity class declaration
 * ***********************************************/

#ifndef ENTITY_H
#define ENTITY_H

#include "all_header.h"

class map

class entity
{
    
    boost::mutex locationXmtx;
    boost::mutex locationYmtx;
    boost::mutex colourmtx;

    public:
        entity::entity(const char*); //constructor, takes file name of the init script for the entity.
        virtual void do_logic(); //logic function
        virtual void render(); //render function
        virtual void handle_collision(int, int); //collision handlers
        virtual void handle_keys(int, map*); //keyboard input handler.
        virtual void return_solid(); //return solid.
        virtual GLfloat return_locationX(); //return locations.
        virtual GLfloat return_locationY();

    private:
        void* stackBP; //pointer to a malloced "stack" for data relating to the entity (Base pointer)
        void* stackSP; //Stack pointer for malloced stack. points to the top of the stack

        lua_State* L; //pointer to Lua state
        bool solid; //solid state of the entity.
        GLfloat colour4f[4]; //colour data
        GLfloat colour[3];
        GLfloat locationX; //location data
        GLfloat locationY;
};

#endif



        

/*************************************************
 * Entity class declaration
 * ***********************************************/

#ifndef ENTITY_H
#define ENTITY_H

#include "SDLheaders.h"
#include "all_header.h"

class map

class entity
{
    
    boost::mutex locationXmtx;
    boost::mutex locationYmtx;
    boost::mutex colourmtx;

    public:
        virtual void do_logic();
        virtual void render();
        virtual void handle_collision(int, int);
        virtual void handle_keys(int, map*);
        virtual void return_solid();
        virtual GLfloat reutnr_locationX();
        virtual GLfloat return_locationY();

    private:
        bool solid;
        GLfloat colour4f[4];
        GLfloat colour[3];
        GLfloat locationX;
        GLfloat locationY;
};

#endif



        

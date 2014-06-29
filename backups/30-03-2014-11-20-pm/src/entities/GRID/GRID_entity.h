/**************************
GRID entity class.
*****************************/

#ifndef GRID_HEADER_HPP
#define GRID_HEADER_HPP

#include "all_header.h"


class map;


class GRID: public base_entity
{
    boost::mutex locationXmtx;
    boost::mutex locationYmtx;
    boost::mutex colourmtx;
    
    public:
        GRID (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        virtual void render(); //renders current object
        virtual GLfloat return_locationX(); //return the X and Y of the current entity.
        virtual GLfloat return_locationY();
        virtual bool return_solid();
    private:
        bool solid; //tru if entity is collidable/solid, false if things can go through this entity. default to solid(true).
        GLfloat colour4f[4]; //array of four bytes for storing object's colours;Red,Green, Blue and Alpha.
        GLfloat colour3f[3]; //array of three bytes for storing object's colours;Red,Green and blue.
        GLfloat locationX; //the X and Y coords of the entity.
        GLfloat locationY;

};



#endif


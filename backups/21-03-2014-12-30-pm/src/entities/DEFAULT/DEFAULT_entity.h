/******************************
Default entity
*******************************/

#ifndef DEFAULT_HEADER_HPP
#define DEFAULT_HEADER_HPP

#include "all_header.h"


class map;


class DEFAULT: public base_entity
{
    boost::mutex locationXmtx;
    boost::mutex locationYmtx;
    boost::mutex colourmtx;
    
    public:
        DEFAULT (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        virtual void render(); //renders current object.
        virtual void handle_collision(int, int); //collision handler, takes ints to show what direction something hit it at.
        virtual void handle_keys(int, map*); //key handling function. Every object has one, this way we can make multiple entities act as one player.
        virtual void do_logic(); //function for doing entity logic.
        virtual GLfloat return_locationX(); //return the X and Y of the current entity.
        virtual GLfloat return_locationY();
    private:
        bool solid; //true if entity is collidable/solid, false if things can go through this entity. default to solid(true).
        GLfloat colour4f[4]; //array of four bytes for storing object's colours;Red,Green, Blue and Alpha.
        GLfloat colour3f[3]; //array of three bytes for storing object's colours;Red,Green and blue.
        GLfloat locationX; //the X and Y coords of the entity.
        GLfloat locationY;


};


#endif



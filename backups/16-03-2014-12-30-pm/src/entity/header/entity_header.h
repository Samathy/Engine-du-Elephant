/*****************************************
Entity class declaration. describes the master entity class.
******************************************/
#ifndef ENTITY_HEADER_H
#define ENTITY_HEADER_H

#include <stdint.h>
#include "SDLheaders.h"

class base_entity
{
    public:
        //base_entity (int, int, int, std::string,int, int); //constructer, takes two ints as positions, an int as the colour (TODO work out how to hold three values in one int.) and a string as the type.   
        base_entity (GLfloat,GLfloat); //constructer that doesnt take colours. (for testing)
        void do_logic(int); //function to run this entities logic. takes an int as the current tick in order to calculate how much time it needs to do something.
        void render(SDL_Window*); //renders current object.
        void handle_collision(int, int); //collision handler, takes ints to show what direction something hit it at.
        void handle_keys(char); //key handling function. Every object has one, this way we can make multiple entities act as one player.
        bool return_solid(); //returns if the entity is solid or transparent.
        GLint return_locationX(); //returns the entities X co-ordinate. used in collsion checking.
        GLint return_locationY();
    private:
        bool solid; //tru if entity is collidable/solid, false if things can go through this entity. default to solid(true).
        GLint colour4i[4]; //array of four bytes for storing object's colours;Red,Green, Blue and Alpha.
        GLint colour3i[3]; //array of three bytes for storing object's colours;Red,Green and blue.
        GLfloat locationX; //the X and Y coords of the entity.
        GLfloat locationY;
        void calculate_colours(int); //calculates the colours.
};

#endif

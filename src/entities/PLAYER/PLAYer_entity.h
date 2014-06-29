/*************************
vlass declaration for player entity.
*****************************/



#include "all_header.h"

class map;

class PLAYER: public base_entity
{

    boost::mutex locationXmtx;
    boost::mutex locationYmtx;
    boost::mutex colourmtx;

     public:
        PLAYER (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        virtual void render(); //renders current object.
        virtual void handle_collision(int, int); //collision handler, takes ints to show what direction something hit it at.
        virtual void handle_keys(int, map*); //key handling function. Every object has one, this way we can make multiple entities act as one player.
        virtual void do_logic(); //function for doing entity logic.
        virtual GLfloat return_locationX(); //return the X and Y of the current entity.
        virtual GLfloat return_locationY();
        virtual bool return_solid();
    private:
        GLfloat colour4f[4]; //array of four bytes for storing object's colours;Red,Green, Blue and Alpha.
        GLfloat colour3f[3]; //array of three bytes for storing object's colours;Red,Green and blue.
        GLfloat locationX; //the X and Y coords of the entity.
        GLfloat locationY;
        bool logicState; //used to track what state the entity is in.

};

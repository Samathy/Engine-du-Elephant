/*****************************
entity class. contains the master entity class. This class can be uysed as a basic entity, but it is advised to just use it as a class to inherit from.
******************************/

//class base_entity
//{
//    public:
//        base_entity (int, int, int, std::string); //constructer, takes two ints as positions, an int as the colour (TODO work out how to hold three values in one int.) and a string as the type.   
//        base_entity (int, int, std::string); //constructer that doesnt take colours. (for testing)
//        void do_logic(int); //function to run this entities logic. takes an int as the current tick in order to calculate how much time it needs to do something.
//        void render(); //renders current object.
//        void handle_collision(int, int); //collision handler, takes ints to show what direction something hit it at.
//        void handle_keys(char); //key handling function. Every object has one, this way we can make multiple entities act as one player.
//        private:
//        GLint colour4i[4]; //array of four bytes for storing object's colours;Red,Green, Blue and Alpha.
//        GLint colour3i[3]; //array of three bytes for storing object's colours;Red,Green and blue.
//        int location[1][1]; //array of two ints containing the objects current location.
//};

#include "all_header.h"


GLfloat base_entity::return_locationX()
{
return 0.0f;
}

GLfloat base_entity::return_locationY()
{
return 0.0f;
}

void base_entity::handle_keys(int key, map*)
{
    return;
}

bool base_entity::return_solid()
    {
        return false;
    }

void base_entity::do_logic() //does all the logic for the entity.
    {

        return;
    }
    
void base_entity::handle_collision(int hitX, int hitY) //handles collisions.
{
 //nothing to do here!
}

void base_entity::render() //by default this renders a red cube.
    {
        return;
    }


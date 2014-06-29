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
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat base_entity::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;


}
void base_entity::handle_keys(int key, map*)
{
    return;
}

bool base_entity::return_solid()
    {
        return base_entity::solid;
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
        std::cout << "Called base entity render.\n\n";
        
        GLfloat pointTL[2] = {(base_entity::locationX), (base_entity::locationY + 0.0f)};
        GLfloat pointTR[2] = {(base_entity::locationX + 0.1f), (base_entity::locationY)};
        GLfloat pointBR[2] = {(base_entity::locationX + 0.1f), (base_entity::locationY - 0.1f)};
        GLfloat pointBL[2] = {(base_entity::locationX), (base_entity::locationY - 0.1f)};
    
        
        
                
        glLoadIdentity(); //load ID
        //glTranslatef(180, 15,0); //translate to topleft 
        glBegin(GL_QUADS); //draw quad.
            glColor3f(1.f,0.f, 0.f);
            glVertex2f(pointTL[0],pointTL[1]);
            glVertex2f( pointTR[0],pointTR[1]);
            glVertex2f(pointBR[0],pointBR[1]);
            glVertex2f(pointBL[0],pointBL[1]);
        glEnd(); //end


//        
        return;
    }

//base_entity::base_entity (GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
//{
//    std::cout << "new base entity created!\n\n";

//    std::cout << "X = " << x << "\nY = " << y << "\n\n";
//    locationX = x; //add the x and y to this entity.
//  locationY = y; 
//    std::cout << "location: " << locationX << "  " << locationY << "\n\n";
//    colour4f[0] = R; //assign colours.
//    colour4f[1] = G;
//    colour4f[2] = B;
//    colour4f[3] = A;
//    
//    //base_entity::solid = true; //default as solid.
//     //we dont have colours for this one.
//    return;
//}
   
   


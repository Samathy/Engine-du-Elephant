/**********************
SQUARE entity class members.

***********************/

#include "all_entities.h"
#include "all_header.h"


GLfloat SQUARE::return_locationX()
{
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat SQUARE::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;

}

bool SQUARE::return_solid()
{
    solidmtx.lock();
    bool tmp = this->solid;
    solidmtx.unlock();
    return tmp;

}

void SQUARE::render()
{
        GLfloat pointTL[2] = {(SQUARE::locationX), (SQUARE::locationY + 0.0f)};
        GLfloat pointTR[2] = {(SQUARE::locationX + 0.1f), (SQUARE::locationY)};
        GLfloat pointBR[2] = {(SQUARE::locationX + 0.1f), (SQUARE::locationY - 0.1f)};
        GLfloat pointBL[2] = {(SQUARE::locationX), (SQUARE::locationY - 0.1f)};
        
        //std::cout << "colours: " << colour4f[0] << " " << colour4f[1] << " " << colour4f[2] << " " << colour4f[3] << "\n";
        
        
                
        glLoadIdentity(); //load ID
        glBegin(GL_QUADS); //draw quad.
            glColor3f(1.0f,0.0f,0.0f);
            //glColor3f(SQUARE::colour4f[0],SQUARE::colour4f[1],SQUARE::colour4f[2]);
            glColor4f(SQUARE::colour4f[0],SQUARE::colour4f[1],SQUARE::colour4f[2],SQUARE::colour4f[3]);
            glVertex2f(pointTL[0],pointTL[1]);
            glVertex2f(pointTR[0],pointTR[1]);
            glVertex2f(pointBR[0],pointBR[1]);
            glVertex2f(pointBL[0],pointBL[1]);
        glEnd();

return;

}


void SQUARE::handle_keys(int key, map* ptrmap)
{
    return;
}

void SQUARE::handle_collision(int x, int y)
{
    return;
}

void SQUARE::do_logic()
{
//    if (SQUARE::logicState == true)
//    {
//    colourmtx.lock(); //lock colour mutex.
//    this->colour4f[2] = 1.0f; //change colour.
//    this->colour4f[1] = 1.0f;
//    this->colour4f[0] = 1.0f;
//    SDL_Delay (5);
//    colourmtx.unlock(); //unlock mutex.
//    SQUARE::logicState = false;
//    return;
//    }
//    else if (SQUARE::logicState == false)
//    {
//    colourmtx.lock(); //lock colour mutex.
//    this->colour4f[2] = 0.0f; //change colour.
//    this->colour4f[1] = 1.0f;
//    this->colour4f[0] = 1.0f;
//    SDL_Delay (10);
//    colourmtx.unlock(); //unlock mutex.
//    SQUARE::logicState = true;
//    return;
//    }
//    return;
}



SQUARE::SQUARE (GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    std::cout << "new SQUARE entity created!\n\n";

    std::cout << "X = " << x << "\nY = " << y << "\n\n";
  this-> locationX = x; //add the x and y to this entity.
 this->locationY = y; 
    std::cout << "location: " << locationX << "  " << locationY << "\n\n";
    SQUARE::colour4f[0] = R; //assign colours.
    SQUARE::colour4f[1] = G;
    SQUARE::colour4f[2] = B;
    SQUARE::colour4f[3] = A;
    this->solid = true; //set entity to solid.
    
    return;
}

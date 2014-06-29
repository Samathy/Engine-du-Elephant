/************************
Class methods for the star class.
************************/

#include "all_entities.h"
#include "all_header.h"
#include <stdint.h>

int STAR::points = 0;


GLfloat STAR::return_locationX()
{
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat STAR::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;

}

bool STAR::return_solid()
{
    solidmtx.lock();
    bool tmp = this->solid;
    solidmtx.unlock();
    return tmp;

}

void STAR::render()
{
    GLfloat pointTL[2] = {(this->locationX + 0.05f),        (this->locationY)};
    GLfloat pointTR[2] = {(this->locationX + 0.1f), (this->locationY)};
    GLfloat pointBR[2] = {(this->locationX + 0.1f), (this->locationY - 0.05f)};
    GLfloat pointBL[2] = {(this->locationX),        (this->locationY - 0.05f)};

    //std::cout << "colours: " << colour4f[0] << " " << colour4f[1] << " " << colour4f[2] << " " << colour4f[3] << "\n";

     glMatrixMode (GL_MODELVIEW);
     glLoadIdentity(); //load ID
     glTranslatef(1280.0f/2.f, 720.0f/2.f, 0.f);
     glScalef(500.0f, 500.0f, 0.0f);

     glBegin(GL_TRIANGLES); //draw quad.
        glColor4f(this->colour4f[0], this->colour4f[1], this->colour4f[2], this->colour4f[3]);
        glVertex2f(pointTL[0],pointTL[1]);
        glVertex2f(pointBR[0],pointBR[1]);
        glVertex2f(pointBL[0],pointBL[1]);
        glVertex2f(pointTL[0],(pointTL[1] - 0.1f));
        glVertex2f(pointBR[0],pointBR[1]);
        glVertex2f(pointBL[0],pointBL[1]);
     glEnd();

return;

}


void STAR::handle_keys(int key, map* ptrmap)
{
    return;
}

void STAR::handle_collision(int x, int y)
{
    if (this->pickedUp != true) //if this hasent been picked up.
    {
        this->pickedUp = true; //then indicate that it has now
        //std::cout << "Handling collision...\n\n";
        points = points + 2; //increment the points amount.
        std::cout << "Points = " << this->points << "\n";
        colourmtx.lock();
        this->colour4f[3] = 0.0f; //and make it invisible.
        colourmtx.unlock();
        return;
    }
    else
    { 
        return; //else do nothing.
    }
    return;
}


void STAR::do_logic()
{   
    game_state state;
    if (this->points >= 10)
    {   
        std::cout << "\nYou Won!\n";
        state.change_quit_state(true); //if the points >= 10 then quit the game.
        
    }
return;
 
}



STAR::STAR (GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    std::cout << "new STAR  entity created!\n\n";

    std::cout << "X = " << x << "\nY = " << y << "\n\n";
    this->locationX = x; //add the x and y to this entity.
  locationY = y;
    std::cout << "location: " << locationX << "  " << locationY << "\n\n";
    this->colour4f[0] = 0.835294f; //assign colours.
    this->colour4f[1] = 0.94117647058f;
    this->colour4f[2] = 0.14901960784f;
    this->colour4f[3] = A;
    this->solid = false ;//set entity to solid.

    return;
}

/*************************
DEFAULT entity class methods.
***************************/


#include "all_entities.h"
#include "all_header.h"



GLfloat DEFAULT::return_locationX()
{
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat DEFAULT::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;

}

void DEFAULT::render()
{
        GLfloat pointTL[2] = {(DEFAULT::locationX), (DEFAULT::locationY + 0.0f)};
        GLfloat pointTR[2] = {(DEFAULT::locationX + 0.1f), (DEFAULT::locationY)};
        GLfloat pointBR[2] = {(DEFAULT::locationX + 0.1f), (DEFAULT::locationY - 0.1f)};
        GLfloat pointBL[2] = {(DEFAULT::locationX), (DEFAULT::locationY - 0.1f)};
        
        std::cout << "colours: " << colour4f[0] << " " << colour4f[1] << " " << colour4f[2] << " " << colour4f[3] << "\n";
        
        
                
        glLoadIdentity(); //load ID
        glBegin(GL_QUADS); //draw quad.
            glColor3f(1.0f,0.0f,0.0f);
            glVertex2f(pointTL[0],pointTL[1]);
            glVertex2f(pointTR[0],pointTR[1]);
            glVertex2f(pointBR[0],pointBR[1]);
            glVertex2f(pointBL[0],pointBL[1]);
        glEnd();

return;

}


void DEFAULT::handle_keys(int key, map* ptrmap)
{
    return;
}

void DEFAULT::handle_collision(int x, int y)
{
    return;
}

void DEFAULT::do_logic()
{
return;
}



DEFAULT::DEFAULT (GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    std::cout << "new DEFAULT entity created!\n\n";

    std::cout << "X = " << x << "\nY = " << y << "\n\n";
    DEFAULT::locationX = x; //add the x and y to this entity.
  locationY = y; 
    std::cout << "location: " << locationX << "  " << locationY << "\n\n";
    DEFAULT::colour4f[0] = R; //assign colours.
    DEFAULT::colour4f[1] = G;
    DEFAULT::colour4f[2] = B;
    DEFAULT::colour4f[3] = A;
    
    return;
    
}

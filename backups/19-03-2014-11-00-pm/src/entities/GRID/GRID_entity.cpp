/************************
GRID entity members
*************************/

#include "all_entities.h"

GLfloat GRID::return_locationX()
{
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat GRID::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;

}

void GRID::render()
{
//Renders a large grid showing all the elements on the screen.
        glBegin(GL_LINES);
            glColor3f(1.f,0.f,0.f);
            glVertex2f(0.f, 1.0f);
            glVertex2f (0.0f, -1.0f);
            glVertex2f (-1.0f, 0.0f);
            glVertex2f (1.0f, 0.0f);
            
            glVertex2f (0.5f, 1.0f);
            glVertex2f (0.5f, -1.0f);
            glVertex2f (-0.5f, 1.0f);
            glVertex2f (-0.5f, -1.0f);
            
            glVertex2f (-1.0f, -0.5f);
            glVertex2f (1.0f, -0.5f);
            glVertex2f (1.0f, 0.5f);
            glVertex2f (-1.0f, 0.5f);
            
            glVertex2f (-1.0f, -0.1f);
            glVertex2f (1.0f, -0.1f);
            glVertex2f (1.0f, 0.1f);
            glVertex2f (-1.0f, 0.1f);
            
            glVertex2f (-1.0f, -0.2f);
            glVertex2f (1.0f, -0.2f);
            glVertex2f (1.0f, 0.2f);
            glVertex2f (-1.0f, 0.2f);
            
            glVertex2f (-1.0f, -0.3f);
            glVertex2f (1.0f, -0.3f);
            glVertex2f (1.0f, 0.3f);
            glVertex2f (-1.0f, 0.3f);
            
            glVertex2f (-1.0f, -0.4f);
            glVertex2f (1.0f, -0.4f);
            glVertex2f (1.0f, 0.4f);
            glVertex2f (-1.0f, 0.4f);
            
            glVertex2f (-1.0f, -0.6f);
            glVertex2f (1.0f, -0.6f);
            glVertex2f (1.0f, 0.6f);
            glVertex2f (-1.0f, 0.6f);
            
            glVertex2f (-1.0f, -0.7f);
            glVertex2f (1.0f, -0.7f);
            glVertex2f (1.0f, 0.7f);
            glVertex2f (-1.0f, 0.7f);
            
            glVertex2f (-1.0f, -0.8f);
            glVertex2f (1.0f, -0.8f);
            glVertex2f (1.0f, 0.8f);
            glVertex2f (-1.0f, 0.8f);
            
            glVertex2f (-1.0f, -0.9f);
            glVertex2f (1.0f, -0.9f);
            glVertex2f (1.0f, 0.9f);
            glVertex2f (-1.0f, 0.9f);
            
            glVertex2f(0.1f, 1.0f);
            glVertex2f (0.1f, -1.0f);

            glVertex2f(0.2f, 1.0f);
            glVertex2f (0.2f, -1.0f);
            glVertex2f(0.3f, 1.0f);
            glVertex2f (0.3f, -1.0f);

            glVertex2f(0.4f, 1.0f);
            glVertex2f (0.4f, -1.0f);
            
            glVertex2f(0.6f, 1.0f);
            glVertex2f (0.6f, -1.0f);
            
            glVertex2f(0.7f, 1.0f);
            glVertex2f (0.7f, -1.0f);
            
            glVertex2f(0.8f, 1.0f);
            glVertex2f (0.8f, -1.0f);
            
            glVertex2f(0.9f, 1.0f);
            glVertex2f (0.9f, -1.0f);
            
            glVertex2f(-0.1f, 1.0f);
            glVertex2f (-0.1f, -1.0f);

            glVertex2f(-0.2f, 1.0f);
            glVertex2f (-0.2f, -1.0f);
            glVertex2f(-0.3f, 1.0f);
            glVertex2f (-0.3f, -1.0f);

            glVertex2f(-0.4f, 1.0f);
            glVertex2f (-0.4f, -1.0f);
            
            glVertex2f(-0.6f, 1.0f);
            glVertex2f (-0.6f, -1.0f);
            
            glVertex2f(-0.7f, 1.0f);
            glVertex2f (-0.7f, -1.0f);
            
            glVertex2f(-0.8f, 1.0f);
            glVertex2f (-0.8f, -1.0f);
            
            glVertex2f(-0.9f, 1.0f);
            glVertex2f (-0.9f, -1.0f);
        glEnd();

return;

}

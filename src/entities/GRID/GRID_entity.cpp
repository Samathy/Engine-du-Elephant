/************************
GRID entity members
*************************/

#include "all_entities.h"

GLfloat GRID::return_locationX()
{
return 0.0f;
}

GLfloat GRID::return_locationY()
{
    
    return 0.0;

}

bool GRID::return_solid()
{
    return false;
}

void GRID::render()
{
    	    glLoadIdentity();
	    glTranslatef( 1920 /2.f, 1080/2.f, 0.f); //remove hard coded translate values here and ensure that the real screen sizes get put in :)
        glScalef(500.0f, 500.0f, 500.0f);
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



GRID::GRID(GLfloat X ,GLfloat Y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    this->solid = false;
    return;

}

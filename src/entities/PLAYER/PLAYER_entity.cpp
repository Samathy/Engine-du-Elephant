/************************
Class methods for PLAYER class.
************************/

#include "all_entities.h"
#include "all_header.h"



GLfloat PLAYER::return_locationX()
{
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat PLAYER::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;

}

bool PLAYER::return_solid()
{
    return false;
}


void PLAYER::render()
{
        GLfloat pointTL[2] = {(this->locationX), (this->locationY + 0.0f)};
        GLfloat pointTR[2] = {(this->locationX + 0.1f), (this->locationY)};
        GLfloat pointBR[2] = {(this->locationX + 0.1f), (this->locationY - 0.1f)};
        GLfloat pointBL[2] = {(this->locationX), (this->locationY - 0.1f)};
        
        //std::cout << "colours: " << colour4f[0] << " " << colour4f[1] << " " << colour4f[2] << " " << colour4f[3] << "\n";
        
        
	glMatrixMode (GL_MODELVIEW);
        glLoadIdentity(); //load ID
       	//glTranslatef(1280.0f /2.f, 720.0f/2.f, 0.f); //Remove hardcoded translate values and passt over screensize.
        //glScalef(500.0f, 500.0f, 0.0f);
	glBegin(GL_QUADS); //draw quad.
            //glColor3f(SQUARE::colour4f[0],SQUARE::colour4f[1],SQUARE::colour4f[2]);
            glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
            glVertex2f(pointTL[0],pointTL[1]);
            glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
            glVertex2f(pointTR[0],pointTR[1]);
            glColor4f(0.0f,0.0f, 1.0f, 1.0f);
            glVertex2f(pointBR[0],pointBR[1]);
            glColor4f(0.0f,0.0f, 1.0f, 1.0f);
            glVertex2f(pointBL[0],pointBL[1]);
        glEnd();

return;

}


void PLAYER::handle_keys(int key, map* mapptr)
{

    
    
   
    
    if (key == 119 || key ==  1073741906 ) //if key == W then try to move forward.
    {
            int entities = mapptr->return_number_of_entities();
           
            
            for (int i=0; (i)<entities; ++i) //loop for the amount of instatiated entities.
            {
               
               int tmpY = (mapptr->entityStack[i]->return_locationY() * 10);
               int tmpX = (mapptr->entityStack[i]->return_locationX() * 10);
               int thistmpY = (this->return_locationY() * 10);
               int thistmpX = (this->return_locationX() * 10);
                
                std::cout << "\ntmpY = " <<  tmpY << " tmpX = " <<  tmpX << "\nthistmpY = " << thistmpY << " thistmpX =" << thistmpX << "\n" ; 
                std::cout << "polling entity number: " << i << "\n";
                std::cout << "entities -2 = " << (entities - 2 ) << "\n";               
                               
                std::cout << "thistmpX = " << thistmpX << " thistmpY = " << thistmpY << "\n";
                std::cout << "tmpX = " << tmpX << "tmpY = " << tmpY << "\n";

                 if (tmpY == (thistmpY  - 1)  && tmpX == (thistmpX))
                    {
                       std::cout << "entity in intended place, handling...\n";

                    
                         mapptr->entityStack[i]->handle_collision(0,0); //then call that entities cillision function. with n o collision parameters.
                     
                        if (mapptr->entityStack[i]->return_solid() == true) //if the entity in the way is solid then just dont move.
                        {
                          break;
                        }
                        else if (mapptr->entityStack[i]->return_solid() == false) //is there isnt a solid entity in the place we want to move to, then move!
                        {
                            std::cout << "Changing location\n\n";
                            locationYmtx.lock();
                            this->locationY = locationY - 0.1f; //if the key = W then move one up
                            locationYmtx.unlock();
                         
                            break;
                        }
                    }
                
                
                else if (tmpX != (thistmpX) && tmpY != (thistmpY + 1 ) ) // If the entity we're looking at is not at the position we want to move to.
                {
		    std::cout << "Entity not where we want to be\n";	
		}

                    //int e = entities;
                   // --e;
		    //--e;
		    //std::cout << "

                    //if (i == e) //and we're at the end of the entities
                    //{
                        //locationYmtx.lock();
                       // this->locationY = locationY + 0.1f; //Then move.
                       // locationYmtx.unlock();
                       // break; 
                    //}
                //}
               
                if (i == (entities - 1))
                {   
		    std::cout << "Finished checking all entities, rendering\n";	
                    locationYmtx.lock();
                    this->locationY = locationY - 0.1f; //Then move.
                    locationYmtx.unlock();
                    break;
                }   
                      
              
                
             }   
            return;
           
    }
    
    
    if (key == 97 || key == 1073741904  ) //if key == A then try to move LEFT.
    {
            int entities = mapptr->return_number_of_entities();
             
            
            for (int i=0; (i)<entities; ++i) //loop for the amount of instatiated entities.
            {
               
                int tmpY = (mapptr->entityStack[i]->return_locationY() * 10);
                int tmpX = (mapptr->entityStack[i]->return_locationX() * 10);
                int thistmpY = (this->return_locationY() * 10);
                int thistmpX = (this->return_locationX() * 10);
                
                                        
 
                if (tmpY == (thistmpY) && tmpX == (thistmpX - 1))
                    {
                        std::cout << "There is something in the space we want to move to.\n\n";    
                        mapptr->entityStack[i]->handle_collision(0,0); //then call that entities cillision function. with n o collision parameters.
                        if (mapptr->entityStack[i]->return_solid() == true) //if the entity in the way is solid then just dont move.
                        {   
                            std::cout << "Solid detected.\n";
                            break;
                        }
                        else if (mapptr->entityStack[i]->return_solid() == false) //is there isnt a solid entity in the place we want to move to, then move!
                        {
                            std::cout << "non-solid detected.\n\n";
                            locationYmtx.lock();
                            this->locationX = locationX - 0.1f; //if the key = W then move one up
                            locationYmtx.unlock();
                            break;
                        }
                    }
                
                
               else if (tmpY != (thistmpY) && tmpX != (thistmpX - 1)) // If the entity we're looking at is not at the position we want to move to.
                {
                              
		    std::cout << "Entity not where we want to be\n";	
		}

                    //int e = entities;
                   // --e;
		    //--e;
		    //std::cout << "

                    //if (i == e) //and we're at the end of the entities
                    //{
                        //locationYmtx.lock();
                       // this->locationY = locationY + 0.1f; //Then move.
                       // locationYmtx.unlock();
                       // break; 
                    //}
                //}
               
                if (i == (entities - 1))
                {   
		    std::cout << "Finished checking all entities, rendering\n";	
                    locationYmtx.lock();
                    this->locationX = locationX - 0.1f; //Then move.
                    locationYmtx.unlock();
                    break;
                }   
                      
             
             }   
            return;
           
    }
    
            
    if (key == 100 || key == 1073741903 ) //if key == D then try to move RIGHT.
    {
            int entities = mapptr->return_number_of_entities();
            
            for (int i=0; (i)<entities; ++i) //loop for the amount of instatiated entities.
            {
               
                int tmpY = (mapptr->entityStack[i]->return_locationY() * 10);
                int tmpX = (mapptr->entityStack[i]->return_locationX() * 10);
                int thistmpY = (this->return_locationY() * 10);
                int thistmpX = (this->return_locationX() * 10);
                
               // std::cout << "tmpY = " <<  tmpY << " tmpX = " <<  tmpX << " thistmpY = " << thistmpY << " thistmpX =" << thistmpX << "\n" ; 
                //std::cout << "polling entity number: " << i << "\n";
                //std::cout << "entities -2 = " << (entities - 2 ) << "\n";               
 
                 if (tmpY == (thistmpY) && tmpX == (thistmpX + 1))
                    {
                    
                        std::cout << "Returned entity present in X " << tmpX << " Y " << tmpY << "\n\n";
		      	    mapptr->entityStack[i]->handle_collision(0,0); //then call that entities cillision function. with n o collision parameters.
                        if (mapptr->entityStack[i]->return_solid() == true) //if the entity in the way is solid then just dont move.
                        {
				std::cout << "breaking...\n\n";	
                            break;
                        }
                        else if (mapptr->entityStack[i]->return_solid() == false) //is there isnt a solid entity in the place we want to move to, then move!
                        {
			    std::cout << "is not solid, moving...\n";
                            locationYmtx.lock();
                            this->locationX = locationX + 0.1f; //if the key = W then move one up
                            locationYmtx.unlock();
                            break;
                        }
                    }
                
                
                else if (tmpY != (thistmpY) && tmpX != (thistmpX + 1)) // If the entity we're looking at is not at the position we want to move to.
                                {
		    std::cout << "Entity not where we want to be\n";	
		}

                    //int e = entities;
                   // --e;
		    //--e;
		    //std::cout << "

                    //if (i == e) //and we're at the end of the entities
                    //{
                        //locationYmtx.lock();
                       // this->locationY = locationY + 0.1f; //Then move.
                       // locationYmtx.unlock();
                       // break; 
                    //}
                //}
               
                if (i == (entities - 1))
                {   
		    std::cout << "Finished checking all entities, rendering\n";	
                    locationYmtx.lock();
                    this->locationX = locationX + 0.1f; //Then move.
                    locationYmtx.unlock();
                    break;
                }   
                      
             }   
            std::cout << "Loop broke\n\n";
            return;
           
    }
    
    
    
    if (key == 115 || key == 1073741905 ) //if key == S  then try to move DOWN.
    {
            int entities = mapptr->return_number_of_entities();
            
            for (int i=0; (i)<entities; ++i) //loop for the amount of instatiated entities.
            {
               
                int tmpY = (mapptr->entityStack[i]->return_locationY() * 10);
                int tmpX = (mapptr->entityStack[i]->return_locationX() * 10);
                int thistmpY = (this->return_locationY() * 10);
                int thistmpX = (this->return_locationX() * 10);
                
  
                 if (tmpY == (thistmpY + 1) && tmpX == thistmpX )
                    {

			    std::cout << "found entity\n";    
                    
                         mapptr->entityStack[i]->handle_collision(0,0); //then call that entities cillision function. with n o collision parameters.
                        if (mapptr->entityStack[i]->return_solid() == true) //if the entity in the way is solid then just dont move.
                        {
				
			    std::cout << "Is solid, breaking.\n";	
                            break;
                        }
                        else if (mapptr->entityStack[i]->return_solid() != true) //is there isnt a solid entity in the place we want to move to, then move!
                        {
			    std::cout << "Is not solid\n";	
                            locationYmtx.lock();
                            this->locationY = locationY + 0.1f; //if the key = W then move one up
                            locationYmtx.unlock();
                            break;
                        }
                    }
                
                
               else  if (tmpY != (thistmpY + 1) && tmpX != thistmpX ) // If the entity we're looking at is not at the position we want to move to.
                {
		    std::cout << "Entity not where we want to be\n";	
		}

                    //int e = entities;
                   // --e;
		    //--e;
		    //std::cout << "

                    //if (i == e) //and we're at the end of the entities
                    //{
                        //locationYmtx.lock();
                       // this->locationY = locationY + 0.1f; //Then move.
                       // locationYmtx.unlock();
                       // break; 
                    //}
                //}
               
                if (i == (entities - 1))
                {   
		    std::cout << "Finished checking all entities, rendering\n";	
                    locationYmtx.lock();
                    this->locationY = locationY + 0.1f; //Then move.
                    locationYmtx.unlock();
                    break;
                }   
                      
             }   
            return;
           
    }
    
    

    
    return;
}

void PLAYER::handle_collision(int x, int y)
{
    return;
}

void PLAYER::do_logic()
{
return;
}



PLAYER::PLAYER (GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    std::cout << "new PLAYER entity created!\n\n";

    std::cout << "X = " << x << "\nY = " << y << "\n\n";
    this->locationX = x; //add the x and y to this entity.
    this->locationY = y; 
    std::cout << "location: " << this->locationX << "  " << this->locationY << "\n\n";
    this->colour4f[0] = 0.0f; //assign colours.
    this->colour4f[1] = 1.0f;
    this->colour4f[2] = 1.0f;
    this->colour4f[3] = 1.0f;
    
    return;
}

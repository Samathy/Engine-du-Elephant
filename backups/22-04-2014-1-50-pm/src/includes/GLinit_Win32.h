/********************
GL initialiseation function with a few differances for windows.
***********************/



bool initGL(int width, int height)
{
    GLdouble tempW = (double) width;
    GLdouble tempH = (double) height;
    
    
    glViewport (0, 0, width, height);
    
        GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! 27" << gluErrorString( error ) << "\n";
       return false;
   }    

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
     error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! 38 " << gluErrorString( error ) << "\n";
       return false;
   }
    
    glOrtho(0.0, tempW, tempH, 0.0, -1, 1);
    
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! 47" << gluErrorString( error ) << "\n";
       return false;
   }
    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
   error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! 57 " << gluErrorString( error ) << "\n";
       return false;
   }
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Initialise alpha.
    glEnable( GL_BLEND );
    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! 70 " << gluErrorString( error ) << "\n";
       return false;
    }
 


    return true;
}

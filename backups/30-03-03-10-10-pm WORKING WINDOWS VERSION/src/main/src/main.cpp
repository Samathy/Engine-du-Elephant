

#include "all_header.h"
#include "map_header.h"
#include <string>
#include <time.h>

#ifdef  _WIN32
#define scale 100.0f
#else 
#define scale 1.0f
#endif


/**********************************
The .cpp that holds the main function of the program. This function does all tha calling of the other functions.
****************************************/



int count;

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
    
    glOrtho(0.0, tempW, tempH, 0.0, 1, -1);
    
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


bool interpret_commands(std::string argument)
{

    game_state state; //new gamestate object 
    
    std::cout << "this is interpret commands func\n\n";
    std::cout << "Interpreting the command: " << argument << "\n\n";
    
    if (argument.compare("exit") == 0 || argument.compare("Exit") == 0 ) //Check for valid console inputs.
    {
        std::cout<<("Exiting...\n");
        state.change_quit_state(true); //change quit state to true
        
                return false;
    }
    else if (argument.compare("help") == 0 || argument.compare("Help") == 0)
    {
        std::cout<<("Avalible commands are: \n") << ("exit - Exits the program safely.\n") << ("help - Displays this message\n");
        return true;
    }
    else
    {
        std::cout<<("Unknown command, use help.\n");
        return true;
    };
return true;
} 

void entity_logic_loop(int entities, map* ptrmap)
{
    int ticks = 0;
    unsigned long startTime = 0; //var to hold  start time.
    unsigned long time = 0 ; //var to hold current time.
    
    timer timer; //new timer object.
    
    game_state state; //new game state object.
    
    
    while (state.return_quit_state() != true) //loop while not quit.
    {
            timer.start(); //start timer.
            startTime = timer.getTime();
            ++ticks; //increment tick count.
            
            for (int i = 0; i<entities; ++i) //loop for however many 
            {
                ptrmap->entityStack[i]->do_logic(); //render entities.
            }
            
            time = timer.getTime(); //get current time
        
            if (time != (startTime+1)) //if a second has not passed then
            {
                if (ticks == 64) //check if there have been 64 ticks.
                {
                    while (time != (startTime+1)) // if there has been 64 ticks then loop until current time == startTime plus a second
                        {
                            time = timer.getTime();
                        }
                    ticks = 0; //and put ticks back to 0 again.
                }
            }
            timer.stop(); //stop timer.
            timer.reset(); //reset timer.

    }
    
    return;
    

}

bool game_loop(command* commandptr, map* ptrmap, SDL_Window* ptrwindow) //game loop.
//bool game_loop( map* ptrmap, SDL_Window* ptrwindow) //game loop.
{
        
        SDL_Event event; //init SDL events.
        game_state state; //create new game state object.
        
bool quit = false; //temp var to indicate the state of the quit.

while ( quit != true)
{

            glClear ( GL_COLOR_BUFFER_BIT); //clear the screen.
//            glMatrixMode (GL_MODELVIEW);
//	    glLoadIdentity();
//	    glTranslatef(1920 /2.f, 1080/2.f, 0.f);

	    std::cout << "Entities: " << ptrmap->return_number_of_entities() << "\n";

            for (int i = 0; i<ptrmap->return_number_of_entities(); ++i) //loop for however many 
            {
                std::cout << "Rendering...\n\n";
                ptrmap->entityStack[i]->render(); //render entities.

            }
            
            //std::cout << "Exited renderloop, swapping buffers.\n\n";
            
            SDL_GL_SwapWindow(ptrwindow); //show content.
            
    while ( SDL_PollEvent ( &event )) //check for SDL events.
        {
                if (event.type == SDL_QUIT ) //if its quit, then quit.
                {
                    state.change_quit_state(true); //change quit state.
                    quit = (true); //change local quit state.
                }
                else if ( event.type == SDL_KEYDOWN ) //else check for key presses
                {
                    std::cout << "HANDLING THE FOLLOWING KEYS: " << event.key.keysym.sym << "\n\n";
                    int quitkey = 113;
                    int key = (&event)->key.keysym.sym;
                    
                    if ((&event)->key.keysym.sym == quitkey )
                    {
                    state.change_quit_state(true);
                    quit = true; //set local quit state.
                    std::cout << " state changed, returning FALSE\n\n";
                    }
                    else
                    {
                        
                        for (int i = 0; i<ptrmap->return_number_of_entities(); ++i) //loop for however many 
                        {
                            ptrmap->entityStack[i]->handle_keys(key, ptrmap); //giv all the entities the key.

                        }
                    }
                }
        }
            //std::cout << "checking commands.\n\n";
            
            if (commandptr->return_command_present() == true ) // check if there is a command present.
            {   
                std::string temp = commandptr->return_arg(); //if there is, get it.
                std::cout << "interpreting command: "<< temp <<"\n\n";
                bool commands = interpret_commands(temp);
                
                if (commands == false) //if interpret commands returns false, then return false to exit program.
                    {
                        std::cout << "commands == false!\n\n";
                        state.change_quit_state(true); //set the quit state.
                        quit = true; //set local quit state.
                    } //nterrupt loop and interpret command.
                
                else if (commands == true)
                    {
                        std::cout << "Restarting commandline \n\n";
                        commandptr->start_command(); //restart commandline.
                    }
            }
            


    }
    //std::cout << "Main while loop is returning!\n\n";
return false;
}

int main( int argc, char* argv[] )
{
       
    
    //get_settings read_settings; //create a settings reading object.    
    int screenDataW = 1920; //put screen data into a temp var
    int screenDataH = 1080;
    

    
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL init error: " << SDL_GetError();
     return 0;
    } //start SDL

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2); //set GL version of the window
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);    
    SDL_Window* window = SDL_CreateWindow( "RainbowRPG - SDL2.0 - OpenGL2.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenDataW, screenDataH, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL); //create OpenGL window

    SDL_GLContext glcontext = SDL_GL_CreateContext(window); //set context as OpenGL
        initGL(screenDataW, screenDataH); //init GL.
    
    GLenum err = glewInit();

    if (GLEW_OK != err)
    {
         std::cout << "initialiseing GLEW failed." << glewGetErrorString(err);
         return 0 ;
    }

    std::cout << "Using GLEW - " << glewGetString(GLEW_VERSION) << "\n";

//     glMatrixMode (GL_MODELVIEW);
//   glLoadIdentity();     
//        glScalef(scale, scale, scale);
//      glBegin(GL_QUADS); //draw quad.
//            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
//            //glColor3f(SQUARE::colour4f[0],SQUARE::colour4f[1],SQUARE::colour4f[2]);
//            //glColor4f(SQUARE::colour4f[0],SQUARE::colour4f[1],SQUARE::colour4f[2],SQUARE::colour4f[3]);
//            glVertex2f(-1.0f,1.0f);
//            glVertex2f(1.0f,1.0f);
//            glVertex2f(1.0f,-1.0f);
//            glVertex2f(-1.0f,-1.0f);
//            glEnd();
//           
//            GLenum error = glGetError();
//            if( error != GL_NO_ERROR )
//            {
//            std::cout << "Error drawing! 177 " << gluErrorString( error ) << "\n";
//            return false;
//            }
//            SDL_GL_SwapWindow(window); //show content.
//            SDL_Delay(1000);
//     return 0;

    //command_thread.detach();
//    SDL_Delay(1000);
    std::string mapFile ("a.map");
    std::cout << "Initialising map!\n\n";
    
    map* ptrmap; //create a pointer of type map.
    map currentMap (screenDataW, screenDataH, mapFile);
    ptrmap = &currentMap; //make pointer point to instance of map.
    std::cout << "checking for inputted commands....";
    

    command* ptrCommand; //create a pointer of type command.
    command commandline; //create command line object.
    std::cout << "creating command line thread...\n";
    boost::thread command_thread ( boost::bind (&command::start_command, &commandline) ); //create a thread of the command line.
    std::cout << "Command thread started\n\n";
    ptrCommand = & commandline; //make pointer point to command object.
    
    int entities = ptrmap -> return_number_of_entities();
    
    boost::thread logic_loop (boost::bind(&entity_logic_loop, entities, ptrmap)); //create logic loop thread.
    
    std::cout << "Running game loop func\n\n";
    game_loop(ptrCommand, ptrmap, window);
    //game_loop( ptrmap, window);

    currentMap.destroy_map(); //destroy the map!
    SDL_GL_DeleteContext(glcontext); //clean up
    SDL_Quit(); //quit SDL   
    logic_loop.join(); //join logic thread.
    std::cout << "\nQuited nicely, press any letter/number key then tap return to terminate \n(This is a problem with using threads and std::cin together, must find a better way of doing this safely\n\n"; // - Remember killing the thread causes recursive terminate >.<.)\n\n";
    command_thread.join(); //detach both out threads.
    


    return 0;
    
    }
    






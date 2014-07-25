

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




bool initGL(int width, int height)
{
    GLdouble tempW = (double) width;
    GLdouble tempH = (double) height;
    
    
    glViewport (0, 0, tempW, tempH); //set viewport to the entire screen.
    
        GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL!" << gluErrorString( error ) << "\n";
       return false;
   }    
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
     error = glGetError();
    if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! " << gluErrorString( error ) << "\n";
       return false;
   }
    
    glOrtho(0.0, 1920.0, 1080.0, 0.0, 1.0, -1.0); // Set matrixs.
    
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        std::cout << "Error initializing OpenGL!" << gluErrorString( error ) << "\n";
        return false;
    }
    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
   error = glGetError();
   if( error != GL_NO_ERROR )
    {
       std::cout << "Error initializing OpenGL! " << gluErrorString( error ) << "\n";
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
            std::cout << "ticks..." << ticks << "\n";
    }
    
    return;
    

}

bool game_loop( map* ptrmap, SDL_Window* ptrwindow) //game loop.
{
        
        SDL_Event event; //init SDL events.
        game_state state; //create new game state object.
          

        bool quit = false; //temp var to indicate the state of the quit.

while ( state.return_quit_state() != true)
{

            glClear ( GL_COLOR_BUFFER_BIT); //clear the screen.

	    std::cout << "Entities: " << ptrmap->return_number_of_entities() << "\n";

            for (int i = 0; i<ptrmap->return_number_of_entities(); ++i) //loop for however many 
            {
                //std::cout << "Rendering...\n\n";
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
                            std::cout << "sending key to entities..."<< i << "\n";
                            ptrmap->entityStack[i]->handle_keys(key, ptrmap); //giv all the entities the key.
                            std::cout << "handled key...\n";
                         } 
                    }
                }
        }
    }
return false;
}      


int main( int argc, char* argv[] )
{
       
    char* settings_file = "conf.lua";
        
    lua_State* L = luaL_newstate(); //set up Lua
    luaopen_base(L);
    luaopen_io(L);
    luaopen_string(L);
    luaopen_math(L);

    luaL_loadfile(L, settings_file) || lua_pcall(L, 0,0,0); //load initial setup script

    lua_getglobal(L, "width"); //get width and height
    lua_getglobal(L, "height");
    lua_getglobal(L, "name"); //get name
    lua_getglobal(L, "entity_conf"); //get entity setup script
    int screenDataW = (int)lua_tonumber(L, -4);
    int screenDataH = (int)lua_tonumber(L, -3);
    const char* entity_setup = lua_tostring(L, -1);
    const char* name = lua_tostring(L, -2);
    std::cout << "Screen data: " << screenDataW << ", " << screenDataH << "\n";
    std::cout << "Name: " << name << "\n";
    std::string entity_conf (entity_setup);
    std::cout << "entity map name: " << entity_conf << "\n";

    SDL_Delay(1000);


    
   



    
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL init error: " << SDL_GetError();
     return 0;
    } //start SDL

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2); //set GL version of the window
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);    
    SDL_Window* window = SDL_CreateWindow( name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenDataW, screenDataH, SDL_WINDOW_OPENGL); //create OpenGL window

    SDL_GLContext glcontext = SDL_GL_CreateContext(window); //set context as OpenGL
    initGL(screenDataW, screenDataH); //init GL.
    

    std::cout << "Using GLEW - " << glewGetString(GLEW_VERSION) << "\n";

           
            GLenum error = glGetError();
            if( error != GL_NO_ERROR )
            {
            std::cout << "Error drawing! 177 " << gluErrorString( error ) << "\n";
            return false;
            }
   
    std::string mapFile (entity_conf);
    std::cout << "Initialising map!\n\n";
    
    map* ptrmap; //create a pointer of type map.
    map currentMap (screenDataW, screenDataH, entity_conf);
    ptrmap = &currentMap; //make pointer point to instance of map.
    std::cout << "checking for inputted commands....";

    
    int entities = ptrmap -> return_number_of_entities();
    
    boost::thread logic_loop (boost::bind(&entity_logic_loop, entities, ptrmap)); //create logic loop thread.
    
    std::cout << "Running game loop func\n\n";
    game_loop(ptrmap, window);

    currentMap.destroy_map(); //destroy the map!
    SDL_GL_DeleteContext(glcontext); //clean up
    SDL_Quit(); //quit SDL   
    logic_loop.join(); //join logic thread.
    


    return 0;
    
    }
    






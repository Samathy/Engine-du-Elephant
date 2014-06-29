/*********************************************************************************
Command line interpreter class.
After exiting returns with a value in exitCode if program is needed to be exited.
*********************************************************************************/

#include "all_header.h"
#include "SDLheaders.h"

//class command: public object
//{
//    public:
//        void start_command(); //starts command line interpreter.
//        bool return_command_present(); //returns true if there is a command waiting.
//        std::string return_arg(); //return the last command entered.
//    private:
//        std::string arg; //command storing string.
//        
//        boost::mutex arg_mtx; //mutex.
//        boost::mutex present_mtx;
//};

void command::start_command()
{

        game_state state; //new game state object.

    present_mtx.lock();
    //std::cout << "present locked start_command\n";
        command_present = false; //this is here just so that command_present is ensured to be showing FALSE if we start_command() again after dealing with a command.
    present_mtx.unlock();
    //std::cout << "present unlocked start_command\n";
    
    std::string string; //temp string for command to reduce mutex locking.

    std::cout << "->   ";
    std::cin >> string; //wait for input
    if (state.return_quit_state() == true) //if the game is in quit state, the return instantly.
        {
        return;
        }
    
    arg_mtx.lock();
    //std::cout << "arg locked start_command\n";
        command::arg = string; //push command into command class's thing.
    arg_mtx.unlock();
    //std::cout << "arg unlocked start_command\n";

    //std::cout << "present locked start_command\n";
    present_mtx.lock(); //lock this var
        command::command_present = true; //show that there has been a command entered.
    present_mtx.unlock(); //unlock this var.
    //std::cout << "present unlocked start_command\n";
    return;
    
}

bool command::return_command_present()
{
    SDL_Delay(1500);
    //std::cout << "present locked return_command_present\n";
    present_mtx.lock();
    bool temp = command_present;
    present_mtx.unlock();
    //std::cout << "present unlocked return_command_present\n";
    return temp; //return the bool which indicates a command waiting to be processed.
}

std::string command::return_arg()
{
    //std::cout << "arg locked return_arg\n";
    arg_mtx.lock();
    std::string temp = arg;
    arg_mtx.unlock();
    
    present_mtx.lock();
    command::command_present = false; //assume that there is no longr a command present.
    present_mtx.unlock();
    
    arg_mtx.lock();
    arg.clear(); //clear the string.
    arg_mtx.unlock();
    //std::cout << "arg unlocked return_arg\n";
    return temp; //return the waiting string containing the command.

}


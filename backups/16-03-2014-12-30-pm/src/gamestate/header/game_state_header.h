/***************************
Game state class. Contains information about the state of the game so that all threads etc know whats going on.
****************************/

#include <boost/thread/mutex.hpp>

#ifndef GAME_STATE_HEADER_H
#define GAME_STATE_HEADER_H

class game_state
{
    boost::mutex quitmtx;
    
    public:
        bool return_quit_state(); //returns the quit state bool safely.
        void change_quit_state (bool); //changes the quit state safely.
    private:
    static bool quit_state; //var showing if the game is in quit state. true if quit.
};

#endif

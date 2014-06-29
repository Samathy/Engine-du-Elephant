#ifndef COMMAND_H
#define COMMAND_H

#include <boost/thread/mutex.hpp>
#include <string>
#include <iostream>
#include "object.h"


class command: public object
{
    public:
        void start_command(); //starts command line interpreter.
        bool return_command_present(); //returns true if there is a command waiting.
        std::string return_arg(); //return the last command entered.
    private:
        std::string arg; //command storing string.
        bool command_present;
        
        boost::mutex arg_mtx; //mutex.
        boost::mutex present_mtx;
};



#endif

#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "SDLheaders.h"

class get_settings
{
    public:
        get_settings(); //constructer
        int get_screen_size_width(); //return screen width.
        int get_screen_size_height(); //return screen height.
        std::string get_options(int); //get other options from settings file ( atm just returns std::string lines[]).
    private:
        void read_settings(std::string); //open settings file and fill lines.
        void interpret_settings(); //interpret settings (atm, just fills screen_size[])
        std::string lines[512]; //all the lines of the settings file.
        int screenSize[2]; //the screen size data.
        void legacy_screen_settings();
};

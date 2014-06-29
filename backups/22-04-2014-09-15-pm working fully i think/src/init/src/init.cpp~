#include "all_header.h"

/***********************************************************************
Contains functions to initilase SDL, the windo and GL stuff and things.
***********************************************************************/

//class get_settings
//{
//    public:
//        get_settings(); //constructer
//        int get_screen_size_width(); //return screen width.
//        int get_screen_size_height(); //return screen height.
//        std::string get_options(); //get other options from settings file ( atm just returns std::string lines[]).
//    private:
//        void read_settings(std::string); //open settings file and fill lines.
//        void interpret_settings(); //interpret settings (atm, just fills screen_size[])
//        std::string lines[512]; //all the lines of the settings file.
//        int screenSize[2]; //the screen size data.
//        void legacy_screen_settings();
//};


get_settings::get_settings()
{
    get_settings::read_settings("settings.inf");
    get_settings::interpret_settings(); //interpret the settings and fill screen_size[];
    return;
}

int get_settings::get_screen_size_width() //returns thwe screenSize data.
{
    return screenSize[0];
}

int get_settings::get_screen_size_height() //returns thwe screenSize data.
{
    return screenSize[1];
}

std::string get_settings::get_options(int element) //returns the entire contents of the settings file (unformatted)
{
    std::string temp = get_settings::lines[element];
    return temp;
}

void get_settings::read_settings(std::string filename) //reads settings file and returns a string array with all the lines in.
{
    int i =  0; //count integer
    std::string line; //temp string for the lines read from the text file.

    std::ifstream settings_file (filename.c_str()); // open file.



        if (!settings_file)
        {
        // Check the stream is in a good state,
        // which here pretty much just means open
        std::cout<< "Cant open settings file. Common cause is not having admin privilages.\n";
        return;
        }

        std::cout << "Opening settings file....\n";

        while (std::getline(settings_file, line))
        // read and immediately check it worked.
        {
            std::cout << line << '\n';
            get_settings::lines[i] = line;
            i= i+1;
        }

return;

}


void get_settings::interpret_settings() //interprest the contents of the settings file, returns screen sizes in int array.
{

    if (get_settings::lines[0] == "%UseLegacyScreen") //if legacy screen settings specified then swap over to that thing.
    {
        get_settings::legacy_screen_settings();
    }

    if (get_settings::lines[0] == "%ScreenSize") //else read screen settings.
    {

        get_settings::screenSize[0] = atoi (lines[1].c_str());//convert stings into integers
        get_settings::screenSize[1] = atoi (lines [2].c_str());
    }

return;

}

void get_settings::legacy_screen_settings() //legacy function for settings the screen size, sets according to options with limeted options.
{
    std::string option = "1";


    if (lines[1] == option) //compare settings file data to the option string above and set the screen size.
    {
        get_settings::screenSize[0] =1280;
        get_settings::screenSize[1] =720;
        return;
    }

    option = "2";

    if (lines[1] == option)
    {
    get_settings::screenSize[0] =1600;
    get_settings::screenSize[1] =900;
    return;
    }

    option = "3";

    if (lines[1] == option)
    {
    get_settings::screenSize[0] =1920;
    get_settings::screenSize[1] =1080;
    return;
    }

    else
    {
    get_settings::screenSize[0] =1280;
    get_settings::screenSize[1] =720;
    std::cout<<"Cannot find valid screen size settings data. Resorting to default.\n";
    }

    return;
}



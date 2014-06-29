/**************************
THIS IS NOT MY CODE. I copied it from this post: http://www.cplusplus.com/forum/beginner/317/#msg1047
Timer class.
***************************/

class timer 
{
    public:
        timer();
        void start();
        void stop();
        void reset();
        bool isRunning();
        unsigned long getTime();
        bool isOver(unsigned long seconds);
    private:
        bool resetted;
        bool running;
        unsigned long beg;
        unsigned long end;
};


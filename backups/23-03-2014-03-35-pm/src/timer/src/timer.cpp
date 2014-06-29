/***************************
THIS IS NOT MY CODE. I copied it from this post: http://www.cplusplus.com/forum/beginner/317/#msg1047
timer implimentation.
****************************/

#include "all_header.h"

timer::timer() {
    resetted = true;
    running = false;
    beg = 0;
    end = 0;
}


void timer::start() {
    if(! running) {
        if(resetted)
            beg = (unsigned long) clock();
        else
            beg -= end - (unsigned long) clock();
        running = true;
        resetted = false;
    }
}


void timer::stop() {
    if(running) {
        end = (unsigned long) clock();
        running = false;
    }
}


void timer::reset() {
    bool wereRunning = running;
    if(wereRunning)
        stop();
    resetted = true;
    beg = 0;
    end = 0;
    if(wereRunning)
        start();
}


bool timer::isRunning() {
    return running;
}


unsigned long timer::getTime() {
    if(running)
        return ((unsigned long) clock() - beg) / CLOCKS_PER_SEC;
    else
        return end - beg;
}


bool timer::isOver(unsigned long seconds) {
    return seconds >= getTime();
}

#ifndef SHAKE_H
#define SHAKE_H
#include <list>
#include <ncurses.h>


#include "pixel.h"
#include "constant.h"

class Shake
{
    private:
        std::list <Pixel*> shake;
        std::list <Pixel*>::iterator _i;
    public:
        Shake();
        ~Shake();
        void    printShake();
        int     checkFrontCoordinates();
        int     checkCoordinates(int x, int y, int from);
        void    push_front(int x, int y);
        std::list<Pixel*>    get_shake();
        void    set_shake(std::list <Pixel*> newShake);
        void    pop_back();
};

#endif

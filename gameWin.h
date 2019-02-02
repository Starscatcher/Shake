#ifndef GAMEWIN_H
#define GAMEWIN_H

#include "constant.h"
#include "ncurses.h"

class gameWin
{
public:
    WINDOW  *createMainWin();
    WINDOW  *createGameArea(WINDOW *originWin);
    gameWin(int height, int wight);
    ~gameWin();
    void    clearWin();
private:
    int _height;
    int _wight;
    void    drawFrame();
};

#endif

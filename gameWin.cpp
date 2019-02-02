#include <ncurses.h>
#include "gameWin.h"

gameWin::gameWin(int height, int wight) : _height(height), _wight(wight)
{

}

gameWin::~gameWin()
{

}

void    gameWin::drawFrame()
{
    int x = 0;
    int y = 0;

    while (x < this->_height)
    {
        move(x, 0);
        printw("#");
        refresh();
        move(x, this->_wight);
        printw("#");
        refresh();
        x++;
    }
    while (y < this->_wight)
    {
        move(0, y);
        printw("#");
        refresh();
        move(this->_height, y);
        printw("#");
        refresh();
        y++;
    }
}

void    gameWin::clearWin()
{
    int x = 1;

    while (x != GAME_HEIGHT)
    {
        int y = 1;
        while (y != GAME_WEIGHT)
        {
            move(x, y);
            printw(" ");
            y++;
        }
        x++;
    }
}

WINDOW  *gameWin::createGameArea(WINDOW *originWin)
{
    WINDOW *window;
    window = subwin(originWin, this->_height, this->_wight, 0, 0);
    drawFrame();
    return (window);
}

WINDOW  *gameWin::createMainWin()
{
    WINDOW *window;
    window = newwin(this->_height, this->_wight, 0, 0);
    drawFrame();
    return (window);
}

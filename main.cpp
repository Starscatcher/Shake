#include "gameWin.h"
#include "pixel.h"
#include <ncurses.h>
//#include <uchar.h>
#include <unistd.h>
#include "Shake.h"
#include "constant.h"
#include <cstdlib>
#include <cstdio>
#include "time.h"

int     dinner(Shake shake, Pixel *food)
{
    if (shake.get_shake().front()->get_x() == food->get_x() && shake.get_shake().front()->get_y() == food->get_y())
    {
//        while (!shake.checkCoordinates(food->get_x(), food->get_y(), 0))
//        {
//            food->set_x(std::rand() % GAME_HEIGHT + 1);
//            food->set_y(std::rand() % GAME_WEIGHT + 1);
//        }
        mvprintw(4, GAME_WEIGHT + 10, "true" );
        return (1);
    }
    else
        return (0);
}

void    shakeGame(gameWin gameArea)
{
    int key = 0;
    Shake shake;
    int eat;

    std::srand(clock());
    shake.printShake();
    Pixel food(5, 5);
    move(food.get_x(), food.get_y());
    printw("*");
    refresh();
    int i = 0;
    while (key != 'q')
    {
        i++;
        key = getch();
        eat = dinner(shake, &food);
        mvprintw(3, GAME_WEIGHT + 10, "%d", eat );
        mvprintw(5, GAME_WEIGHT + 10, "%d", i );
        if (key == 65)
        {
            shake.push_front(-1, 0);
            if (!eat)
                shake.pop_back();
        }
        else if (key == 66)
        {
            shake.push_front(1, 0);
            if (!eat)
                shake.pop_back();
        }
        else if (key == 67)
        {
            shake.push_front(0, 1);
            if (!eat)
                shake.pop_back();
        }
        else if (key == 68)
        {
            shake.push_front(0, -1);
            if (!eat)
                shake.pop_back();
        }
        gameArea.clearWin();
        move(food.get_x(), food.get_y());
        printw("*");
        shake.printShake();
        if (!shake.checkFrontCoordinates())
            break ;
        if (!shake.checkCoordinates(shake.get_shake().front()->get_x(), shake.get_shake().front()->get_y(), 1))
            break ;
        //usleep(100000);
    }
}

int main()
{
    WINDOW  *mainWin;
    WINDOW  *playWin;
    gameWin gameWindow(WIN_HEIGHT, WIN_WIDHT);
    gameWin gameArea(GAME_HEIGHT, GAME_WEIGHT);

    initscr();
    mainWin = gameWindow.createMainWin();
    playWin = gameArea.createGameArea(mainWin);

    curs_set(0);
    shakeGame(gameArea);

    delwin(mainWin);
    delwin(playWin);
    endwin();
    return (0);
}
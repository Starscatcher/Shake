#include "Shake.h"

//using namespace std;

Shake::Shake()
{
    for (int i = 0; i < START_SHAKE_LEN; ++i)
    {
        shake.push_back(new Pixel(GAME_HEIGHT/2, GAME_WEIGHT/2+i));
    }
    _i = shake.begin();
}

Shake::~Shake()
{

}

void    Shake::set_shake(std::list <Pixel*> newShake)
{
    shake = newShake;
}

std::list<Pixel*>    Shake::get_shake()
{
    return (shake);
}

void    Shake::pop_back()
{
    shake.pop_back();
}

void    Shake::push_front(int x, int y)
{
    shake.push_front(new Pixel(shake.front()->get_x() + x, shake.front()->get_y() + y));
}

int     Shake::checkFrontCoordinates()
{
    if (shake.front()->get_x() > 0 && shake.front()->get_x() < GAME_HEIGHT \
        && shake.front()->get_y()  > 0 && shake.front()->get_y() < GAME_WEIGHT)
        return (1);
    else
        return (0);
}

int     Shake::checkCoordinates(int x, int y, int from)
{
    for (_i = shake.begin(); _i != shake.end(); ++_i)
    {
        if (from)
        {
            ++_i;
            from = 0;
        }
        if ((*_i)->get_x() == x && (*_i)->get_y() == y)
            return (0);
    }
    return (1);
}

void    Shake::printShake()
{
    for (_i = shake.begin(); _i != shake.end(); _i++)
    {
        move((*_i)->get_x(), (*_i)->get_y());
        if (_i == shake.begin())
            printw("<");
        else
            printw("=");
        refresh();
    }
}

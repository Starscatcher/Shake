#include "Shake.h"

//using namespace std;
#include "Game.h"

Shake::Shake()
{
    _speed = START_SHAKE_SPEED;
    _countEaten = 0;
    _eaten = 0;
    for (int i = 0; i < START_SHAKE_LEN; ++i)
        _shake.push_back(new Pixel(GAME_HEIGHT/2, GAME_WIDTH/2+i));
}

void    Shake::setSpeed(unsigned long speed)
{
	_speed = speed;
}

unsigned long    Shake::getSpeed()
{
	return (_speed);
}

void    Shake::setCountEaten(unsigned int countEaten)
{
	_countEaten = countEaten;
}

unsigned int    Shake::getCountEaten()
{
	return (_countEaten);
}

Shake::~Shake()
{

}

void    Shake::setShake(std::list <Pixel*> newShake)
{
    _shake = newShake;
}

std::list<Pixel*>    Shake::getShake()
{
    return (_shake);
}

void    Shake::pop_back()
{
    _shake.pop_back();
}

void    Shake::push_front(int x, int y)
{
    _shake.push_front(new Pixel(_shake.front()->get_x() + x, _shake.front()->get_y() + y));
}

int     Shake::checkFrontCoordinates()
{
    if (_shake.front()->get_x() > 0 && _shake.front()->get_x() < GAME_HEIGHT \
        && _shake.front()->get_y() > 0 && _shake.front()->get_y() < GAME_WIDTH)
        return (1);
    else
        return (0);
}

int     Shake::checkCoordinates(int x, int y, int from)
{
	for (Pixel *pixel : _shake)
    {
        if (from)
        {
            from = 0;
			continue;
        }
        if (pixel->get_x() == x && pixel->get_y() == y)
            return (0);
    }
    return (1);
}

int		Shake::checkCollision()
{
	if (!checkFrontCoordinates())
		return (0);
	//if (!checkCoordinates(_shake.front()->get_x(), _shake.front()->get_y(), 0))
		//return (0);
}

void    Shake::moveUp()
{
    push_front(-1, 0);
    if (!_eaten)
        _shake.pop_back();
}

void    Shake::moveDown()
{
    push_front(1, 0);
    if (!_eaten)
        _shake.pop_back();
}

void    Shake::moveRight()
{
    push_front(0, 1);
    if (!_eaten)
        _shake.pop_back();
}

void    Shake::moveLeft()
{
    push_front(0, -1);
    if (!_eaten)
        _shake.pop_back();
}


bool    Shake::setEaten(bool eaten)
{
    _eaten = eaten;
    return (_eaten);
}

bool    Shake::getEaten()
{
    return (_eaten);
}
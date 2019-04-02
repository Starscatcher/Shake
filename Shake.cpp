#include "Shake.h"

Shake::Shake()
{
    _speed = 150;
    _countEaten = 0;
    _eaten = false;
    for (int i = 0; i < START_SHAKE_LEN; ++i)
        _shake.push_back(new Pixel(GAME_HEIGHT/2, GAME_WIDTH/2+i));
}

Shake::~Shake()
{

}


void    Shake::setSpeed(unsigned long speed)
{
	_speed = speed;
}

unsigned long    Shake::getSpeed()
{
	return (_speed);
}

void    Shake::setEaten(bool eaten)
{
	_eaten = eaten;
}

bool    Shake::getEaten()
{
	return (_eaten);
}

void    Shake::setCountEaten(unsigned int countEaten)
{
	_countEaten = countEaten;
}

unsigned int    Shake::getCountEaten()
{
	return (_countEaten);
}

void    Shake::setShake(std::list <Pixel*> newShake)
{
	_shake = newShake;
}

std::list<Pixel*>    Shake::getShake()
{
	return (_shake);
}

void    Shake::pushFront(int x, int y)
{
    _shake.push_front(new Pixel(_shake.front()->get_x() + x, _shake.front()->get_y() + y));
}

bool 		Shake::checkCollisionWithFood(int x, int y)
{
	if (_shake.front()->get_x() == x && _shake.front()->get_y() == y)
		return (true);
	else
		return (false);
}

bool     Shake::checkCollisionWithFrame()
{
    if (_shake.front()->get_x() > 0 && _shake.front()->get_x() < GAME_HEIGHT \
          && _shake.front()->get_y() > 0 && _shake.front()->get_y() < GAME_WIDTH)
        return (false);
    else
        return (true);
}

bool     Shake::checkCollisionWithShakeBody(int x, int y)
{
	int i = 0;

	for (Pixel *pixel : _shake)
    {
        if (!i)
            i++;
        else if (pixel->get_x() == x && pixel->get_y() == y)
            return (true);
    }
    return (false);
}

bool		Shake::checkCollision()
{
	if (checkCollisionWithFrame())
		return (true);
	else if (checkCollisionWithShakeBody(_shake.front()->get_x(), _shake.front()->get_y()))
		return (true);
	else
		return (false);
}

void 	Shake::eat()
{
	_eaten = true;
	_countEaten++;
	if (_countEaten % 5 == 0)
		_speed -= SPEED_INCREASE;
}

void    Shake::moveUp()
{
	pushFront(-1, 0);
	if (!_eaten)
		_shake.pop_back();
	_eaten = false;
}

void    Shake::moveDown()
{
	pushFront(1, 0);
	if (!_eaten)
		_shake.pop_back();
	_eaten = false;
}

void    Shake::moveRight()
{
	pushFront(0, 1);
	if (!_eaten)
		_shake.pop_back();
	_eaten = false;
}

void    Shake::moveLeft()
{
	pushFront(0, -1);
	if (!_eaten)
		_shake.pop_back();
	_eaten = false;
}

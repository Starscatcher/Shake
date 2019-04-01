#include "pixel.h"
#include <ncurses.h>
#include <cstdlib>
#include "Shake.h"
#include "Game.h"

Pixel::Pixel(int x, int y) : _x(x), _y(y)
{

}

Pixel::~Pixel()
{

}

void Pixel::setBody(char	body)
{
	_body = body;
}

char Pixel::getBody()
{
	return (_body);
}


void Pixel::set_x(int x)
{
    _x = x;
}

void Pixel::set_y(int y)
{
    _y = y;
}

int Pixel::get_y()
{
    return (this->_y);
}

int Pixel::get_x()
{
    return (this->_x);
}

bool 		Pixel::checkFoodColision(Shake shake)
{
	if (!shake.checkCoordinates(get_x(), get_y(), 0) || \
		get_x() < 0 && get_x() > GAME_HEIGHT && get_y() < 0 && get_y() > GAME_WEIGHT)
		return (true);
	return (false);
}

bool     Pixel::generateFood(Shake shake)
{
	if (shake.getShake().front()->get_x() == get_x() && shake.getShake().front()->get_y() == get_y())
	{
		while (checkFoodColision(shake))
		{
			set_x(std::rand() % GAME_HEIGHT + 1);
			set_y(std::rand() % GAME_WEIGHT + 1);
		}
		shake.setCountEaten(shake.getCountEaten() + 1);
		if (!shake.getCountEaten() % 5)
			shake.setSpeed(shake.getSpeed() - SPEED_INCREASE);
		return (true);
	}
	else
		return (false);
}

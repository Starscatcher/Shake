#include "Pixel.h"

Pixel::Pixel(int x, int y)
{
	_x = x;
	_y = y;
}

Pixel::~Pixel()
{

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
	for (Pixel *pixel : shake.getShake())
	{
		if (pixel->get_x() == get_x() && pixel->get_y() == get_y())
			return (true);
	}
	if (get_x() <= 0 && get_x() >= GAME_HEIGHT && get_y() <= 0 && get_y() >= GAME_WIDTH)
		return (true);
	else
		return (false);
}

void     Pixel::generateFood(Shake shake)
{
	while (checkFoodColision(shake))
	{
		set_x(std::rand() % GAME_HEIGHT);
		set_y(std::rand() % GAME_WIDTH);
	}
}

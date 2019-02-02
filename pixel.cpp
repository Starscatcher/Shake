#include "pixel.h"

Pixel::Pixel(int x, int y) : _x(x), _y(y)
{

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
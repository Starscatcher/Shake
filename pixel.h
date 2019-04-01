#ifndef PIXEL_H
#define PIXEL_H

#include "Shake.h"

class Shake;

class Pixel
{
private:
	int _x;
	int _y;
	char _body;

public:
    Pixel(int x, int y);
	~Pixel();

    int		get_x();
    int		get_y();
    void	set_x(int x);
    void	set_y(int y);
	void setBody(char	body);
	char getBody();

	bool	generateFood(Shake shake);
	bool  	checkFoodColision(Shake shake);
};

#endif

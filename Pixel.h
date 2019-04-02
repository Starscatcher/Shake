#ifndef PIXEL_H
#define PIXEL_H

#include <cstdlib>

#include "Shake.h"

#include "GameConstants.h"


class Shake;

class Pixel
{
	private:
		int _x;
		int _y;

	public:
		Pixel(int x, int y);
		~Pixel();

    	int		get_x();
    	int		get_y();
    	void	set_x(int x);
    	void	set_y(int y);


		void	generateFood(Shake shake);
		bool  	checkFoodColision(Shake shake);
};

#endif

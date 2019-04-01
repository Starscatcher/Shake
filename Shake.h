#ifndef SHAKE_H
#define SHAKE_H

#include <list>
#include <ncurses.h>
#include "pixel.h"
#include "constant.h"

class Pixel;

class Shake
{
    private:
		std::list <Pixel*> 				_shake;
		bool                       		_eaten;
		unsigned long					_speed;
		unsigned int 					_countEaten;

    public:
        Shake();
        ~Shake();

		int		checkCollision();
        int     checkFrontCoordinates();
        int     checkCoordinates(int x, int y, int from);


        void    push_front(int x, int y);
		void    pop_back();

        void    setShake(std::list <Pixel*> newShake);
		std::list<Pixel*>    getShake();
		bool    setEaten(bool val);
		bool    getEaten();
		void    setSpeed(unsigned long speed);
		unsigned long    getSpeed();
		void    setCountEaten(unsigned int countEaten);
		unsigned int    getCountEaten();

        void    moveUp();
        void    moveDown();
        void    moveRight();
        void    moveLeft();
};

#endif

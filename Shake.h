#ifndef SHAKE_H
#define SHAKE_H

#include <list>
#include <ncurses.h>

#include "GameConstants.h"

#include "Pixel.h"

class Pixel;

class Shake
{
    private:
		std::list <Pixel*>	_shake;
		bool                _eaten;
		unsigned long		_speed;
		unsigned int		_countEaten;

    public:
        Shake();
        ~Shake();

		bool	checkCollision();
        bool	checkCollisionWithFrame();
        bool	checkCollisionWithShakeBody(int x, int y);
		bool 	checkCollisionWithFood(int x, int y);

        void				setShake(std::list <Pixel*> newShake);
		std::list<Pixel*>	getShake();
		void				setEaten(bool val);
		bool				getEaten();
		void				setSpeed(unsigned long speed);
		unsigned long		getSpeed();
		void				setCountEaten(unsigned int countEaten);
		unsigned int		getCountEaten();

        void    moveUp();
        void    moveDown();
        void    moveRight();
        void    moveLeft();
        void 	eat();

		void    pushFront(int x, int y);
};

#endif

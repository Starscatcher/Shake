#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "Shake.h"
#include "Pixel.h"

#include "GameConstants.h"


class Shake;
class Pixel;

class Graphic {

public:

	Graphic(){}

	virtual void    drawFrame(int height, int width) = 0;
	virtual void    clearWin() = 0;
	virtual void	createGameArea() = 0;
	virtual void	createMainWin() = 0;
	virtual void    printShake(Shake Shake) = 0;
	virtual void    printFood(Pixel Food) = 0;
	virtual void    printMenu(unsigned int score) = 0;
	virtual void    changeHeadDirection(int direction) = 0;
	virtual ~Graphic(void) {}

};


#endif

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "Shake.h"
#include "pixel.h"
#include "ncurses.h"

class Graphic {

public:

	virtual void    drawFrame();
	virtual void    clearWin();
	virtual void	createGameArea();
	virtual void	createMainWin();
	virtual void    printShake(Shake shake);
	virtual void    printFood(Pixel Food);
	virtual void    changeHeadDirection(int direction);
	virtual ~Graphic(void) {}

};


#endif

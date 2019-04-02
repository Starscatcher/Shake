#ifndef GAME_H
#define GAME_H


#include "random"
#include "iostream"
#include "unistd.h"

#include "Ncurses.h"
#include "Graphic.h"
#include "Pixel.h"
#include "Shake.h"

#include "GameConstants.h"

class Game {
private:
	unsigned int	_score;

public:
	Game();
	~Game();
	void    start();
	void 	pause();

};

#endif

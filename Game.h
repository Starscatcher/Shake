#ifndef GAME_H
#define GAME_H

#define WIN_HEIGHT 40
#define WIN_WIDTH 125

#define GAME_HEIGHT 40
#define GAME_WIDTH 90

#define START_SHAKE_SPEED 100000

#define SPEED_INCREASE 100000

#define SCORE_INCREASE 10


#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68
#define PAUSE 'p'
#define RESUME 32
#define EXIT 'q'


#include "ncurses.h"
#include "gameWin.h"
#include "pixel.h"
#include "Shake.h"
#include "random"
#include "iostream"
#include "unistd.h"
#include "Ncurses.h"
#include "Graphic.h"

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

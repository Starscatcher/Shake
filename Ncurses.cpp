#include "Ncurses.h"

Ncurses::Ncurses()
{
	initscr();
	createMainWin();
	createGameArea();
	curs_set(0);
	_head = '<';
	_food = '*';
}

Ncurses::~Ncurses()
{
	delwin(mainWin);
	delwin(playWin);
	endwin();
}




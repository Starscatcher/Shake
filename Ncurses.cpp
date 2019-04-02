#include "Ncurses.h"

Ncurses::Ncurses()
{
	initscr();
	createMainWin();
	createGameArea();
	curs_set(0);
	_head = '<';
	_food = '*';
	_body = 'o';
}

Ncurses::~Ncurses()
{
	delwin(mainWin);
	delwin(playWin);
	endwin();
}

#ifndef NCURSES_H
#define NCURSES_H

#include "Graphic.h"
#include <ncurses.h>
#include "Game.h"
#include "Shake.h"


class Ncurses : public Graphic {

private:
	char 	_head;
	char	_food;

public:
	WINDOW  *mainWin;
	WINDOW  *playWin;


	Ncurses();
	~Ncurses();


	void    drawFrame() override
	{
		int x = 0;
		int y = 0;

		while (x < GAME_HEIGHT)
		{
			move(x, 0);
			printw("#");
			refresh();
			move(x, GAME_WIDTH);
			printw("#");
			refresh();
			x++;
		}
		while (y < GAME_WIDTH)
		{
			move(0, y);
			printw("#");
			refresh();
			move(GAME_HEIGHT, y);
			printw("#");
			refresh();
			y++;
		}
	}

	void    clearWin() override
	{
		int x = 1;

		while (x != GAME_HEIGHT)
		{
			int y = 1;
			while (y != GAME_WEIGHT)
			{
				move(x, y);
				printw(" ");
				y++;
			}
			x++;
		}
	}

	void	createGameArea() override
	{
		playWin = subwin(mainWin, GAME_HEIGHT, GAME_WIDTH, 0, 0);
		drawFrame();
	}

	void	createMainWin() override
	{
		mainWin = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
		drawFrame();
	}

	void	printShake(Shake shake) override
	{
		std::list <Pixel*>::iterator	_i;

		for (_i = shake.getShake().begin(); _i != shake.getShake().end(); _i++)
		{
			move((*_i)->get_x(), (*_i)->get_y());
			if (_i == shake.getShake().begin())
				printw("%c", _head);
			else
				printw("=");
			refresh();
		}
	}

	void    printFood(Pixel Food) override
	{
		move(Food.get_x(), Food.get_y());
		printw("%c", _food);
	}

	void    changeHeadDirection(int direction) override {
		if (direction == UP)
			this->_head = '^';
		else if (direction == DOWN)
			this->_head = 'o';
		else if (direction == RIGHT)
			this->_head = '>';
		else if (direction == LEFT)
			this->_head = '<';
	}
};

#endif

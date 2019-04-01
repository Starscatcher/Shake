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
	char	_body;

public:
	WINDOW  *mainWin;
	WINDOW  *playWin;

	Ncurses();
	~Ncurses();

	void    drawFrame(int height, int width) override
	{
		int x = 0;
		int y = 0;

		while (x < height)
		{
			move(x, 0);
			printw("#");
			refresh();
			move(x, width);
			printw("#");
			refresh();
			x++;
		}
		while (y <= width)
		{
			move(0, y);
			printw("#");
			refresh();
			move(height, y);
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
			while (y != GAME_WIDTH)
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
		drawFrame(GAME_HEIGHT, GAME_WIDTH);
	}

	void	createMainWin() override
	{
		mainWin = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
		drawFrame(WIN_HEIGHT, WIN_WIDTH);
	}

	void	printShake(Shake shake) override
	{
		int j = 0;

		for (Pixel *pixel: shake.getShake()) {
			if (j == 0)
			{
				move(pixel->get_x(), pixel->get_y() );
				printw("%c", _head);
				refresh();
				j++;
			}
			else {
				move(pixel->get_x(), pixel->get_y());
				printw("%c", _body);
				refresh();
			}
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

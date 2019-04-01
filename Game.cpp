#include "Game.h"

Game::Game()
{
	_score = 0;
}

Game::~Game()
{}


void 	Game::pause()
{
	while (getch() != RESUME)
		;
}

void    Game::start()
{
	Pixel 	Food(5, 5);
	Shake	Shake;
	int 	key = 0;
	int 	temp = 0;
	Ncurses Ncurses;

	std::srand(clock());
	nodelay(stdscr, TRUE); // for getch

	long k = 0;
	while (1)
	{
		if (Shake.setEaten(Food.generateFood(Shake)))
			_score += SCORE_INCREASE;

		move(5, 100);
		printw("%d", _score);

		Ncurses.clearWin();
		Ncurses.printFood(Food);
		Ncurses.printShake(Shake);

		if ((key = getch()) == ERR)
			key = temp;
		if (key != PAUSE)
			temp = key;
		if (k % 50 == 0) {
			if (key == UP) {
				Shake.moveUp();
				Ncurses.changeHeadDirection(UP);
			} else if (key == DOWN) {
				Shake.moveDown();
				Ncurses.changeHeadDirection(DOWN);
			} else if (key == RIGHT) {
				Shake.moveRight();
				Ncurses.changeHeadDirection(RIGHT);
			} else if (key == LEFT) {
				Shake.moveLeft();
				Ncurses.changeHeadDirection(LEFT);
			} else if (key == PAUSE) {
				pause();
				key = temp;
			}
		}
		k++;
		if (!Shake.checkCollision())
			break;
		usleep(START_SHAKE_SPEED);
	}
}

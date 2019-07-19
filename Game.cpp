#include "Game.h"

Game::Game() {
	_score = 0;
}

Game::~Game()
{}

void 	Game::pause() {
	while (getch() != RESUME)
		;
}

void    Game::start() {
	Pixel 	Food(5, 5);
	Shake	Shake;
	int 	key = LEFT;
	int 	temp = LEFT;
	Ncurses Ncurses;

	std::srand(clock());
	nodelay(stdscr, TRUE); // for getch

	long k = 0;
	while (key != EXIT) {
		if (Shake.checkCollisionWithFood(Food.get_x(), Food.get_y())) {
			_score += SCORE_INCREASE;
			Shake.eat();
			Food.generateFood(Shake);
		}
		Ncurses.clearWin();
		Ncurses.printFood(Food);
		Ncurses.printShake(Shake);
		Ncurses.printMenu(_score);

		if ((key = getch()) == ERR)
			key = temp;
		if (key != PAUSE)
			temp = key;
		if (k % Shake.getSpeed() == 0) {
			if (key == UP) {
				Shake.moveUp();
				Ncurses.changeHeadDirection(UP);
			}
			else if (key == DOWN) {
				Shake.moveDown();
				Ncurses.changeHeadDirection(DOWN);
			}
			else if (key == RIGHT) {
				Shake.moveRight();
				Ncurses.changeHeadDirection(RIGHT);
			}
			else if (key == LEFT) {
				Shake.moveLeft();
				Ncurses.changeHeadDirection(LEFT);
			}
			else if (key == PAUSE) {
				pause();
				key = temp;
			}
		}
		k++;
		if (Shake.checkCollision())
			break;
		usleep(START_SHAKE_SPEED);
	}
}

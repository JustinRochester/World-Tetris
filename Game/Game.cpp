#include"Game.h"
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<cstdlib>

const char Game::UP = 72;
const char Game::LEFT = 75;
const char Game::RIGHT = 77;
const char Game::DOWN = 80;
const char Game::DIRECTIONS = 224;
const char Game::ESC = 0x1b;

void Game::carryCommand(char c) {
	/*
	This method is used to carry the correct command 'c'.
	Surely, it won't work if the command is not defined.
	*/
	if (c == Game::DIRECTIONS)
		c = _getch();
	if (0);
	/*
	It is setted just make the code more symmetrical.
	*/
	else if (c == UP || c == 'W' || c == 'w') {
		/*
		It will act on the first player if there are one player, or the command isn't direction key "up".
		The same to the next.
		*/
		if (CountPlayer == 1||c!=UP)
			player[0].run(Brick::Rotate);
		else
			player[1].run(Brick::Rotate);
	}
	else if (c == DOWN || c == 'S' || c == 's') {
		if (CountPlayer == 1 || c != DOWN)
			player[0].run(Brick::Down);
		else
			player[1].run(Brick::Down);
	}
	else if (c == LEFT || c == 'A' || c == 'a') {
		if (CountPlayer == 1 || c != LEFT)
			player[0].run(Brick::Left);
		else
			player[1].run(Brick::Left);
	}
	else if (c == RIGHT || c == 'D' || c == 'd') {
		if (CountPlayer == 1 || c != RIGHT)
			player[0].run(Brick::Right);
		else
			player[1].run(Brick::Right);
	}
}

void Game::play() {
	/*
	This method is used to carry the World-Teris game circularly.
	*/
	int FramesLimit=100;
	/*
	Number FramesLimit is setted as the limits of FramesCount.
	It will make the bricks fall down 1 cell, if the FramesCount is not less than it.
	*/
	player[0].setName("player1");
	player[1].setName("player2");
	for (clock_t last = clock(), now = last;; now = clock()) {
		if (_kbhit()) {
			clock_t StartTime = clock(), EndTime;
			carryCommand(_getch());
			EndTime = clock();
			Sleep(FramesTime - (StartTime - EndTime));
		}
		else {
			Sleep(FramesLimit);
		}
		FramesCount++;

		if (FramesCount >= FramesLimit) {
			/*
			It is time to make the bricks fall down.
			*/
			player[0].run(0);
			if(CountPlayer==2)
				player[1].run(0);
			FramesCount -= FramesLimit;
			if (player[0].IsGameOver() && player[1].IsGameOver())
				break;
		}
		/*
		To render the map.
		*/
	}
}
void Game::run() {
	welcome();
	while (1) {
		setGameMode();
		play();
		if (_getch() == ESC)
			break;
	}
}
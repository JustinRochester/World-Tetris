#include"Game.h"
#include"Player.h"
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include<iostream>

int Game::FramesCount = 0;
int Game::FramesTime = 100;

const char Game::UP = 72;
const char Game::LEFT = 75;
const char Game::RIGHT = 77;
const char Game::DOWN = 80;
const char Game::DIRECTIONS = 224;
const char Game::ESC = 27;
const char Game::ENTER = 13;

Game::~Game() {
	for (int i = 0; i < 2; i++)
		if (player[i] != NULL) {
			delete player[i];
			player[i] = NULL;
		}
}

Game::Game() {
	player[0] = player[1] = NULL;
	CountPlayer = 0;
	GameMode = 0;
}

void Game::welcome() {
	puts("welcome!");
}

void Game::renderMap() {
	char Map[32][12] = { 0 };
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= 10; j++)
			if (player[0]->MapSqure[i][j])
				Map[i][j] = 'o';
	const int* Pnt = player[0]->NowBrick.getInformation();
	for (int i = 1; i < 9; i += 2)
		Map[Pnt[i]][Pnt[i + 1]] = '*';

	system("cls");
	for (int i = 11; i <= 30; i++) {
		putchar('|');
		for (int j = 1; j <= 10; j++)
			putchar(Map[i][j]);
		putchar('|');
		putchar('\n');
	}
	putchar(0);
	for (int j = 1; j <= 10; j++)
		putchar('-');
	putchar(0);
	putchar('\n');
}

void Game::setGameMode() {
	system("cls");
	puts("Push the key how many people plays the game.");

	for (int i = 0; i < 2; i++)
		if (player[i] != NULL) {
			delete player[i];
			player[i] = NULL;
		}
	char c = _getch();
	while (1) {
		while (c < '1' || c>'2') c = _getch();
		if (c >= '1' && c <= '2') GameMode = c - '0';
		break;
	}
	CountPlayer = c - '0';

	for (int i = 0; i < 2; i++)
		if (i < CountPlayer)
			player[i] = new Player(1);
		else
			player[i] = new Player(0);
}

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
			player[0]->run(Brick::Rotate);
		else
			player[1]->run(Brick::Rotate);
	}
	else if (c == DOWN || c == 'S' || c == 's') {
		if (CountPlayer == 1 || c != DOWN)
			player[0]->run(Brick::Down);
		else
			player[1]->run(Brick::Down);
	}
	else if (c == LEFT || c == 'A' || c == 'a') {
		if (CountPlayer == 1 || c != LEFT)
			player[0]->run(Brick::Left);
		else
			player[1]->run(Brick::Left);
	}
	else if (c == RIGHT || c == 'D' || c == 'd') {
		if (CountPlayer == 1 || c != RIGHT)
			player[0]->run(Brick::Right);
		else
			player[1]->run(Brick::Right);
	}
}

void Game::play() {
	/*
	This method is used to carry the World-Teris game circularly.
	*/
	int FramesLimit=10;
	/*
	Number FramesLimit is setted as the limits of FramesCount.
	It will make the bricks fall down 1 cell, if the FramesCount is not less than it.
	*/
	player[0]->setName("player1");
	player[1]->setName("player2");
	renderMap();
	for (clock_t last = clock(), now = last;; now = clock()) {
		if (_kbhit()) {
			clock_t LastTime = clock();
			carryCommand(_getch());
			LastTime = clock()-LastTime;
			if(Game::FramesTime>LastTime)
				Sleep(Game::FramesTime - LastTime);
		}
		else {
			Sleep(Game::FramesTime);
		}
		Game::FramesCount++;

		if (Game::FramesCount >= FramesLimit) {
			/*
			It is time to make the bricks fall down.
			*/
			player[0]->run(0);
			if(CountPlayer==2)
				player[1]->run(0);
			Game::FramesCount -= FramesLimit;
		}
		if (player[0]->IsGameOver() && player[1]->IsGameOver())
			break;
		renderMap();
		/*
		To render the map.
		*/
	}

	system("cls");
	std::cout << "Game over."<<std::endl;
	for (int i = 0; i < CountPlayer; i++)
		std::cout << "\tPlayer: " << player[i]->getName() << " get scores " << player[i]->getScore() << std::endl;
	std::cout<<"Push key enter to continue, and key ESC to escape."<<std::endl;
}
void Game::run() {
	welcome();
	while (1) {
		setGameMode();
		play();
		char c;
		while (1) {
			c = _getch();
			if (c == ESC || c == ENTER)
				break;
		}
		if (c == ESC)
			break;
	}
}
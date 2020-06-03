#include"Game.h"
#include"Player.h"
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include<iostream>

int Game::FramesCount = 0;
int Game::FramesTime = 25;

const char Game::UP = 72;
const char Game::LEFT = 75;
const char Game::RIGHT = 77;
const char Game::DOWN = 80;
const char Game::DIRECTIONS = 224;
const char Game::ESC = 27;
const char Game::ENTER = 13;

Game::Game() {
	render.HideCursor();
	render.SetTitle();
	player[0] = player[1] = NULL;
	CountPlayer = 0;
	GameMode = 0;
}

Game::~Game() {
	for (int i = 0; i < 2; i++)
		if (player[i] != NULL) {
			delete player[i];
			player[i] = NULL;
		}
}

void Game::helpText() {
	int Cur = 0;
	while (1) {
		render.helpText(GameMode);
		char c = _getch();
		if (c == ESC || c == ENTER)
			return;
	}
}

void Game::explain() {
	int Cur = 0;
	while (1) {
		render.Explain();
		char c = _getch();
		if (c == ESC || c == ENTER)
			return;
	}
}

void Game::participants() {
	int Cur = 0;
	while (1) {
		render.Participants();
		char c = _getch();
		if (c == ESC || c == ENTER)
			return;
	}
}

bool Game::welcome() {
	int Cur = 0;
	while (1) {
		render.Welcome(Cur);
		char c = _getch();
		if (c == ESC)
			return 0;
		if (c == ENTER) {
			if (0);
			else if (Cur == 0)
				return 1;
			else if (Cur == 1)
				explain();
			else if (Cur == 2)
				participants();
			else if (Cur == 3)
				return 0;
		}
		moveCur(Cur,c);
		Cur = (Cur % 4 + 4) % 4;
	}
}

void Game::renderMap() {
	if (CountPlayer == 1) {
		int Map[32][12] = { 0 }, Infor[9] = { 0 };
		for (int* NextState = player[0]->NextBrick.getInformation(), i = 0; i < 9; i++, NextState++)
			Infor[i] = *NextState;
		const int* Pnt = player[0]->NowBrick.getInformation();
		if (!player[0]->GameOver) {
			for (int i = 1; i <= 30; i++)
				for (int j = 1; j <= 10; j++)
					if (player[0]->MapSqure[i][j])
						Map[i][j] = -1;
			for (int i = 1; i < 9; i += 2)
				Map[Pnt[i]][Pnt[i + 1]] = 1;
		}
		else
			Infor[0] = 5;

		render.DrawMap1(player[0]->CountScore);
		render.DrawGame1(Map, Pnt[0], Infor);
		return;
	}
	if (CountPlayer == 2) {
		int Map1[32][12] = { 0 }, Infor1[9] = { 0 };
		for (int* NextState = player[0]->NextBrick.getInformation(), i = 0; i < 9; i++, NextState++)
			Infor1[i] = *NextState;
		const int* Pnt = player[0]->NowBrick.getInformation();
		if (!player[0]->GameOver) {
			for (int i = 1; i <= 30; i++)
				for (int j = 1; j <= 10; j++)
					if (player[0]->MapSqure[i][j])
						Map1[i][j] = -1;
			for (int i = 1; i < 9; i += 2)
				Map1[Pnt[i]][Pnt[i + 1]] = Pnt[0];
		}
		else
			Infor1[0] = 10;


		int Map2[32][12] = { 0 }, Infor2[9] = { 0 };
		for (int* NextState = player[1]->NextBrick.getInformation(), i = 0; i < 9; i++, NextState++)
			Infor2[i] = *NextState;
		Pnt = player[1]->NowBrick.getInformation();
		if (!player[1]->GameOver) {
			for (int i = 1; i <= 30; i++)
				for (int j = 1; j <= 10; j++)
					if (player[1]->MapSqure[i][j])
						Map2[i][j] = -1;
			for (int i = 1; i < 9; i += 2)
				Map2[Pnt[i]][Pnt[i + 1]] = Pnt[0];
		}
		else
			Infor2[0] = 10;

		render.DrawMap2(player[0]->getScore(), player[1]->getScore());
		render.DrawGame2(Map1, Infor1, Map2, Infor2);
		return;
	}
}

void Game::moveCur(int& NowCur, char Command) {
	if (0);
	else if (Command >= '0' && Command <= '9')
		NowCur = (Command - 48);
	else if (Command == '-' || Command == 'W' || Command == 'w')
		NowCur--;
	else if (Command == '+' || Command == 'S' || Command == 's')
		NowCur++;
	else if (Command == DIRECTIONS) {
		Command = _getch();
		if (Command == UP)
			NowCur--;
		else if (Command == DOWN)
			NowCur++;
	}
}

void Game::setGameMode(int Cur) {

	for (int i = 0; i < 2; i++)
		if (player[i] != NULL) {
			delete player[i];
			player[i] = NULL;
		}
	CountPlayer = 0;

	if (Cur < 0) {
		Cur = 0;
		while (1) {
			render.GameModeMenu(Cur);

			char c = _getch();
			if (c == ESC)
				return;
			if (c == ENTER)
				break;
			moveCur(Cur, c);
			Cur = (Cur % 10 + 10) % 10;
		}
	}
	CountPlayer = (Cur > 3) + 1;
	GameMode = Cur;

	for (int i = 0; i < 2; i++)
		if (i < CountPlayer)
			player[i] = new Player(1);
		else
			player[i] = new Player(0);
}

void Game::addOtherLines(int DeleteLinePlayer, int CountDeletedLine) {
	/*
	This method is work only in gamemode 8 or gamemode 9
	It will add CountDeletedLine to player AddLinePlayer
	*/
	if (GameMode != 8 && GameMode != 9)
		return;
	int AddLinePlayer = DeleteLinePlayer ^ 1;
	while (CountDeletedLine) {
		CountDeletedLine = player[AddLinePlayer]->addLine(CountDeletedLine);
		AddLinePlayer ^= 1;
	}
}

void Game::carryCommand(char c) {
	static int Turn = 0;
	/*
	This method is used to carry the correct command 'c'.
	Surely, it won't work if the command is not defined.
	*/
	if (c == Game::DIRECTIONS)
		c = _getch();
	int CountDeleteLines;
	if (0);
	/*
	It is setted just make the code more symmetrical.
	*/
	else if (c == 0) {
		CountDeleteLines = player[Turn]->run(0);
		addOtherLines(Turn, CountDeleteLines);
		Turn ^= 1;
		CountDeleteLines = player[Turn]->run(0);
		addOtherLines(Turn, CountDeleteLines);
	}
	else if (c == UP || c == 'W' || c == 'w') {
		/*
		It will act on the first player if there are one player, or the command isn't direction key "up".
		The same to the next.
		*/
		if (CountPlayer == 1 || c != UP) {
			CountDeleteLines = player[0]->run(Brick::Rotate);
			addOtherLines(0, CountDeleteLines);
		}
		else {
			CountDeleteLines = player[1]->run(Brick::Rotate);
			addOtherLines(1, CountDeleteLines);
		}
		/*
		It will add CountDeleteLines to others if the player remove CountDeleteLines lines in GameMode 8 or 9.
		The same to the next.
		*/
	}
	else if (c == DOWN || c == 'S' || c == 's') {
		if (CountPlayer == 1 || c != DOWN) {
			CountDeleteLines = player[0]->run(Brick::Down);
			addOtherLines(0, CountDeleteLines);
		}
		else {
			CountDeleteLines = player[1]->run(Brick::Down);
			addOtherLines(1, CountDeleteLines);
		}
	}
	else if (c == LEFT || c == 'A' || c == 'a') {
		if (CountPlayer == 1 || c != LEFT) {
			CountDeleteLines = player[0]->run(Brick::Left);
			addOtherLines(0, CountDeleteLines);
		}
		else {
			CountDeleteLines = player[1]->run(Brick::Left);
			addOtherLines(1, CountDeleteLines);
		}
	}
	else if (c == RIGHT || c == 'D' || c == 'd') {
		if (CountPlayer == 1 || c != RIGHT) {
			CountDeleteLines = player[0]->run(Brick::Right);
			addOtherLines(0, CountDeleteLines);
		}
		else {
			CountDeleteLines = player[1]->run(Brick::Right);
			addOtherLines(1, CountDeleteLines);
		}
	}
}

int Game::play() {
	/*
	This method is used to carry the World-Teris game circularly.
	It will return that whether the game is started.
	*/

	int Cur = 0;
	while (1) {
		render.PreStart(Cur);
		char c = _getch();
		if (c == ESC) 
			return 1;
		if (c == ENTER) {
			if (0);
			else if (Cur == 0)
				break;
			else if (Cur == 1) {
				helpText();
				continue;
			}
			else if (Cur == 2)
				return 1;
			else if (Cur == 3)
				return 3;
		}
		else {
			moveCur(Cur, c);
			Cur = (Cur % 4 + 4) % 4;
		}
	}

	system("cls");
	int FramesLimit = 1000 / FramesTime;
	/*
	Number FramesLimit is setted as the limits of FramesCount.
	It will make the bricks fall down 1 cell, if the FramesCount is not less than it.
	*/
	player[0]->setName("Íæ¼Ò1");
	player[1]->setName("Íæ¼Ò2");
	renderMap();
	for (clock_t last = clock(), now = last;; now = clock()) {
		if (_kbhit()) {
			clock_t LastTime = clock();
			char c = _getch();
			if (c == ESC)
				break;
			carryCommand(c);
			renderMap();
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
			carryCommand(0);
			Game::FramesCount -= FramesLimit;

			if (GameMode == 1 || GameMode == 3 || GameMode == 5 || GameMode == 7)
				for (int i = 0; i < CountPlayer; i++)
					if (rand() % 100) continue;
					else {
						int CountAddLines = rand() % 10;
						if (0);
						else if (CountAddLines < 1) CountAddLines = 4;
						else if (CountAddLines < 3) CountAddLines = 3;
						else if (CountAddLines < 6) CountAddLines = 2;
						else if (CountAddLines < 10) CountAddLines = 1;

						player[i]->addLine(CountAddLines);
					}

			renderMap();
		}

		if (GameMode == 2 || GameMode == 3 || GameMode == 6 || GameMode == 7 || GameMode == 9) {
			FramesLimit = 1000 / FramesTime - (player[0]->getScore() + player[1]->getScore()) / 10;
			if (FramesLimit < 1)
				FramesLimit = 1;
		}

		if (player[0]->IsGameOver() && player[1]->IsGameOver())
			break;
		/*
		To render the map.
		*/
	}

	render.SetColor(5);
	Cur = 0;
	while (1) {
		render.End(Cur, CountPlayer, player[0]->getName(), player[0]->getScore(), player[1]->getName(), player[1]->getScore());
		char c = _getch();
		if (c == ESC)
			return 1;
		if (c == ENTER)
			return Cur;
		moveCur(Cur, c);
		Cur = (Cur % 4 + 4) % 4;
	}
}
void Game::run() {
	while (1) {
		if (!welcome())
			return;
		render.SetColor(5);
		while (1) {
			setGameMode(-1);
			if (CountPlayer == 0)
				break;
			int Res = 0;
			while (Res == 0) {
				setGameMode(GameMode);
				Res = play();
			}
			if (Res == 1)
				continue;
			if (Res == 2)
				break;
			if (Res == 3)
				return;
		}
	}
}
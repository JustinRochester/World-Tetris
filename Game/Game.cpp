#include"Game.h"
#include"Player.h"
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include<iostream>

int Game::FramesTime = 25;

const char Game::UP = 72;
const char Game::LEFT = 75;
const char Game::RIGHT = 77;
const char Game::DOWN = 80;
const char Game::DIRECTIONS = 224;
const char Game::ESC = 27;
const char Game::ENTER = 13;
const char Game::BACKSPACE = 8;

Game::Game() {
	FramesCount = 0;
	OperationMode = fileRecoder.OperationMode;
	render.HideCursor();
	render.SetTitle();
	player[0] = player[1] = NULL;
	CountPlayer = 0;
	GameMode = 0;
}

Game::~Game() {
	fileRecoder.OperationMode = OperationMode;
	for (int i = 0; i < 2; i++)
		if (player[i] != NULL) {
			delete player[i];
			player[i] = NULL;
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
				reName();
			else if (Cur == 2)
				explain();
			else if (Cur == 3)
				participants();
			else if (Cur == 4) {
				Setting();
				fileRecoder.OperationMode = OperationMode;
				fileRecoder.outputData();
			}
			else if (Cur == 5)
				return 0;
		}
		moveCur(Cur, c);
		Cur = (Cur % 6 + 6) % 6;
	}
}

void Game::historicRecord() {
	int Cur = 0;
	while (1) {
		int Score = fileRecoder.ScoreRecoder[GameMode];
		if (Score < 0) Score = 0;
		render.historicRecord(fileRecoder.NameRecoder[GameMode], Score, Cur);
		char c = _getch();
		if (0);
		else if (c == ESC)
			return;
		else if (c == ENTER) {
			if (0);
			else if (Cur == 0) return;
			else if (Cur == 1) fileRecoder.clearRecord(GameMode);
		}
		else {
			moveCur(Cur, c);
			Cur = (Cur % 2 + 2) % 2;
		}
	}
}

void Game::Setting() {
	static int CountProperties = 1;
	bool Properties[] = { OperationMode };
	int Cur = 0;
	while (1) {
		render.Setting(Cur, Properties, CountProperties);
		char c = _getch();
		if (c == ESC) {
			OperationMode = ((Properties[0]) ? 1 : 0);
			return;
		}
		if (c == ENTER) {
			if (Cur == CountProperties) {
				OperationMode = ((Properties[0]) ? 1 : 0);
				return;
			}
			Properties[Cur] ^= 1;
		}
		moveCur(Cur, c);
		Cur = (Cur % 2 + 2) % 2;
	}
}

void Game::reName(int ID) {
	std::string tmp="";
	bool isTooLong = 0;
	while (1) {
		if(!isTooLong)
			render.reName(fileRecoder.NamePlayer[ID], tmp);
		else {
			render.reName(fileRecoder.NamePlayer[ID], "(Ãû×Ö¹ý³¤)");
			isTooLong = 0;
		}
		char c = _getch();
		if (0);
		else if (c == DIRECTIONS) {
			c = _getch();
			if (c == UP)
				tmp = fileRecoder.NamePlayer[ID];
		}
		else if (c == ESC)
			return;
		else if (c == ENTER) {
			if (tmp.size() < 16)
				fileRecoder.NamePlayer[ID] = tmp;
			else
				isTooLong = 1;
			tmp = "";
		}
		else if (c == BACKSPACE) {
			if(tmp.size())
				tmp.pop_back();
		}
		else if (isalnum(c))
			tmp += c;
	}
}

void Game::reName() {
	int Cur = 0;
	while (1) {
		render.reName(fileRecoder.NamePlayer[0], fileRecoder.NamePlayer[1], Cur);
		char c = _getch();
		if (0);
		else if (c == ESC)
			return;
		else if (c == ENTER) {
			if (Cur == 2)
				return;
			reName(Cur);
		}
		else {
			moveCur(Cur, c);
			Cur = (Cur % 3 + 3) % 3;
		}
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

void Game::renderMap() {
	/*
	This method is used to draw the game map.
	*/
	int Map[2][32][12] = { 0 }, Infor1[2][9] = { 0 }, Infor2[2][9] = { 0 };
	if (CountPlayer == 0)
		return;
	for (int p = 0; p < CountPlayer; p++) {
		for (int* NowState = player[p]->NowBrick.getInformation(), i = 0; i < 9; i++, NowState++)
			Infor1[p][i] = *NowState;
		for (int* NextState = player[p]->NextBrick.getInformation(), i = 0; i < 9; i++, NextState++)
			Infor2[p][i] = *NextState;

		if (player[p]->GameOver) {
			Infor1[p][0] = 10;
			Infor2[p][0] = 10;
			continue;
		}

		for (int i = 1; i <= 30; i++)
			for (int j = 1; j <= 10; j++)
				if (player[p]->MapSqure[i][j])
					Map[p][i][j] = -1;
	}

	if (0);
	else if (CountPlayer == 1) {
		render.DrawScore1(player[0]->CountScore);
		render.DrawGame1(Map[0], Infor1[0], Infor2[0]);
	}
	else if (CountPlayer == 2) {
		render.DrawScore2(player[0]->CountScore, player[1]->CountScore);
		render.DrawGame2(Map[0], Infor1[0], Infor2[0], Map[1], Infor1[1], Infor2[1]);
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
	/*
	This method is used to choose the game mode.
	It will choose the game mode Cur if the Cur is no less than 0, which means restart this game mode.
	*/

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

bool Game::carryCommand(char c) {
	/*
	This method is used to carry the correct command 'c'.
	Surely, it won't work if the command is not defined.
	*/
	/*if (c == Game::DIRECTIONS)
		c = _getch();*/
	int CountDeleteLines;
	if (0);
	/*
	It is setted just make the code more symmetrical.
	*/
	else if (c == 0) {
		CountDeleteLines = player[0]->run(0);
		addOtherLines(0, CountDeleteLines);
		CountDeleteLines = player[1]->run(0);
		addOtherLines(1, CountDeleteLines);
		return 1;
	}
	else if (c == UP || c == 'W' || c == 'w') {
		/*
		It will act on the first player if there are one player, or the command isn't direction key "up".
		The same to the next.
		*/
		if (CountPlayer == 1 || c != UP) {
			if (!PlayerAllow[0])
				return 0;
			CountDeleteLines = player[0]->run(Brick::Rotate);
			addOtherLines(0, CountDeleteLines);
			PlayerAllow[0] = 0;
			return 1;
		}
		else {
			if (!PlayerAllow[1])
				return 0;
			CountDeleteLines = player[1]->run(Brick::Rotate);
			addOtherLines(1, CountDeleteLines);
			PlayerAllow[1] = 0;
			return 1;
		}
		/*
		It will add CountDeleteLines to others if the player remove CountDeleteLines lines in GameMode 8 or 9.
		The same to the next.
		*/
	}
	else if (c == DOWN || c == 'S' || c == 's') {
		if (CountPlayer == 1 || c != DOWN) {
			if (!PlayerAllow[0])
				return 0;
			CountDeleteLines = player[0]->run(Brick::Down);
			addOtherLines(0, CountDeleteLines);
			PlayerAllow[0] = 0;
			return 1;
		}
		else {
			if (!PlayerAllow[1])
				return 0;
			CountDeleteLines = player[1]->run(Brick::Down);
			addOtherLines(1, CountDeleteLines);
			PlayerAllow[1] = 0;
			return 1;
		}
	}
	else if (c == LEFT || c == 'A' || c == 'a') {
		if (CountPlayer == 1 || c != LEFT) {
			if (!PlayerAllow[0])
				return 0;
			CountDeleteLines = player[0]->run(Brick::Left);
			addOtherLines(0, CountDeleteLines);
			PlayerAllow[0] = 0;
			return 1;
		}
		else {
			if (!PlayerAllow[1])
				return 0;
			CountDeleteLines = player[1]->run(Brick::Left);
			addOtherLines(1, CountDeleteLines);
			PlayerAllow[1] = 0;
			return 1;
		}
	}
	else if (c == RIGHT || c == 'D' || c == 'd') {
		if (CountPlayer == 1 || c != RIGHT) {
			if (!PlayerAllow[0])
				return 0;
			CountDeleteLines = player[0]->run(Brick::Right);
			addOtherLines(0, CountDeleteLines);
			PlayerAllow[0] = 0;
			return 1;
		}
		else {
			if (!PlayerAllow[1])
				return 0;
			CountDeleteLines = player[1]->run(Brick::Right);
			addOtherLines(1, CountDeleteLines);
			PlayerAllow[1] = 0;
			return 1;
		}
	}
	return 0;
}

int Game::preStart() {
	int Cur = 0;
	while (1) {
		render.PreStart(Cur);
		char c = _getch();
		if (c == ESC)
			return 1;
		if (c == ENTER) {
			if (0);
			else if (Cur == 0)
				return 0;
			else if (Cur == 1) {
				reName();
				continue;
			}
			else if (Cur == 2) {
				helpText();
				continue;
			}
			else if (Cur == 3) {
				historicRecord();
				continue;
			}
			else if (Cur == 4)
				return 1;
			else if (Cur == 5)
				return 3;
		}
		else {
			moveCur(Cur, c);
			Cur = (Cur % 6 + 6) % 6;
		}
	}
}

int Game::End() {
	if (0);
	else if (CountPlayer == 1)
		fileRecoder.update(GameMode, 1, player[0]->getScore());
	else if (CountPlayer == 2)
		fileRecoder.update(
			GameMode,
			(player[1]->getScore() >= player[0]->getScore()) << 1 | (player[0]->getScore() >= player[1]->getScore()),
			(player[0]->getScore() >= player[1]->getScore()) ? player[0]->getScore() : player[1]->getScore()
		);
	render.SetColor(5);
	int Cur = 0;
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

bool Game::isKeyDown(short VK_VALUE) {
	return GetAsyncKeyState(VK_VALUE) < 0;
}

char Game::carryKeys0(bool& RenewFlames) {
	static const short VK_W = 87, VK_S = 83, VK_A = 65, VK_D = 68;
	static const short VK_VALUE[] = { VK_UP,VK_DOWN,VK_LEFT,VK_RIGHT,VK_W,VK_S,VK_A,VK_D };
	static const char toASC[] = { UP,DOWN,LEFT,RIGHT,'W','S','A','D' };
	static bool IsKeyDown[8] = { 0 }, IsKeyCarried[8] = { 0 };
	for (int i = 0; i < 8; i++) {
		IsKeyDown[i] = isKeyDown(VK_VALUE[i]);
		if (IsKeyDown[i]) {
			if (IsKeyCarried[i])
				continue;
			IsKeyCarried[i] = 1;
			RenewFlames |= carryCommand(toASC[i]);
		}
		else IsKeyCarried[i] = 0;
	}
	return (isKeyDown(VK_ESCAPE)) * ESC;
}

char Game::carryKeys1(bool& RenewFlames) {
	static const short VK_W = 87, VK_S = 83, VK_A = 65, VK_D = 68;
	static const short VK_VALUE[] = { VK_UP,VK_DOWN,VK_LEFT,VK_RIGHT,VK_W,VK_S,VK_A,VK_D };
	static const char toASC[] = { UP,DOWN,LEFT,RIGHT,'W','S','A','D' };
	static int LIMIT = 3, CountKey[8] = { 0 };
	for (int i = 0; i < 8; i++)
		if (isKeyDown(VK_VALUE[i])) {
			CountKey[i]++;
			if (CountKey[i] == LIMIT) {
				RenewFlames |= carryCommand(toASC[i]);
				CountKey[i] = 0;
			}
		}
		else CountKey[i] = 0;
	return (isKeyDown(VK_ESCAPE)) * ESC;
}

char Game::PlayerOperation(bool& RenewFlames) {
	if (0);
	else if (OperationMode == 0)
		return carryKeys0(RenewFlames);
	else if (OperationMode == 1)
		return carryKeys1(RenewFlames);
}

int Game::play() {
	/*
	This method is used to carry the World-Teris game circularly.
	It will return that whether the game is started.
	*/
	int Res = preStart();
	if (Res != 0)
		return Res;

	//system("cls");
	int FramesLimit = 1000 / FramesTime;
	/*
	Number FramesLimit is setted as the limits of FramesCount.
	It will make the bricks fall down 1 cell, if the FramesCount is not less than it.
	*/

	player[0]->setName(fileRecoder.NamePlayer[0]);
	player[1]->setName(fileRecoder.NamePlayer[1]);
	render.DrawGameMap(CountPlayer);
	renderMap();
	PlayerAllow[0] = PlayerAllow[1] = 1;

	double SumTime = 0, CntTime = 0;

	for (clock_t last = clock(), now = last;; now = clock()) {
		clock_t LastTime = clock();
		if (now - last >= FramesTime) {
			PlayerAllow[0] = PlayerAllow[1] = 1;
			last = now - now % FramesTime;
			FramesCount++;
		}
		bool RenewFlames = 0;
		if (FramesCount >= FramesLimit) {
			RenewFlames = 1;
			/*
			It is time to make the bricks fall down.
			*/
			carryCommand(0);
			FramesCount -= FramesLimit;

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

		}
		char c = PlayerOperation(RenewFlames);
		if (c == ESC)
			break;
		if (RenewFlames)
			renderMap();
		LastTime = clock() - LastTime;
		if (OperationMode == 1 && FramesTime > LastTime) {
			Sleep(FramesTime - LastTime);
			SumTime += LastTime;
			CntTime += 1;
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

	while (_kbhit())
		_getch();

	return End();
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
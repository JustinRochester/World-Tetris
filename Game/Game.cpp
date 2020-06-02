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

void Game::helpText(){
	std::cout << "当你们看见方块掉落时，什么都不要干，就这么看着它。" << std::endl;
	std::cout << "谁先顶到天花板，谁就赢了。" << std::endl;
	std::cout<< std::endl;
	std::cout << "如果你们乱动方块，会把填满的行消掉。我们会记录你们的分数：" << std::endl;
	std::cout << "\t消除 1 行，记录 10 分" << std::endl;
	std::cout << "\t消除 2 行，记录 30 分" << std::endl;
	std::cout << "\t消除 3 行，记录 60 分" << std::endl;
	std::cout << "\t消除 4 行，记录 100 分" << std::endl;
	std::cout << std::endl;
	if (GameMode == 2 || GameMode == 3 || GameMode == 6 || GameMode == 7 || GameMode == 9) {
		std::cout << "作为惩罚，每加 10 分，方块下落会变快一次，直至上限" << std::endl;
		std::cout << std::endl;
	}
	if (GameMode == 8 || GameMode == 9) {
		std::cout << "同时，为了方便你的朋友顶到天花板。你每次消除一行，你的朋友就会增加一行" << std::endl;
		std::cout << std::endl;
	}
	if (GameMode == 1 || GameMode == 3 || GameMode == 5 || GameMode == 7) {
		std::cout << "为了方便你们顶到天花板，每次方块下落有 1% 的概率触发加行 buff :" << std::endl;
		std::cout << "\t其中有 40% 的概率增加 1 行" << std::endl;
		std::cout << "\t其中有 30% 的概率增加 2 行" << std::endl;
		std::cout << "\t其中有 20% 的概率增加 3 行" << std::endl;
		std::cout << "\t其中有 10% 的概率增加 4 行" << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "懂了就随便敲一个键回去，没懂就多看几遍背下来" << std::endl;
	system("pause>nul");
}

void Game::welcome() {
}

void Game::renderMap() {
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
	render.DrawGame1(Map, Pnt[0],Infor);
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

void Game::setGameMode() {

	for (int i = 0; i < 2; i++)
		if (player[i] != NULL) {
			delete player[i];
			player[i] = NULL;
		}
	CountPlayer = 0;

	int Cur = 0, CountGameMode = 10;
	while (1) {
		system("cls");
		std::cout << "请选择游戏模式" << std::endl;
		std::cout << char((0 == Cur) * '>') << char((0 == Cur) * '>') << "单人修仙" << std::endl;
		std::cout << char((1 == Cur) * '>') << char((1 == Cur) * '>') << "单人加行" << std::endl;
		std::cout << char((2 == Cur) * '>') << char((2 == Cur) * '>') << "单人加速" << std::endl;
		std::cout << char((3 == Cur) * '>') << char((3 == Cur) * '>') << "单人加行加速" << std::endl;
		std::cout << char((4 == Cur) * '>') << char((4 == Cur) * '>') << "双人修仙" << std::endl;
		std::cout << char((5 == Cur) * '>') << char((5 == Cur) * '>') << "双人加行" << std::endl;
		std::cout << char((6 == Cur) * '>') << char((6 == Cur) * '>') << "双人加速" << std::endl;
		std::cout << char((7 == Cur) * '>') << char((7 == Cur) * '>') << "双人加行加速" << std::endl;
		std::cout << char((8 == Cur) * '>') << char((8 == Cur) * '>') << "双人此消彼长" << std::endl;
		std::cout << char((9 == Cur) * '>') << char((9 == Cur) * '>') << "双人此消彼长加速" << std::endl;

		char c = _getch();
		if (c == ESC)
			return;
		if (c == ENTER)
			break;
		moveCur(Cur, c);
		Cur = (Cur % CountGameMode + CountGameMode) % CountGameMode;
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

void Game::play() {
	/*
	This method is used to carry the World-Teris game circularly.
	*/

	int Cur = 0;
	while (1) {
		system("cls");
		std::cout << char((0 == Cur) * '>') << char((0 == Cur) * '>') << "开始游戏" << std::endl;
		std::cout << char((1 == Cur) * '>') << char((1 == Cur) * '>') << "查看帮助" << std::endl;
		char c = _getch();
		if (c == ESC) {
			system("cls");
			return;
		}
		if (c == ENTER) {
			if (0);
			else if (Cur == 0)
				break;
			else if (Cur == 1) {
				system("cls");
				helpText();
				continue;
			}
		}
		else {
			moveCur(Cur, c);
			Cur = (Cur % 2 + 2) % 2;
		}
	}

	int FramesLimit = 1000 / FramesTime;
	/*
	Number FramesLimit is setted as the limits of FramesCount.
	It will make the bricks fall down 1 cell, if the FramesCount is not less than it.
	*/
	player[0]->setName("玩家1");
	player[1]->setName("玩家2");
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
			player[0]->run(0);
			if(CountPlayer==2)
				player[1]->run(0);
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
	system("cls");
	std::cout << "游戏结束"<<std::endl;
	for (int i = 0; i < CountPlayer; i++)
		std::cout << "\t玩家: " << player[i]->getName() << " 得分 " << player[i]->getScore() << std::endl;
}
void Game::run() {
	welcome();
	while (1) {
		setGameMode();
		if (CountPlayer == 0)
			break;
		play();
		std::cout << "按回车键继续游戏，退出键退出游戏" << std::endl;
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
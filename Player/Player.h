#include<string>
#include"Brick.h"

#ifndef _PLAYER
#define _PLAYER
class Player {
private:
	static int UP_LIM, DOWN_LIM, LEFT_LIM, RIGHT_LIM;
	int CountScore;
	bool MapSqure[32][12];
	bool GameOver;
	std::string Name;
	Brick NowBrick, NextBrick;

	bool isOverlap();
	bool carryCommand(int Direction);
	bool touchBottom();
	bool touchCeiling();
	void addToMap();
	int delLine();
	int renewBrick();
#ifdef DEBUG
	friend void display(Player &p);
#endif

public:
	Player(bool StartGame=0);
	void setName(const std::string& Name_);
	int run(int Direction);
	int addLine(int CountLine);
};
#endif
#include<string>
#include"Brick.h"

#ifndef _PLAYER
#define _PLAYER
class Player {
private:
	static int UP, DOWN, LEFT, RIGHT, SPIN, UPDATE;
	static int UP_LIM, DOWN_LIM, LEFT_LIM, RIGHT_LIM;
	int CountScore;
	bool MapSqure[30][10];
	bool GameOver;
	std::string Name;
	Brick NowBrick, NextBrick;

	bool isOverlap();//L
	bool carryCommand(int Direction);//L
	bool touchBottom();//L
	bool touchCeiling();//C
	void addToMap();//C
	int delLine();//L

public:
	Player(bool StartGame=0);//Finished
	void setName(const std::string& Name_);//Finished
	void run(int Direction,int &CountRemoveLine);
	void addLine(int CountLine);//C
};
#endif
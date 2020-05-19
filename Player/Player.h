#include<string>

#ifndef _PLAYER
#define _PLAYER
class Player {
private:
	int CountScore;
	bool MapSqure[10][30];
	bool GameOver;
	std::string Name;

	bool isOverlap();//L
	bool alowOperation(int direction);//L
	bool touchBottom();//L
	bool touchCeiling();//C
	void addToMap();//C
	int delLine(int State[9]);//L

public:
	Player(bool StartGame=0);//Finished
	void setName(const std::string& Name_);//Finished
	void run(int Direction,int &CountRemoveLine);
	void addLine(int CountLine);//C
};
#endif
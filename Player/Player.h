#include<string>

#ifndef _PLAYER
#define _PLAYER
class Player {
private:
	int CountScore;
	bool MapSqure[10][25];
	bool GameOver;
	std::string Name;

public:
	Player(bool StartGame=0);
	void setName(const string& s);
};
#endif
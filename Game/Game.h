#include"Render.h"

#ifndef _GAME
#define _GAME
class Player;
class Game {
private:
	Player *player[2];
	Render render;
	int GameMode,CountPlayer;
	static int FramesCount, FramesTime;
	static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER;

	void explain();
	void participants();
	bool welcome();
	void carryCommand(char);
	void setGameMode(int);
	int play();
	void addOtherLines(int,int);
	void moveCur(int&,char);
	void helpText();

public:	
	Game();	
	~Game();
	void run();
	void renderMap();
}; 
#endif

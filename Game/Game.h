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
	void setGameMode(int);
	void helpText();
	int preStart();
	int End();

	void carryCommand(char);
	int play();
	void addOtherLines(int,int);
	void moveCur(int&,char);

public:	
	Game();	
	~Game();
	void run();
	void renderMap();
}; 
#endif

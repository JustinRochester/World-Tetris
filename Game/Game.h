#include"Render.h"

#ifndef _GAME
#define _GAME
class Player;
class Game {
private:
	Player *player[2];
	Render render;
	int GameMode, CountPlayer, FramesCount, OperationMode;
	bool PlayerAllow[2];
	static int FramesTime;
	static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER;

	void explain();
	void participants();
	bool welcome();
	void setGameMode(int);
	void helpText();
	int preStart();
	int End();
	void Setting();

	static bool isKeyDown(short);

	bool carryCommand(char);
	char carryKeys2(bool&);
	char PlayerOperation(bool&);
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

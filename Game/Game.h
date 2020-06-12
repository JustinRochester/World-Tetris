#include"Render.h"
#include"FileRecoder.h"

#ifndef _GAME
#define _GAME
class Player;
class Game {
private:
	Player *player[2];
	Render render;
	FileRecoder fileRecoder;
	int GameMode, CountPlayer, FramesCount, OperationMode;
	bool PlayerAllow[2];
	static int FramesTime;
	static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER, BACKSPACE;

	void explain();
	void participants();
	bool welcome();
	void setGameMode(int);
	void helpText();
	void historicRecord();
	int preStart();
	int End();
	void Setting();
	void reName();
	void reName(int);

	static bool isKeyDown(short);

	bool carryCommand(char);
	char carryKeys0(bool&);
	char carryKeys1(bool&);
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

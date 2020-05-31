//#include"Render.h"

#ifndef _GAME
#define _GAME
class Player;
class Game {
private:
	Player *player[2];
	//Render render;
	int GameMode,CountPlayer;
	static int FramesCount, FramesTime;
	static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER;

	void welcome();
	void carryCommand(char c);
	void setGameMode();
	void play();

public:	
	Game();	
	~Game();
	void run();
	void renderMap();
}; 
#endif

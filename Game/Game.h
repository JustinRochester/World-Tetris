#include"Player.h"
#include"Render.h"

class Game {
private:
	Player player[2];
	Render render;
	int Gamemode,CountPlayer;
	static int FramesCount, FramesTime;
	static const char ESC, LEFT, RIGHT, UP, DOWN,DIRECTIONS;

	void welcome();
	void carryCommand(char c);
	void setGameMode();
	void play();

public:	
	Game();	
	void run();
}; 

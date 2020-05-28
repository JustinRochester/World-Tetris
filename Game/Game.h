#include"Player.h"
#include"Render.h"
class Game {
private:
	Player player[2];
	int Gamemode;
	static int NumberOfFrames;
	bool gameShouldOver();
	bool IsUsedCommand();
	void setGameMode();
	void play();

public:	
	Game();	
	void run();
}; 

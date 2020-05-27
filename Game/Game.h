class Game {
private:
	Player player[2];
	int Gamemode;
	static int NumberOfFrames;

public:	
	Game();	
	bool gameShouldOver();
	void run();
	
	void setGameMode();
}; 

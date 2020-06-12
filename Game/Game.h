#include"Render.h"
#include"FileRecoder.h"
#include"PlaySound.h"

#ifndef _GAME
#define _GAME
class Player;
class Game {
private:
	static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER, BACKSPACE;
	static const int FramesTime;
	static const std::string BGMPath[11][2];
	static const std::string SoundEffectPath[2][2];

	Player* player[2];
	Render render;
	FileRecoder fileRecoder;
	PlayMusic BGMMusic[11];//0-9分别表示模式0-9的BGM,10表示菜单界面的BGM
	PlayMusic SoundEffect[2];
	bool BGMOn[11];
	int MusicMode;
	int GameMode, CountPlayer, FramesCount;
	int OperationMode, IsBackgroundMusicOn, IsSoundEffect;
	bool PlayerAllow[2];

	static bool isKeyDown(short);

	//UI
	void moveCur(int&, char);
	bool welcome();
	void setGameMode(int);
	void reName();
	void reName(int);
	void explain();
	void participants();
	void Setting();
	void helpText();
	void historicRecord();
	int preStart();
	int End();

	bool carryCommand(char);
	char carryKeys0(bool&);
	char carryKeys1(bool&);
	char PlayerOperation(bool&);
	int play();
	void addOtherLines(int, int);

public:
	Game();
	~Game();
	void run();
	void renderMap();
};
#endif

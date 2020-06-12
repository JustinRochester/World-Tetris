#include"Render.h"
#include"FileRecoder.h"
#include"PlaySound.h"

#ifndef _GAME
#define _GAME
class Player;
class Game {
private:
	Player* player[2];
	Render render;
	PlayMusic BGMMusic[11];//0-9分别表示模式0-9的BGM,10表示菜单界面的BGM
	PlayMusic TouchSound, KeySound;
	static const std::string TouchSoundPath[2], KeySoundPath[2];
	bool BGMOn[11];
	static const std::string BGMPath[11][2];
	int MusicMode;
	FileRecoder fileRecoder;
	int GameMode, CountPlayer, FramesCount;
	int OperationMode, IsBackgroundMusicOn, IsKeySound, IsTouchSound;
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
	void addOtherLines(int, int);
	void moveCur(int&, char);

public:
	Game();
	~Game();
	void run();
	void renderMap();
};
#endif

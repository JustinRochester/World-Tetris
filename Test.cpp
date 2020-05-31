#include"Game.h"
#include"Player.h"
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;
Game* g;
int main() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	//Hide the Cursor.

	srand(time(0));
	g = new Game();
	g->run();
	return 0;
}
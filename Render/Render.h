#include<cstdlib>
#include<windows.h>
#include<conio.h>
#ifndef _Render
#define _Render
class Render
{
private:
	int type;				//模式 
public:
	void Welcome();			//首界面
	void SetColor(int);		//控制颜色
	void DrawMap1(int score);			//游戏界面
	void DrawMap2(int score1, int score2);
	void DrawGame1(int Map[32][12], int BrickCol, const int *NextBrick);  //single-player 
	static void HideCursor();
	static void SetTitle();
};

#endif


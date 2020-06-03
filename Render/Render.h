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
	void DrawGame2(int Map1[32][12], const int *B1, int Map2[32][12], const int *B2);
	/*
		B1[0] is the color
		B2[0] is the color
		Map[i][j] = -1 is meant that the brick can't move
		Map[i][j] = 0 is meant that there is no brick
		Map[i][j] = x (1 <= x <= 10) meant (i,j) have a Brick is moving and color is x
	*/
	static void HideCursor();
	static void SetTitle();
};

#endif


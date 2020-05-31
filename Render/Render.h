#include<cstdlib>
#include<windows.h>
#include<conio.h>
#ifndef Render
#define Render
class Render
{
private:
	int type;				//模式 
	int score; 
public:
	void Welcome();			//首界面
	void SetColor(int);		//控制颜色
	void DrawMap1();			//游戏界面
	void DrawMap2(); 
};
#endif

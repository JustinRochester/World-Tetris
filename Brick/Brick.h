#pragma once
#include <cstdlib>

class Brick {
private:
	int BrickColor;//方块颜色
	int BrickType;//方块类型
	int BrickPos[9];//坐标集合
	int CenterX, CenterY;//中心点坐标
	void shiftLeft(int pace = 1);//左移
	void shiftRight(int pace = 1);//右移
	void shiftDown(int pace = 1);//下移
	void shiftUp(int pace = 1);//上移
	void brickUpdate();//更新颜色和类型
	void rotateBrick();//顺时针旋转
	static const int TotalBrickType = 17, TotalColorType = 4;
public:
	static const int Up = 1, Down = 2,Left = 3, Right = 4, Rotate = 5, Update = 6;
	Brick();//初始化类型和颜色
	void brickSet(int x, int y);//通过x,y初始化坐标
	void Operation(int _Order);//识别指令
	int* getInformation();//返回信息
};

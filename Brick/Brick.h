#include <cstdlib>
#pragma once

class Brick {
private:
	int BrickColor;//方块颜色
	int BrickType;//方块类型
	int BrickPos[9];//坐标集合
	int CenterX, CenterY;//中心点坐标
	static int TotalColorType;//颜色总数
	static int TotalBrickType;	//类型总数
public:
	Brick();//初始化类型和颜色
	void brickSet(int x, int y);//通过x,y初始化坐标
	void shiftLeft(int pace = 1);//左移
	void shiftRight(int pace = 1);//右移
	void shiftDown(int pace = 1);//下移
	void shiftUp(int pace = 1);//上移
	void rotateBrick();//顺时针旋转
	void identifyOrder(int _Order);//识别指令
	int* getInformation();//返回信息
	void brickUpdate();//更新颜色和类型
};

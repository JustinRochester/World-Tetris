#include "Brick.h"


int Brick::randlyAssign() {
	int _Type = rand() % TotalBrickType;// TotalBrickType = 7;
	if (_Type == 5)// 对称的'7'
		_Type = 1;
	else if (_Type == 6)//对称的'z'
		_Type = 4;
	_Type += 1;
	if (_Type == 9)
		return _Type;
	_Type += rand() % 4;
	return _Type;

}

void Brick::brickUpdate() {
	BrickColor = (rand() % TotalColorType) + 1;
	BrickType = Brick::randlyAssign();
	for (int i = 1; i < 9; ++i)
		BrickPos[i] = 0;
	BrickPos[0] = BrickColor;
}

Brick::Brick() {
	brickUpdate();
}

void Brick::brickSet(int x, int y) {
	CenterX = x;
	CenterY = y;
	switch(BrickType) {
		case 1:
			for (int i = 1; i <= 7; i += 2)
				BrickPos[i] = x;
			for (int i = 2, _i = -1; i <= 8; i += 2, _i++)
				BrickPos[i] = y + _i;
			break;
		case 2:
			for (int i = 1, _i = -1; i <= 7; i += 2, _i++)
				BrickPos[i] = x + _i;
			for (int i = 2; i <= 8; i += 2)
				BrickPos[i] = y + 1;
			break;
		case 3:
			for (int i = 1; i <= 7; i += 2)
				BrickPos[i] = x + 1;
			for (int i = 2, _i = -1; i <= 8; i += 2, _i++)
				BrickPos[i] = y + _i;
			break;
		case 4:
			for (int i = 1, _i = -1; i <= 7; i += 2, _i++)
				BrickPos[i] = x + _i;
			for (int i = 2; i <= 8; i += 2)
				BrickPos[i] = y;
			break;
		case 5:
			BrickPos[1] = x - 1;
			BrickPos[3] = BrickPos[5] = BrickPos[7] = x;
			BrickPos[4] = y - 1;
			BrickPos[6] = y;
			BrickPos[8] = BrickPos[2] = y + 1;
			break;
		case 6:
			BrickPos[1] = x - 1;
			BrickPos[3] = x;
			BrickPos[5] = BrickPos[7] = x + 1;
			BrickPos[2] = BrickPos[4] = BrickPos[6] = y;
			BrickPos[8] = y + 1;
			break;
		case 7:
			BrickPos[1] = BrickPos[3] = BrickPos[5] = x;
			BrickPos[7] = x + 1;
			BrickPos[2] = BrickPos[8] = y - 1;
			BrickPos[4] = y;
			BrickPos[6] = y + 1;
			break;
		case 8:
			BrickPos[1] = BrickPos[3] = x - 1;
			BrickPos[5] = x;
			BrickPos[7] = x + 1;
			BrickPos[2] = y - 1;
			BrickPos[4] = BrickPos[6] = BrickPos[8] = y;
			break;
		case 9:
			BrickPos[1] = BrickPos[3] = x;
			BrickPos[5] = BrickPos[7] = x + 1;
			BrickPos[2] = BrickPos[6] = y;
			BrickPos[4] = BrickPos[8] = y + 1;
			break;
		case 10:
			BrickPos[1] = x - 1;
			BrickPos[3] = BrickPos[5] = BrickPos[7] = x;
			BrickPos[2] = BrickPos[6] = y;
			BrickPos[4] = y - 1;
			BrickPos[8] = y + 1;
			break;
		case 11:
			BrickPos[1] = x - 1;
			BrickPos[3] = BrickPos[7] = x;
			BrickPos[5] = x + 1;
			BrickPos[2] = BrickPos[4] = BrickPos[6] = y;
			BrickPos[8] = y + 1;
			break;
		case 12:
			BrickPos[1] = BrickPos[3] = BrickPos[5] = x;
			BrickPos[7] = x + 1;
			BrickPos[2] = y - 1;
			BrickPos[4] = BrickPos[8] =  y;
			BrickPos[6] = y + 1;
			break;
		case 13:
			BrickPos[1] = BrickPos[5] = x;
			BrickPos[3] = x - 1;
			BrickPos[7] = x + 1;
			BrickPos[2] = y - 1;
			BrickPos[4] = BrickPos[6] = BrickPos[8] = y;
			break;
		case 14:
			BrickPos[1] = BrickPos[3] = x - 1;
			BrickPos[5] = BrickPos[7] = x;
			BrickPos[2] = y - 1;
			BrickPos[4] = BrickPos[6] = y;
			BrickPos[8] = y + 1;
			break;
		case 15:
			BrickPos[5] = x - 1;
			BrickPos[1] = BrickPos[7] = x;
			BrickPos[3] = x + 1;
			BrickPos[2] = BrickPos[4] = y;
			BrickPos[6] = BrickPos[8] = y + 1;
			break;
		case 16:
			BrickPos[1] = BrickPos[3] = x;
			BrickPos[5] = BrickPos[7] = x + 1;
			BrickPos[2] = y - 1;
			BrickPos[4] = BrickPos[6] = y;
			BrickPos[8] = y + 1;
			break;
		case 17:
			BrickPos[5] = x - 1;
			BrickPos[1] = BrickPos[7] = x;
			BrickPos[3] = x + 1;
			BrickPos[2] = BrickPos[4] = y - 1;
			BrickPos[6] = BrickPos[8] = y;
			break;
	}
}

void Brick::shiftLeft(int pace) {
	for (int i = 2;i <= 8; i += 2)
		BrickPos[i] -= pace;
	CenterY -= pace;
}

void Brick::shiftRight(int pace) {
	for (int i = 2; i <= 8; i += 2)
		BrickPos[i] += pace;
	CenterY += pace;
}

void Brick::shiftUp(int pace) {
	for (int i = 1; i <= 7; i += 2)
		BrickPos[i] -= pace;
	CenterX -= pace;
}

void Brick::shiftDown(int pace) {
	for (int i = 1; i <= 7; i += 2)
		BrickPos[i] += pace;
	CenterX += pace;
}

int* Brick::getInformation() {
	return BrickPos;
}

void Brick::rotateBrick() {
	int x = CenterX;
	int y = CenterY;
	switch(BrickType) {
		case 1:
			BrickType = 2;
			break;
		case 2:
			BrickType = 3;
			break;
		case 3:
			BrickType = 4;
			break;
		case 4:
			BrickType = 1;
			break;
		case 5:
			BrickType = 6;
			break;
		case 6:
			BrickType = 7;
			break;
		case 7:
			BrickType = 8;
			break;
		case 8:
			BrickType = 5;
			break;
		case 9:
			BrickType = 9;
			break;
		case 10:
			BrickType = 11;
			break;
		case 11:
			BrickType = 12;
			break;
		case 12:
			BrickType = 13;
			break;
		case 13:
			BrickType = 10;
			break;	
		case 14:
			BrickType = 15;
			break;
		case 15:
			BrickType = 16;
			break;
		case 16:
			BrickType = 17;
			break;
		case 17:
			BrickType = 14;
			break;
	}
	brickSet(x, y);
}

void Brick::Operation(int _Order) {
	switch(_Order) {
		case Brick::Up:
			shiftUp();
			break;
		case Brick::Down:
			shiftDown();
			break;
		case Brick::Left:
			shiftLeft();
			break;
		case Brick::Right:
			shiftRight();
			break;
		case Brick::Rotate:
			rotateBrick();
			break;
		case Brick::Update:
			brickUpdate();
			break;
	}
}

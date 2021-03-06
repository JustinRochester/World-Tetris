#include "Brick.h"


int Brick::randlyAssign() {
	int _Type = rand() % TotalBrickType;// TotalBrickType = 7;
	int Sym = 0;
	if (_Type == 5)// �ԳƵ�'7'
		_Type = 1, Sym = 1;
	else if (_Type == 6)//�ԳƵ�'z'
		_Type = 4, Sym = 1;
	_Type = (_Type << 2) | (rand() & 3);
	_Type += 1;
	if (_Type > 11) _Type -= 3;
	else if (_Type > 9) _Type = 9;
	return (_Type << 1) | Sym;

}

void Brick::Symmetry() {
	if (!IsSym) return;
	for (int i = 1; i < 9; i += 2)
		BrickPos[i] = 2 * CenterX - BrickPos[i];
}

void Brick::brickUpdate() {
	BrickColor = (rand() % TotalColorType) + 1;
	BrickType = Brick::randlyAssign();
	IsSym = BrickType & 1;
	BrickType >>= 1;
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
	Symmetry();
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

	int CountRotate;
	if (IsSym) CountRotate = 3;
	else CountRotate = 1;

	for (int i = 1; i <= CountRotate; i++) {
		BrickType--;
		if (BrickType >= 8) BrickType += 3;
		BrickType = ((BrickType >> 2) << 2) | ((BrickType + 1) & 3);
		if (BrickType > 8) BrickType -= 3;
		BrickType++;
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

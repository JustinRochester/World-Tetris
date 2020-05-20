#include"Player.h"

int Player::UP_LIM = 30;
int Player::DOWN_LIM = 1;
int Player::RIGHT_LIM = 10;
int Player::LEFT_LIM = 1;
Player::Player(bool StartGame) {
	CountScore = 0;
	for (int i = DOWN_LIM; i <= UP_LIM; i++)
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			MapSqure[i][j] = 0;
	for (int i = DOWN_LIM; i <= UP_LIM; i++)
		MapSqure[i][LEFT_LIM - 1] = MapSqure[i][RIGHT_LIM + 1] = 1;
	for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
		MapSqure[DOWN_LIM - 1][j] = MapSqure[UP_LIM + 1][j] = 1;
	GameOver = !StartGame;
	/*
	Surely, the game serve won't start if this player didn't start the game.
	*/
}
void Player::setName(const std::string& Name_) {
	Name = Name_;
}
bool Player::isOverlap(){
	/*
	This method is used to check whether the working brick is overlapping the map.
	*/
	int* Tmp;
	Tmp = NowBrick.getInformation();

	for (int i = 1; i < 9; i+=2)
		if (Tmp[i]<DOWN_LIM || Tmp[i]>UP_LIM)
			return true;
	for (int i = 2; i < 9; i+=2)
		if (Tmp[i]<LEFT_LIM || Tmp[i]>RIGHT_LIM)
			return true;
	/*
	The brick is out of the map. We considered that it is a case of overlap.
	(Considered that there are some walls around the map.)
	*/

	for (int i = 1; i < 9; i+=2)
		if (MapSqure[Tmp[i]][Tmp[i + 1]])
			return true;
	return false;
}
bool Player::carryCommand(int Direction) {
	/*
	This method is used to carry the command which is given by the player.
	And it will return that whether it carried successfully or not.
	*/
	NowBrick.Operation(Direction);
	if (Direction == Brick::Down) {
		/*
		The Command that this player given is down to the bottom.
		*/
		while (!isOverlap())
			NowBrick.Operation(Brick::Down);
		NowBrick.Operation(Brick::Up);
		return true;
	}
	if (Direction == Brick::Rotate) {
		NowBrick.Operation(Brick::Right);
		if (!isOverlap())
			return true;
		NowBrick.Operation(Brick::Right);
		NowBrick.Operation(Brick::Right);
		NowBrick.Operation(Brick::Right);
		return false;
	}
	if (Direction == Brick::Left || Direction == Brick::Right) {
		NowBrick.Operation(Direction);
		if (!isOverlap())
			return true;
		if (Direction == Brick::Left)
			NowBrick.Operation(Brick::Right);
		else
			NowBrick.Operation(Brick::Left);
		return false;
	}
	return false;
}
bool Player::touchBottom() {
	/*
	This method is used to check whether the working brick touches the bottom.
	*/
	NowBrick.Operation(Brick::Down);
	bool TouchBottom = isOverlap();
	NowBrick.Operation(Brick::Up);
	return TouchBottom;
}
int Player::delLine() {
	/*
	This method is used after the working birck touches the bottom.
	And it will work to delete the full line.
	After that, it will return the number of the line(s) it deleted.
	*/
	int* Tmp = NowBrick.getInformation();
	int Lines[4] = { 0 };
	for (int i = 1,j=0; i < 9; i+=2,j++)
		Lines[j] = Tmp[i];
	for (int i = 0; i < 4; i++)
		for (int j = 3; j > i; j--)
			if (Lines[j] < Lines[j - 1])
				Lines[j] ^= Lines[j - 1] ^= Lines[j] ^= Lines[j - 1];
	/*
	Get the lines that the working brick in. And sort them from the minimum to the maximum.
	*/
	int CountLines = 0;
	for (int i = 0; i < 4; i++) {
		if (i > 0 && Lines[i] == Lines[i - 1])
			continue;
		int Line = Lines[i];
		bool FullLine = 1;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			FullLine &= MapSqure[Line][j];
		if (!FullLine)
			continue;
		/*
		Check that whether the line is full or not.
		*/

		CountLines++;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			MapSqure[Line][j] = 0;
		/*
		Delete the full line.
		*/
	}

	for (int i = DOWN_LIM; i <= UP_LIM; i++) {
		bool EmptyLine = 1;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			EmptyLine &= !MapSqure[i][j];
		if (!EmptyLine) continue;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++) {
			MapSqure[i][j] = MapSqure[i + 1][j];
			MapSqure[i + 1][j] = 0;
		}
	}

	return CountLines;
}
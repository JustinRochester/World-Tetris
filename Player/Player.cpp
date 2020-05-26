#include"Player.h"
#include<ctime>

int Player::UP_LIM = 1;
int Player::DOWN_LIM = 30;
int Player::RIGHT_LIM = 10;
int Player::LEFT_LIM = 1;
Player::Player(bool StartGame) {
	CountScore = 0;
	for (int i = UP_LIM; i <= DOWN_LIM; i++)
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			MapSqure[i][j] = 0;
	for (int i = UP_LIM; i <= DOWN_LIM; i++)
		MapSqure[i][LEFT_LIM - 1] = MapSqure[i][RIGHT_LIM + 1] = 1;
	for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
		MapSqure[UP_LIM - 1][j] = MapSqure[DOWN_LIM + 1][j] = 1;
	GameOver = !StartGame;
	if (GameOver) return;
	/*
	Surely, the game serve won't start if this player didn't start the game.
	*/
	NowBrick.Operation(Brick::Update);
	NowBrick.brickSet(6, LEFT_LIM + RIGHT_LIM >> 1);
	NextBrick.Operation(Brick::Update);

	int NowLine = 0;
	for (int* Information = NowBrick.getInformation() + 1, i = 1; i < 9; i += 2, Information += 2)
		if (*Information > NowLine)
			NowLine = *Information;
	while (NowLine < 10) {
		NowBrick.Operation(Brick::Down);
		NowLine++;
	}
}
void Player::setName(const std::string& Name_) {
	Name = Name_;
	return;
}
bool Player::isOverlap(){
	/*
	This method is used to check whether the working brick is overlapping the map.
	*/
	const int* Tmp = NowBrick.getInformation();

	for (int i = 1; i < 9; i+=2)
		if (Tmp[i]<UP_LIM || Tmp[i]>DOWN_LIM)
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
	if (Direction == 0) {
		/*
		The Command is given by the system that the working birck should fall by one line.
		*/
		NowBrick.Operation(Brick::Down);
		return true;
	}
	if (Direction == Brick::Down) {
		/*
		The command that this player given is down quickly.
		So, I set that it falls down 3 cells in this game.
		*/
		for (int i = 1; i <= 3; i++)
			NowBrick.Operation(Brick::Down);
		while (isOverlap())
			NowBrick.Operation(Brick::Up);
		return true;
	}
	if (Direction == Brick::Rotate) {
		NowBrick.Operation(Brick::Rotate);
		if (!isOverlap())
			return true;
		NowBrick.Operation(Brick::Rotate);
		NowBrick.Operation(Brick::Rotate);
		NowBrick.Operation(Brick::Rotate);
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
bool Player::touchCeiling() {
	/*
	In this code, we considered that the first 20 lines consists of the map.
	Therefore, it means that the game is over if there is any brick appeared out of them.
	*/
	for (int i = UP_LIM; i <= 10; i++) 
		for(int j=LEFT_LIM;j<=RIGHT_LIM;j++)
			if (MapSqure[i][j])
				return true;
		
	return false;
}
void Player::addToMap() {
	/*
	This method is used to add the working brick into the map, which touches the bottom.
	*/
	const int* Information = NowBrick.getInformation();
	for (int i = 1; i < 9; i += 2)
		MapSqure[Information[i]][Information[i + 1]] = 1;
	return;
}
int Player::delLine() {
	/*
	This method is used after the working birck touches the bottom.
	And it will work to delete the full line.
	After that, it will return the number of the line(s) it deleted.
	*/
	const int* Information = NowBrick.getInformation();
	int Lines[4] = { 0 };
	for (int i = 1,j=0; i < 9; i+=2,j++)
		Lines[j] = Information[i];
	for (int i = 0; i < 4; i++)
		for (int j = 3; j > i; j--)
			if (Lines[j] < Lines[j - 1])
				Lines[j] ^= Lines[j - 1] ^= Lines[j] ^= Lines[j - 1];
	/*
	Get the lines that the working brick in. And sort them from the minimum to the maximum.
	*/
	int CountDeleteLine = 0;
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

		CountDeleteLine++;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			MapSqure[Line][j] = 0;
		/*
		Delete the full line.
		*/
	}

	for (int i = DOWN_LIM-1; i >= UP_LIM; i--) {
		bool EmptyLine = 1;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			EmptyLine &= !MapSqure[i][j];
		if (EmptyLine) continue;
		int Line = i;
		while (1) {
			if (Line == DOWN_LIM) break;
			EmptyLine = 1;
			for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
				EmptyLine &= !MapSqure[Line+1][j];
			if (!EmptyLine) break;
			for (int j = LEFT_LIM; j <= RIGHT_LIM; j++) {
				MapSqure[Line + 1][j] = MapSqure[Line][j];
				MapSqure[Line][j] = 0;
			}
			Line++;
		}
	}

	CountScore += CountDeleteLine * (CountDeleteLine + 1) / 2;

	return CountDeleteLine;
}
int Player::renewBrick() {
	/*
	This method is used while the working brick touches the bottom.
	And this method is used to renew the working brick.
	Because the renewing will change the state of the brick which is working now,
	it will return the number of line(s) which is deleted, too.
	*/
	int countDeleteLine = delLine();
	NowBrick = NextBrick;
	NowBrick.brickSet(6, LEFT_LIM + RIGHT_LIM >> 1);
	NextBrick.Operation(Brick::Update);

	int NowLine = 0;
	for (int* Information = NowBrick.getInformation() + 1, i = 1; i < 9; i += 2, Information += 2)
		if (*Information > NowLine)
			NowLine = *Information;
	while (NowLine < 10) {
		NowBrick.Operation(Brick::Down);
		NowLine++;
	}

	return countDeleteLine;
}
int Player::addLine(int CountLine) {
	static int Bas = (1 << RIGHT_LIM - LEFT_LIM + 1) - 2;
	if (GameOver)
		return 0;
	for (int i = UP_LIM; i <= DOWN_LIM - CountLine; i++)
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++)
			MapSqure[i][j] = MapSqure[i + CountLine][j];
	/*
	Move all of the map up.
	*/
	for (int i = DOWN_LIM, j = 1; j <= CountLine; i--, j++) {
		int State = rand() % Bas + 1;
		for (int j = LEFT_LIM; j <= RIGHT_LIM; j++, State >>= 1)
			MapSqure[i][j] = (State & 1);
	}
	/*
	Built the first CounLine lines randomly.
	*/
	int CountDeleteLine = 0;
	if (isOverlap()) {
		while (isOverlap())
			NowBrick.Operation(Brick::Up);
	}
	if (touchBottom()) {
		addToMap();
		CountDeleteLine = renewBrick();
	}
	/*
	Move the working brick up if it overlaps the map.
	And check out whether it is touches the bottom.
	*/
	if (touchCeiling()) {
		GameOver = 1;
		return 0;
	}
	return CountDeleteLine;
}
int Player::run(int Direction) {
	if (GameOver)
		return 0;
	/*
	The method would not work if the game of this player is over.
	*/
	int CountDeleteLine = 0;
	if (Direction == 0 && touchBottom()) {
		addToMap();
		CountDeleteLine = renewBrick();
		/*
		It will just add the brick to the map, if the brick is touching the bottom and the command order it falls down 1 cells.
		*/
	}
	else {
		if (!carryCommand(Direction))
			return 0;
		/*
		The invalid carring means that there is nothing changed in the map.
		*/
		if (Direction == Brick::Down && touchBottom()) {
			addToMap();
			CountDeleteLine = renewBrick();
			/*
			It will not be added to the map, if the brick isn't touches the bottom or the command doesn't order it falls down quickly.
			*/
		}
	}
	if (touchCeiling()) {
		GameOver = 1;
		return 0;
	}
	return CountDeleteLine;
}
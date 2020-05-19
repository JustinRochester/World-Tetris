#include"Player.h"

Player::Player(bool StartGame) {
	CountScore = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 30; j++)
			MapSqure[i][j] = 0;
	GameOver = !StartGame;
}
void Player::setName(const std::string& Name_) {
	Name = Name_;
}
bool Player::isOverlap(){
	
}
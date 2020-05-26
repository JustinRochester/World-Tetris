#ifndef DEBUG
	#define DEBUG
#endif // !DEBUG

#include"Player.h"
#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<conio.h>
using namespace std;

void display(Player &p){
	system("cls");

	if (p.GameOver) {
		cout << "GameOver!" << endl;
		return;
	}

	int Map[32][12] = { 0 };
	for (int i = Player::UP_LIM; i <= Player::DOWN_LIM; i++)
		for (int j = Player::LEFT_LIM; j <= Player::RIGHT_LIM; j++)
			if(p.MapSqure[i][j])
				Map[i][j]=1;
	
	int* Information = p.NowBrick.getInformation();

	for (int i = 1; i < 9; i += 2)
		Map[Information[i]][Information[i + 1]] = 2;

	cout << p.Name << endl << *Information << endl;
	for (int i = 11; i <= Player::DOWN_LIM; i++) {
		printf("%d\t|", i-10);
		for (int j = Player::LEFT_LIM; j <= Player::RIGHT_LIM; j++)
			if (!Map[i][j]) putchar(' ');
			else if (Map[i][j] == 2) putchar('*');
			else putchar('o');
		putchar('|');
		putchar('\n');
	}
	putchar('\t');
	for (int j = Player::LEFT_LIM; j <= Player::RIGHT_LIM; j++)
		putchar('-');
	putchar('\n');

	for (int i = 1; i < 9; i += 2)
		cout << endl << Information[i] << " " << Information[i + 1];

	cout << endl;
	return;
}

const char UP = 72;
const char DOWN = 80;
const char LEFT = 75;
const char RIGHT = 77;
const char DERECTION = 224;
const char ESC = 0x1b;
const char BLANK = 32;
const char BACK = 8;

Player p1(1);
int main() {
	srand(time(0));
	p1.setName("player_test");
	char c;
	display(p1);
	while ((c = _getch()) != ESC) {
		if (c == BLANK) {
			p1.run(0);
			display(p1);
			continue;
		}
		if (c == BACK) {
			int T=p1.addLine(3);
			display(p1);
			cout << T << endl;
			continue;
		}
		if (c != DERECTION) continue;
		c = _getch();
		if (0);
		else if (c == UP) p1.run(Brick::Rotate);
		else if (c == DOWN) p1.run(Brick::Down);
		else if (c == LEFT) p1.run(Brick::Left);
		else if (c == RIGHT) p1.run(Brick::Right);
		display(p1);
	}
	return 0;
}
#include"Game.h"
#include"Player.h"
#include<ctime>
#include<cstdlib>
#include<Windows.h>
#include<iostream>
using namespace std;
Game* g;
int main() {
	srand(time(0));
	g = new Game();
	g->run();
	return 0;
}
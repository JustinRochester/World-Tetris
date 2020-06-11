#include"Game.h"
#include"Player.h"
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;
Game* g;
int main() {
	srand(time(0));
	g = new Game();
	g->run();
	delete g;
	return 0;
}
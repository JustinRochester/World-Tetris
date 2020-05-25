#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Brick.h"
using namespace std;
int c[10][10];



void init(Brick a) {
	memset(c, 0, sizeof(c));
	int *b = a.getInformation();
	cout << "color: " << b[0] << endl;
	for (int i = 1; i <= 7; i += 2)
		c[b[i]][b[i + 1]] = 1;
}
void out() {
	for (int i = 3; i <= 8; ++i) {
		for (int j = 3; j <= 8; ++j) {
			if (c[i][j])
				cout << "*";
			else
				cout << "#";
		}
		cout << endl;
	}
	cout << endl;
}
void testleft(Brick a) {
	cout << "testleft" << endl;
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	a.Operation(Brick::Left);
	init(a);
	out();
	cout << "------------------------------------" << endl;
}
void testright(Brick a) {
	cout << "testright" << endl;
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	a.Operation(Brick::Right);
	init(a);
	out();
	cout << "------------------------------------" << endl;
}
void testup(Brick a) {
	cout << "testup" << endl;
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	a.Operation(Brick::Up);
	init(a);
	out();
	cout << "------------------------------------" << endl;
}
void testdown(Brick a) {
	cout << "testdown" << endl;
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	a.Operation(Brick::Down);
	init(a);
	out();
	cout << "------------------------------------" << endl;
}
void testupdate(Brick a) {
	cout << "testupdate" << endl;
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	cout << "------------------------------------" << endl;
}
void testrotate(Brick a) {
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	cout << "testrotate" << endl;
	for (int i = 1; i <= 4; ++i) {
		init(a);
		out();
		a.Operation(Brick::Rotate);
	}
	cout << "------------------------------------" << endl;
}
void testleftandrote(Brick a) {
	a.Operation(Brick::Update);
	a.brickSet(5, 5);
	init(a);
	out();
	a.Operation(Brick::Up);
	init(a);
	out();
	a.Operation(Brick::Rotate);
	init(a);
	out();

}
void test(Brick a) {
	testleftandrote(a);
}
int main() {
	srand(time(0));
	Brick a;
	test(a);
	getchar();
	return 0;
}
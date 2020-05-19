#include"Player.h"
#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	Player p1;
	p1.setName(s);
	return 0;
}
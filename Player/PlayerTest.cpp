#include"Player.h"
#include<iostream>
#include<string>
using namespace std;

Player p1;
int main() {
	string s;
	cin >> s;
	p1.setName(s);
	return 0;
}
#include<iostream>
#include<fstream>
#include<string>
#ifndef _FILERECODER
#define _FILERECODER
class Game;
class FileRecoder {
private:
	static const std::string Suffix, FileName[11];

	std::string NamePlayer[2], NameRecoder[10];
	int ScoreRecoder[10];
	int OperationMode, IsBackgroundMusicOn, IsSoundEffect;

	friend class Game;

public:
	void clearRecord(int);
	void update(int, int, int);
	void outputData();
	FileRecoder();
	~FileRecoder();
};
#endif
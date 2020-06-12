#include"FileRecoder.h"

const std::string FileRecoder::Suffix = ".world-tetris";
const std::string FileRecoder::FileName[] = {
	"Single",
	"SingleAddline",
	"SingleSpeedup",
	"SingleAddlineSpeedup",
	"Couple",
	"CoupleAddline",
	"CoupleSpeedup",
	"CoupleAddlineSpeedup",
	"CoupleChange",
	"CoupleChangeSpeedup",
	"Setting"
};

void FileRecoder::update(int GameMode, int PlayerState, int Score) {
	if (Score <= ScoreRecoder[GameMode])
		return;
	ScoreRecoder[GameMode] = Score;
	if (0);
	else if (PlayerState == 1) NameRecoder[GameMode] = NamePlayer[0];
	else if (PlayerState == 2) NameRecoder[GameMode] = NamePlayer[1];
	else if (PlayerState == 3) NameRecoder[GameMode] = NamePlayer[0] + " & " + NamePlayer[1];
	outputData();
}

void FileRecoder::clearRecord(int GameMode) {
	NameRecoder[GameMode] = "Nobody";
	ScoreRecoder[GameMode] = -1;
	outputData();
}

FileRecoder::FileRecoder() {
	std::fstream iofile;
	for (int i = 0; i < 10; i++) {
		iofile.open((FileName[i] + Suffix).c_str(), std::ios::in);
		if (!iofile.is_open()) {
			iofile.open((FileName[i] + Suffix).c_str(), std::ios::out);
			iofile << "Nobody" << std::endl << -1 << std::endl;
			iofile.close();
			iofile.open((FileName[i] + Suffix).c_str(), std::ios::in);
		}
		getline(iofile, NameRecoder[i]);
		iofile >> ScoreRecoder[i];
		iofile.close();
	}

	iofile.open((FileName[10] + Suffix).c_str(), std::ios::in);
	if (!iofile.is_open()) {
		iofile.open((FileName[10] + Suffix).c_str(), std::ios::out);
		iofile << "Player1" << std::endl << "Player2" << std::endl;
		iofile << 0 << std::endl << 1 << std::endl << 1 << std::endl << 1 << std::endl;
		iofile.close();
		iofile.open((FileName[10] + Suffix).c_str(), std::ios::in);
	}
	getline(iofile, NamePlayer[0]);
	getline(iofile, NamePlayer[1]);
	iofile >> OperationMode >> IsBackgroundMusicOn >> IsKeySound >> IsTouchSound;
	iofile.close();
}

void FileRecoder::outputData() {
	std::fstream iofile;
	for (int i = 0; i < 10; i++) {
		iofile.open((FileName[i] + Suffix).c_str(), std::ios::out);
		iofile << NameRecoder[i]<<std::endl<<ScoreRecoder[i]<<std::endl;
		iofile.close();
	}

	iofile.open((FileName[10] + Suffix).c_str(), std::ios::out);
	iofile << NamePlayer[0] << std::endl << NamePlayer[1] << std::endl;
	iofile << OperationMode << std::endl << IsBackgroundMusicOn << std::endl << IsKeySound << std::endl << IsTouchSound << std::endl;
	iofile.close();
}

FileRecoder::~FileRecoder() {
	outputData();
}
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
	else if (PlayerState == 3) NameRecoder[GameMode] = NamePlayer[0] + "&" + NamePlayer[1];
	outputData();
}

FileRecoder::FileRecoder() {
	std::string tmp="Nobody 0";
	std::fstream iofile;
	for (int i = 0; i < 10; i++) {
		iofile.open((FileName[i] + Suffix).c_str(), std::ios::in);
		if (!iofile.is_open()) {
			iofile.open((FileName[i] + Suffix).c_str(), std::ios::out);
			iofile << tmp;
			iofile.close();
			iofile.open((FileName[i] + Suffix).c_str(), std::ios::in);
		}
		iofile >> NameRecoder[i] >> ScoreRecoder[i];
		iofile.close();
	}

	tmp = "Player1 Player2 0";
	iofile.open((FileName[10] + Suffix).c_str(), std::ios::in);
	if (!iofile.is_open()) {
		iofile.open((FileName[10] + Suffix).c_str(), std::ios::out);
		iofile << tmp;
		iofile.close();
		iofile.open((FileName[10] + Suffix).c_str(), std::ios::in);
	}
	iofile >> NamePlayer[0] >> NamePlayer[1] >> OperationMode;
	iofile.close();
}

void FileRecoder::outputData() {
	std::fstream iofile;
	for (int i = 0; i < 10; i++) {
		iofile.open((FileName[i] + Suffix).c_str(), std::ios::out);
		iofile << NameRecoder[i]<<" "<<ScoreRecoder[i];
		iofile.close();
	}

	iofile.open((FileName[10] + Suffix).c_str(), std::ios::out);
	for (int i = 0; i < 2; i++)
		iofile << NamePlayer[i] << " ";
	iofile << OperationMode << std::endl;
	iofile.close();
}

FileRecoder::~FileRecoder() {
	outputData();
}
#include <string>

#ifndef PlaySound_123456
#define PlaySound_123456

class PlayMusic {
public:
	bool Stop = false;
	std::string filepath = "";
	std::string Open = "";
	std::string Close = "CLOSE MUSIC";
	std::string Status = "status MUSIC mode";
	std::string Play = "PLAY MUSIC FROM 0";
	int times = 0x3f3f3f3f;
public:
	static unsigned int WINAPI ThreadFunc(LPVOID lpParam);
	void PlaySoundEffect(std::string path, int times);
	void PlaySoundEffect(std::string path);
	void StopSoundEffect();
};
#endif

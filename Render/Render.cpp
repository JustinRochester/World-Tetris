#include"Render.h"
#include<windows.h>
#include<iostream>
#include<cstring>
using namespace std;

void Render::SetTitle() {
	string Title = "我罗斯方块哒^^";
	SetConsoleTitle(Title.c_str());
}
void Render::HideCursor() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

const char Render::GameMap1[1000]= { "■■■■■■■■■■■■        ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n■                    ■        ☆                          ☆\n■                    ■        ☆分数：                    ☆\n■                    ■        ☆                          ☆\n■                    ■        ☆                          ☆\n■                    ■        ☆下一图形：                ☆\n■                    ■        ☆                          ☆\n■                    ■        ☆                          ☆\n■                    ■        ☆                          ☆\n■                    ■        ☆                          ☆\n■                    ■        ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■                    ■\n■■■■■■■■■■■■\n" };
const char Render::GameMap2[2500] = { "☆☆☆☆☆☆☆☆☆☆☆☆☆☆■■■■■■■■■■■■        ■■■■■■■■■■■■  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆分数：                  ☆■                    ■        ■                    ■  ☆分数：                    ☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆下一图形：              ☆■                    ■        ■                    ■  ☆下一图形：                ☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆                        ☆■                    ■        ■                    ■  ☆                          ☆\n☆☆☆☆☆☆☆☆☆☆☆☆☆☆■                    ■        ■                    ■  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■                    ■        ■                    ■\n                            ■■■■■■■■■■■■        ■■■■■■■■■■■■\n" };

void Render::DrawGameMap(int CountPlayer) {
	system("cls");
	SetColor(5);
	if (0);
	else if (CountPlayer == 1)
		fwrite(GameMap1, 1, sizeof(GameMap1), stdout);
	else if (CountPlayer == 2)
		fwrite(GameMap2, 1, sizeof(GameMap2), stdout);
}

void SetPos(short i, short j)			//控制光标位置 列 行

{

	COORD pos={i,j};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}


void Render::Setting(int Cur, bool SettingProperties[],int CountProperties) {
	static char SettingUI[] = { "◆■■■■■■■■■■\n■                  ■\n■    允许长按：    ■\n■                  ■\n■    背景音乐：    ■\n■                  ■\n■    按键音效：    ■\n■                  ■\n■    触底音效：    ■\n■                  ■\n■    返回          ■\n■                  ■\n■■■■■■■■■■◆\n" };
	system("cls");
	fwrite(SettingUI, 1, sizeof(SettingUI), stdout);
	for (int i = 0; i < CountProperties; i++) {
		SetPos(16, 2 * i + 2);
		if (SettingProperties[i] == 1) fwrite("是", 1, 2, stdout);
		else fwrite("否", 1, 2, stdout);
	}
	SetPos(4, 2 * Cur + 2);
	fwrite(">>", 1, 2, stdout);
}

void Render::Welcome(int Cur)	//游戏刚进去的界面	
{
	static char welcomeUI[] = { "◆■■■■■■■■\n■              ■\n■  我罗斯方块  ■\n■              ■\n■■■■■■■■■\n■              ■\n■   开始游戏   ■\n■              ■\n■   修改名称   ■\n■              ■\n■   操作说明   ■\n■              ■\n■   开发人员   ■\n■              ■\n■   相关设置   ■\n■              ■\n■   退出游戏   ■\n■              ■\n■■■■■■■■◆\n" };
	system("cls");
	SetColor(3);
	/*if (Cur == 0) {
		welcomeUI[117] = welcomeUI[118] = '>';
	}
	else if (Cur == 1) {
		welcomeUI[155] = welcomeUI[156] = '>';
	}
	else if (Cur == 2) {
		welcomeUI[193] = welcomeUI[194] = '>';
	}
	else if (Cur == 3) {
		welcomeUI[231] = welcomeUI[232] = '>';
	}*/
	fwrite(welcomeUI, 1, sizeof(welcomeUI), stdout);
	SetPos(3, 6+Cur*2);
	fwrite(">>", 1, 2, stdout);
}
void Render::Explain()
{
	system("cls");
	SetColor(3);
	cout << "◆■■■■■■■■■■■■■■■■" << endl;
	cout << "■                              ■" << endl;
	cout << "■                              ■" << endl;
	cout << "■      单人模式                ■" << endl;
	cout << "■                              ■" << endl;
	cout << "■       ↑ & w - 旋转\t\t■" << endl;
	cout << "■       ↓ & s - 速降\t\t■" << endl;
	cout << "■      ← & a - 左移\t\t■" << endl;
	cout << "■      → & d - 右移\t\t■" << endl;
	cout << "■       pause - 暂停\t\t■" << endl;
	cout << "■                              ■" << endl;
	cout << "■                              ■" << endl;
	cout << "■■■■■■■■■■■■■■■■◆" << endl;
	cout << endl;
	cout << "◆■■■■■■■■■■■■■■■■" << endl;
	cout << "■                              ■" << endl;
	cout << "■                              ■" << endl;
	cout << "■   双人模式                   ■" << endl;
	cout << "■                              ■" << endl;
	cout << "■    ↑ - 旋转\tw - 旋转\t■" << endl;
	cout << "■    ↓ - 速降\ts - 速降\t■" << endl;
	cout << "■   → - 右移\td - 右移\t■" << endl;
	cout << "■   ← - 左移\ta - 左移\t■" << endl;
	cout << "■       pause - 暂停\t\t■" << endl;
	cout << "■                              ■" << endl;
	cout << "■                              ■" << endl;
	cout << "■■■■■■■■■■■■■■■■◆" << endl;
	cout << endl;
	cout << ">> ^返回^" << endl;
}
void Render::GameModeMenu(int Cur)
{
	system("cls");
	SetColor(3);
	std::cout << "◆■■■■■■■■■■■■■■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■      请选择游戏模式      ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■ ( ESC 键可退回开始界面)  ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((0 == Cur) * '>') << char((0 == Cur) * '>') << " " << "0.单人修仙" << "         ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((1 == Cur) * '>') << char((1 == Cur) * '>') << " " << "1.单人加行" << "         ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((2 == Cur) * '>') << char((2 == Cur) * '>') << " " << "2.单人加速" << "         ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((3 == Cur) * '>') << char((3 == Cur) * '>') << " " << "3.单人加行加速" << "     ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((4 == Cur) * '>') << char((4 == Cur) * '>') << " " << "4.双人修仙" << "         ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((5 == Cur) * '>') << char((5 == Cur) * '>') << " " << "5.双人加行" << "         ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((6 == Cur) * '>') << char((6 == Cur) * '>') << " " << "6.双人加速" << "         ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((7 == Cur) * '>') << char((7 == Cur) * '>') << " " << "7.双人加行加速" << "     ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((8 == Cur) * '>') << char((8 == Cur) * '>') << " " << "8.双人此消彼长" << "     ■" << std::endl;

	std::cout << "■                          ■" << std::endl;

	std::cout << "■    " << char((9 == Cur) * '>') << char((9 == Cur) * '>') << " " << "9.双人此消彼长加速" << " ■" << std::endl;

	std::cout << "■                          ■" << std::endl;
	std::cout << "■                          ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■◆" << std::endl;
}
void Render::Participants()
{
	system("cls");
	SetColor(3);
	cout << "◆■■■■■■■■■■■■■■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■  程序开发参与人员：      ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■    JustinRochester       ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■    Taj426                ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■    fzuliaoliao           ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■  特别感谢：              ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■    yingluosanqian        ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■■■■■■■■■■■■■■◆" << endl;
	cout << endl;
	cout << endl;
	cout << ">> ^返回^" << endl;
}
void Render::helpText(int GameMode)
{
	system("cls");
	SetColor(5);
	cout << endl;
	Sleep(1000);
	cout << "  当你们看见方块掉落时，什么都不要干，就这么看着它。" << endl << endl;
	Sleep(1500);
	cout << "  谁先顶到天花板，谁就赢了。" << endl;
	Sleep(1000);
	cout << endl;

	SetColor(3);
	cout << "  如果你们乱动方块，会把填满的行消掉。我们会记录你们的分数：" << endl << endl;
	
	cout << "\t消除 1 行，记录 10 分" << endl << endl;

	cout << "\t消除 2 行，记录 30 分" << endl << endl;

	cout << "\t消除 3 行，记录 60 分" << endl << endl;

	cout << "\t消除 4 行，记录 100 分" << endl << endl;

	cout << endl;

	if (GameMode == 2 || GameMode == 3 || GameMode == 6 || GameMode == 7 || GameMode == 9) {

		cout << "  为了让你消行了还能顶到天花板，每加 10 分，方块下落会变快一次，直至上限" << endl;

		cout << endl;

	}

	if (GameMode == 8 || GameMode == 9) {

		cout << "  同时，为了方便你的朋友顶到天花板。你每次消除一行，你的朋友就会增加一行" << endl;

		cout << endl;

	}

	if (GameMode == 1 || GameMode == 3 || GameMode == 5 || GameMode == 7) {

		cout << "  为了方便你们顶到天花板，每次方块下落有 1% 的概率触发加行 buff :" << endl << endl;
	
		cout << "\t其中有 40% 的概率增加 1 行" << endl << endl;
	
		cout << "\t其中有 30% 的概率增加 2 行" << endl << endl;
	
		cout << "\t其中有 20% 的概率增加 3 行" << endl << endl;

		cout << "\t其中有 10% 的概率增加 4 行" << endl << endl;

		cout << endl;

	}

	cout << endl;

	cout << ">> ^返回^" << endl;

}

void Render::reName(const string& Name1, const string& Name2, int Cur) {
	system("cls");
	SetColor(3);

	cout << "◆■■■■■■■■■■■■■■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 0)
		cout << "■ >> 玩家1：               ■" << endl;
	else
		cout << "■    玩家1：               ■" << endl;
	cout << "■                          ■" << endl;

	if (Cur == 1)
		cout << "■ >> 玩家1：               ■" << endl;
	else
		cout << "■    玩家1：               ■" << endl;
	cout << "■                          ■" << endl;

	if (Cur == 2)
		cout << "■ >> 返回                  ■" << endl;
	else
		cout << "■    返回                  ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■■■■■■■■■■■■■■◆" << endl;

	SetPos(13, 2);
	cout << Name1;
	SetPos(13, 4);
	cout << Name2;
}

void Render::reName(const string& Name1, const string& Name2) {
	system("cls");
	SetColor(3);
	cout << "请输入16字符内的新姓名。按 ENTER 键确认，ESC 键返回" << endl;
	cout << endl;
	cout << "原名称：" << Name1 << endl;
	cout << endl;
	cout << "新名称：" << Name2 << endl;
}

void Render::historicRecord(const string& Name, int Score, int Cur) {
	system("cls");
	cout << "◆■■■■■■■■■■■■■■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■■■■■■■■■■■■■■◆" << endl;
	cout << endl;
	if(Cur==0)
		cout << ">> 返回" << endl;
	else
		cout << "   返回" << endl;
	if (Cur == 1)
		cout << ">> 清除记录" << endl;
	else
		cout << "   清除记录" << endl;
	int Pos = 30 - Name.size();
	Pos >>= 1;
	if (Pos & 1) Pos ^= 1;
	SetPos(Pos, 3);
	cout << Name << "：";
	SetPos(13, 4);
	cout << Score << "分";
}

void Render::PreStart(int Cur)
{
	system("cls");
	SetColor(3);
	cout << "◆■■■■■■■■■■■■■■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 0)
	cout << "■      >> 开始游戏         ■" << endl;
	else
	cout << "■         开始游戏         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 1)
		cout << "■      >> 修改名称         ■" << endl;
	else
		cout << "■         修改名称         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 2)
	cout << "■      >> 查看帮助         ■" << endl;
	else
	cout << "■         查看帮助         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 3)
		cout << "■      >> 历史记录         ■" << endl;
	else
		cout << "■         历史记录         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 4)
	cout << "■      >> 更换模式         ■" << endl;
	else
	cout << "■         更换模式         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 5)
	cout << "■      >> 退出游戏         ■" << endl;
	else
	cout << "■         退出游戏         ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■■■■■■■■■■■■■■◆" << endl;
}

void Render::End(int Cur, int num, const string& player1, int score1, const string& player2, int score2)
{
	system("cls");
	SetColor(3);
	cout << "◆■■■■■■■■■■■■■■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■         游戏结束！       ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■           得分           ■" << endl;
	cout << "■                          ■" << endl;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= 3; j++)
			cout << "■                          ■" << endl;
	if (Cur == 0)
	cout << "■      >> 重新游戏         ■" << endl;
	else
	cout << "■         重新游戏         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 1)
	cout << "■      >> 更换模式         ■" << endl;
	else
	cout << "■         更换模式         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 2)
	cout << "■      >> 返回菜单         ■" << endl;
	else
	cout << "■         返回菜单         ■" << endl;
	cout << "■                          ■" << endl;
	if (Cur == 3)
	cout << "■      >> 退出游戏         ■" << endl;
	else
	cout << "■         退出游戏         ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■                          ■" << endl;
	cout << "■■■■■■■■■■■■■■◆" << endl;

	int Pos = 30 - player1.size();
	Pos >>= 1;
	if (Pos & 1) Pos ^= 1;
	SetPos(Pos, 7);
	cout << player1 << "：";
	SetPos(13, 8);
	cout << score1 << "分";
	SetPos(0, 10);
	if (num == 2) {
		Pos = 30 - player2.size();
		Pos >>= 1;
		if (Pos & 1) Pos ^= 1;
		SetPos(Pos, 10);
		cout << player2 << "：";
		SetPos(13, 11);
		cout << score2 << "分";
	}
}

void Render::SetColor(int color_num)//设置颜色

{

	int n;

	switch(color_num)

	{

		case 0: n = 0x08; break;//灰色

		case 1: n = 0x0C; break;//红色

		case 2: n = 0x0D; break;//紫色

		case 3: n = 0x0E; break;//黄色

		case 4: n = 0x0A; break;//绿色

		case 5: n = 0x0F; break;//白色

		case 6: n = 0x09; break;//蓝色

		case 7: n = 0x0B; break;//淡浅绿色

		case 8: n = 0x05; break;//深紫色

		case 9: n = 0x03; break;//浅绿色（有点蓝）

		case 10:n = 0x00; break;//黑色
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);

}

void Render::DrawScore1(int score)				//单人画游戏时界面

{
	SetPos(40, 2);
	SetColor(5);
	printf("%d", score);

	/*int i;

	for (i = 0; i <= 10; i++)

	{

		SetColor(5);

		SetPos(i * 2, 0);

		fwrite("■", 1, 2, stdout);

		SetPos(i * 2, 21);

		fwrite("■", 1, 2, stdout);

	}



	for (i = 0; i <= 21; i++)

	{

		SetColor(5);

		SetPos(0, i);

		fwrite("■", 1, 2, stdout);

		SetPos(11 * 2, i);

		fwrite("■", 1, 2, stdout);

	}



	for (i = 16; i < 30; i++)

	{

		SetColor(0);

		SetPos(i * 2, 0);

		fwrite("☆", 1, 2, stdout);

		SetPos(i * 2, 10);

		fwrite("☆", 1, 2, stdout);

	}



	for (i = 0; i <= 10; i++)

	{

		SetColor(0);

		SetPos(32, i);

		fwrite("☆", 1, 2, stdout);

		SetPos(60, i);

		fwrite("☆", 1, 2, stdout);

	}



	SetPos(34, 2);

	printf("分数：%d", score);

	SetPos(34, 5);

	printf("下一图形：");*/

}

void Render::DrawGame1(int Map[32][12], const int* NowBrick, const int* NextBrick) {
	SetColor(0);
	for (int i = 11; i <= 30; ++i) {
		char LineSqure[32] = { 0 }, * pLine = LineSqure;
		for (int j = 1; j <= 10; j++) {
			if (Map[i][j] == -1)
				strcpy_s(pLine, 3, "■");
			else
				strcpy_s(pLine, 3, "  ");
			pLine += 2;
		}
		SetPos(2, (i - 10));
		fwrite(LineSqure, 1, 20, stdout);
	}
	/*for (int i = 11; i <= 30; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (Map[i][j] == -1) {
				SetColor(0);
				SetPos(2 * j, (i - 10));
				fwrite("■", 1, 2, stdout);
			}
			else if (Map[i][j] > 0) {
				SetColor(Map[i][j]);
				SetPos(2 * j, (i - 10));
				fwrite("■", 1, 2, stdout);
			}
			else {
				SetPos(2 * j, i - 10);
				fwrite("  ", 1, 2, stdout);
			}
		}
	}*/
	SetColor(NowBrick[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NowBrick[i];
		int y = NowBrick[i + 1];
		if (x <= 10) continue;
		SetPos(2 * y, (x - 10));
		fwrite("■", 1, 2, stdout);
	}
	for (int i = 22; i <= 26; ++i) {
		for (int j = 6; j <= 9; ++j) {
			SetPos(2 * i, j);
			fwrite("  ", 1, 2, stdout);
		}
	}
	SetColor(NextBrick[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NextBrick[i] + 5;
		int y = NextBrick[i + 1] + 21;
		SetPos(2 * y, x);
		fwrite("■", 1, 2, stdout);
	}

}



//-1不能移动的方块，0空，1正在移动的方块， 
void Render::DrawScore2(int score1, int score2)				//双人画游戏时界面

{

	SetColor(5);
	SetPos(8, 2);
	printf("%d", score1);
	SetPos(94, 2);
	printf("%d", score2);

	//int i;

	//SetColor(0);

	////第一个计分的人 

	//for (i = 0; i < 13; i++)		//宽13格计分 

	//{

	//	SetColor(0);

	//	SetPos(i * 2, 0);

	//	fwrite("☆", 1, 2, stdout);

	//	SetPos(i * 2, 10);

	//	fwrite("☆", 1, 2, stdout);

	//}



	//for (i = 0; i <= 10; i++)		//高10格计分 

	//{

	//	SetPos(0, i);

	//	fwrite("☆", 1, 2, stdout);

	//	SetPos(13 * 2, i);

	//	fwrite("☆", 1, 2, stdout);

	//}

	////第二个人计分的人 

	//for (i = 43; i < 57; i++)		//宽13格计分 

	//{

	//	SetPos(i * 2, 0);

	//	fwrite("☆", 1, 2, stdout);

	//	SetPos(i * 2, 10);

	//	fwrite("☆", 1, 2, stdout);

	//}



	//for (i = 0; i <= 10; i++)		//高10格计分 

	//{

	//	SetPos(43 * 2, i);

	//	fwrite("☆", 1, 2, stdout);

	//	SetPos(57 * 2, i);

	//	fwrite("☆", 1, 2, stdout);

	//}

	////第一个人的界面 

	//for (i = 14; i < 25; i++)		//宽13格计分 

	//{

	//	SetColor(5);

	//	SetPos(i * 2, 0);

	//	fwrite("■", 1, 2, stdout);

	//	SetPos(i * 2, 21);

	//	fwrite("■", 1, 2, stdout);

	//}

	//for (i = 0; i <= 21; i++)		//高21格计分 

	//{

	//	SetColor(5);

	//	SetPos(50, i);

	//	fwrite("■", 1, 2, stdout);

	//	SetPos(28, i);

	//	fwrite("■", 1, 2, stdout);

	//}

	////第二个人的界面 

	//for (i = 30; i < 42; i++)		//宽13格计分 

	//{

	//	SetColor(5);

	//	SetPos(i * 2, 0);

	//	fwrite("■", 1, 2, stdout);


	//	SetPos(i * 2, 21);

	//	fwrite("■", 1, 2, stdout);

	//}

	//for (i = 0; i < 21; i++)		//高21格计分 

	//{

	//	SetColor(5);

	//	SetPos(60, i);

	//	fwrite("■", 1, 2, stdout);

	//	SetPos(82, i);

	//	fwrite("■", 1, 2, stdout);

	//}



	//SetColor(5);

	////Input_score();

	//SetPos(2, 2);

	//printf("分数：%d", score1);

	//SetPos(2, 5);

	//printf("下一图形：");

	//SetPos(88, 2);

	//printf("分数：%d", score2);

	//SetPos(88, 5);

	//printf("下一图形：");

}

/*Map1 begin (15, 1)
  Map2 begin (31, 1)
*/
void Render::DrawGame2(int Map1[32][12], const int* NowBrick1, const int* NextBrick1,
	int Map2[32][12], const int* NowBrick2, const int* NextBrick2) {
	//player1's map
	SetColor(0);
	for (int i = 11; i <= 30; ++i) {
		char LineSqure1[32] = { 0 }, * pLine1 = LineSqure1;
		char LineSqure2[32] = { 0 }, * pLine2 = LineSqure2;
		for (int j = 1; j <= 10; j++) {
			if (Map1[i][j] == -1)
				strcpy_s(pLine1, 3, "■");
			else
				strcpy_s(pLine1, 3, "  ");
			pLine1 += 2;
		}
		SetPos(30, (i - 10));
		fwrite(LineSqure1, 1, 20, stdout);

		for (int j = 1; j <= 10; j++) {
			if (Map2[i][j] == -1)
				strcpy_s(pLine2, 3, "■");
			else
				strcpy_s(pLine2, 3, "  ");
			pLine2 += 2;
		}
		SetPos(62, (i - 10));
		fwrite(LineSqure2, 1, 20, stdout);
	}
	SetColor(NowBrick1[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NowBrick1[i];
		int y = NowBrick1[i + 1];
		if (x <= 10) continue;
		SetPos(2 * (y + 14), (x - 10));
		fwrite("■", 1, 2, stdout);
	}
	SetColor(NowBrick2[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NowBrick2[i];
		int y = NowBrick2[i + 1];
		if (x <= 10) continue;
		SetPos(2 * (y + 30), (x - 10));
		fwrite("■", 1, 2, stdout);
	}
	//for (int i = 11; i <= 30; ++i) {
	//	for (int j = 1; j <= 10; ++j) {
	//		if (Map1[i][j] == -1)
	//			SetColor(0);
	//		else if (Map1[i][j] == 0)
	//			SetColor(10);
	//		else
	//			SetColor(Map1[i][j]);
	//		SetPos(2 * (j + 14), i - 10);
	//		fwrite("■", 1, 2, stdout);
	//		if (Map2[i][j] == -1)
	//			SetColor(0);
	//		else if (Map2[i][j] == 0)
	//			SetColor(10);
	//		else
	//			SetColor(Map2[i][j]);
	//		SetPos(2 * (j + 30), i - 10);
	//		fwrite("■", 1, 2, stdout);
	//	}
	//}

	////player1's next brick
	for (int i = 6; i <= 9; ++i) {
		for (int j = 6; j <= 9; ++j) {
			SetPos(2 * i, j);
			fwrite("  ", 1, 2, stdout);
		}
	}
	SetColor(NextBrick1[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NextBrick1[i] + 5;
		int y = NextBrick1[i + 1] + 5;
		SetPos(2 * y, x);
		fwrite("■", 1, 2, stdout);
	}
	////7,5
	//for (int i = 6; i <= 9; ++i) {
	//	for (int j = 6; j <= 9; ++j) {
	//		SetPos(2 * i, j);
	//		fwrite("  ", 1, 2, stdout);
	//	}
	//}
	//SetColor(B1[0]);
	//for (int i = 1; i <= 7; i += 2) {
	//	int x = B1[i] + 5;
	//	int y = B1[i + 1] + 5;
	//	SetPos(2 * y, x);
	//	fwrite("■", 1, 2, stdout);
	//}
	////player2's next brick 	
	for (int i = 48; i <= 53; ++i) {
		for (int j = 6; j <= 9; ++j) {
			SetPos(2 * i, j);
			fwrite("  ", 1, 2, stdout);
		}
	}
	SetColor(NextBrick2[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NextBrick2[i] + 5;
		int y = NextBrick2[i + 1] + 48;
		SetPos(2 * y, x);
		fwrite("■", 1, 2, stdout);
	}
	////43,5 
	//for (int i = 48; i <= 53; ++i) {
	//	for (int j = 6; j <= 9; ++j) {
	//		SetPos(2 * i, j);
	//		fwrite("  ", 1, 2, stdout);
	//	}
	//}
	//SetColor(B2[0]);
	//for (int i = 1; i <= 7; i += 2) {
	//	int x = B2[i] + 5;
	//	int y = B2[i + 1] + 48;
	//	SetPos(2 * y, x);
	//	fwrite("■", 1, 2, stdout);
	//}
}

int Render::Len(int n) {
	int ret = 0;
	do {
		n /= 10;
		ret++;
	} while (n);
	return ret;
}
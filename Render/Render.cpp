#include"Render.h"
#include<iostream>
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
void SetPos(short i, short j)			//控制光标位置 列 行

{

	COORD pos={i,j};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}


void Render::Welcome(int Cur)	//游戏刚进去的界面	
{
	system("cls");
	SetColor(3);//设置颜色 
	cout << endl << "   我罗斯方块		" << endl;
	cout << endl;
	SetColor(5);
	cout << "________________" << endl;
	cout << "                >" << endl;
	if (Cur == 0) cout << ">> 开始游戏     >" << endl;
	else cout << "   开始游戏     >" << endl;
	if (Cur == 1) cout << ">> 操作说明     >" << endl;
	else cout << "   操作说明     >" << endl;
	if (Cur == 2) cout << ">> 开发人员信息 >" << endl;
	else cout << "   开发人员信息 >" << endl;
	if (Cur == 3) cout << ">> 退出游戏     >" << endl;
	else cout << "   退出游戏     >" << endl;
	cout << "________________>" << endl;
}
void Render::Explain()
{
	system("cls");
	SetColor(5);
	cout << "_________________________" << endl;
	cout << "\t\t\to" << endl;
	cout << "  单人模式  操作方法\to" << endl;
	cout << "  ↑& w - 旋转\t\to" << endl;
	cout << "  ↓& s - 加速下移\to" << endl;
	cout << "  ←& a - 左移\t\to" << endl;
	cout << "  →& d - 右移\t\to" << endl;
	cout << "________________________o" << endl;
	cout << endl;
	cout << "_________________________________" << endl;
	cout << "\t\t\t\to" << endl;
	cout << "  双人模式 操作方法\t\to" << endl;
	cout << "  ↑ - 旋转	w - 旋转\to" << endl;
	cout << "  ↓ - 加速下移	s - 加速下移\to" << endl;
	cout << "  → - 右移	d - 右移\to" << endl;
	cout << "  ← - 左移	a - 左移\to" << endl;
	cout << "________________________________o" << endl;
	cout << endl;
	cout << endl;
	cout << ">> ^返回^" << endl;
}
void Render::GameModeMenu(int Cur)
{
	system("cls");

	std::cout << "<><><><><><><><><><><><><><><>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>      请选择游戏模式      <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<> ( ESC 键可退回开始界面)  <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((0 == Cur) * '>') << char((0 == Cur) * '>') << " " << "0.单人修仙" << "         <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((1 == Cur) * '>') << char((1 == Cur) * '>') << " " << "1.单人加行" << "         <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((2 == Cur) * '>') << char((2 == Cur) * '>') << " " << "2.单人加速" << "         <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((3 == Cur) * '>') << char((3 == Cur) * '>') << " " << "3.单人加行加速" << "     <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((4 == Cur) * '>') << char((4 == Cur) * '>') << " " << "4.双人修仙" << "         <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((5 == Cur) * '>') << char((5 == Cur) * '>') << " " << "5.双人加行" << "         <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((6 == Cur) * '>') << char((6 == Cur) * '>') << " " << "6.双人加速" << "         <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((7 == Cur) * '>') << char((7 == Cur) * '>') << " " << "7.双人加行加速" << "     <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((8 == Cur) * '>') << char((8 == Cur) * '>') << " " << "8.双人此消彼长" << "     <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<>    " << char((9 == Cur) * '>') << char((9 == Cur) * '>') << " " << "9.双人此消彼长加速" << " <>" << std::endl;

	std::cout << "<>                          <>" << std::endl;

	std::cout << "<><><><><><><><><><><><><><><>" << std::endl;
}
void Render::Participants()
{
	system("cls");
	SetColor(5);
	cout << "程序开发参与人员： JustinRochester" << endl;
	cout << endl;
	cout << "                   Taj426" << endl;
	cout << endl;
	cout << "                   fzuliaoliao" << endl;
	cout << endl;
	cout << "        特别感谢： yingluosanqian" << endl;
	cout << endl;
	cout << ">> ^返回^" << endl;
}
void Render::helpText(int GameMode)
{
	system("cls");
	SetColor(5);
	cout << endl;
	cout << "  当你们看见方块掉落时，什么都不要干，就这么看着它。" << endl;

	cout << "  谁先顶到天花板，谁就赢了。" << endl;

	cout << endl;

	cout << "  如果你们乱动方块，会把填满的行消掉。我们会记录你们的分数：" << endl;

	cout << "\t消除 1 行，记录 10 分" << endl;

	cout << "\t消除 2 行，记录 30 分" << endl;

	cout << "\t消除 3 行，记录 60 分" << endl;

	cout << "\t消除 4 行，记录 100 分" << endl;

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

		cout << "  为了方便你们顶到天花板，每次方块下落有 1% 的概率触发加行 buff :" << endl;

		cout << "\t其中有 40% 的概率增加 1 行" << endl;

		cout << "\t其中有 30% 的概率增加 2 行" << endl;

		cout << "\t其中有 20% 的概率增加 3 行" << endl;

		cout << "\t其中有 10% 的概率增加 4 行" << endl;

		cout << endl;

	}

	cout << endl;

	cout << ">> ^返回^" << endl;

}

void Render::PreStart(int Cur)
{
	system("cls");
	SetColor(5);
	cout << endl;
	if (Cur == 0) cout << "      >> 开始游戏" << endl;
	else cout << "         开始游戏" << endl;
	cout << endl;
	if (Cur == 1) cout << "      >> 查看帮助文档" << endl;
	else cout << "         查看帮助文档" << endl;
	cout << endl;
	if (Cur == 2) cout << "      >> 重选模式" << endl;
	else cout << "         重选模式" << endl;
	cout << endl;
	if (Cur == 3) cout << "      >> 退出游戏" << endl;
	else cout << "         退出游戏" << endl;
}

void Render::End(int Cur, int num, const string& player1, int score1, const string& player2, int score2)
{
	system("cls");
	cout << endl;
	SetColor(3);
	cout << "   游戏已经结束" << endl;
	cout << endl;
	SetColor(5);
	cout << "   " << player1 << ":" << score1 << endl;
	cout << endl;
	if (num > 1) {
		cout << "   " << player2 << ":" << score2 << endl;
		cout << endl;
	}
	cout << endl << endl;
	if (Cur == 0)
		cout << ">> 重新开始游戏" << endl;
	else
		cout << "   重新开始游戏" << endl;
	cout << endl;
	if (Cur == 1)
		cout << ">> 重选游戏模式" << endl;
	else
		cout << "   重选游戏模式" << endl;
	cout << endl;
	if (Cur == 2)
		cout << ">> 返回开始界面" << endl;
	else
		cout << "   返回开始界面" << endl;
	cout << endl;
	if (Cur == 3)
		cout << ">> 退出游戏" << endl;
	else
		cout << "   退出游戏" << endl;
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

void Render::DrawMap1(int score)				//单人画游戏时界面

{

	int i;

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

	printf("下一图形：");

}

void Render::DrawGame1(int Map[32][12], const int* NextBrick) {
	for (int i = 11; i <= 30; ++i) {
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
void Render::DrawMap2(int score1, int score2)				//双人画游戏时界面

{

	int i;

	SetColor(0);

	//第一个计分的人 

	for (i = 0; i < 13; i++)		//宽13格计分 

	{

		SetColor(0);

		SetPos(i * 2, 0);

		fwrite("☆", 1, 2, stdout);

		SetPos(i * 2, 10);

		fwrite("☆", 1, 2, stdout);

	}



	for (i = 0; i <= 10; i++)		//高10格计分 

	{

		SetPos(0, i);

		fwrite("☆", 1, 2, stdout);

		SetPos(13 * 2, i);

		fwrite("☆", 1, 2, stdout);

	}

	//第二个人计分的人 

	for (i = 43; i < 57; i++)		//宽13格计分 

	{

		SetPos(i * 2, 0);

		fwrite("☆", 1, 2, stdout);

		SetPos(i * 2, 10);

		fwrite("☆", 1, 2, stdout);

	}



	for (i = 0; i <= 10; i++)		//高10格计分 

	{

		SetPos(43 * 2, i);

		fwrite("☆", 1, 2, stdout);

		SetPos(57 * 2, i);

		fwrite("☆", 1, 2, stdout);

	}

	//第一个人的界面 

	for (i = 14; i < 25; i++)		//宽13格计分 

	{

		SetColor(5);

		SetPos(i * 2, 0);

		fwrite("■", 1, 2, stdout);

		SetPos(i * 2, 21);

		fwrite("■", 1, 2, stdout);

	}

	for (i = 0; i <= 21; i++)		//高21格计分 

	{

		SetColor(5);

		SetPos(50, i);

		fwrite("■", 1, 2, stdout);

		SetPos(28, i);

		fwrite("■", 1, 2, stdout);

	}

	//第二个人的界面 

	for (i = 30; i < 42; i++)		//宽13格计分 

	{

		SetColor(5);

		SetPos(i * 2, 0);

		fwrite("■", 1, 2, stdout);


		SetPos(i * 2, 21);

		fwrite("■", 1, 2, stdout);

	}

	for (i = 0; i < 21; i++)		//高21格计分 

	{

		SetColor(5);

		SetPos(60, i);

		fwrite("■", 1, 2, stdout);

		SetPos(82, i);

		fwrite("■", 1, 2, stdout);

	}



	SetColor(5);

	//Input_score();

	SetPos(2, 2);

	printf("分数：%d", score1);

	SetPos(2, 5);

	printf("下一图形：");

	SetPos(88, 2);

	printf("分数：%d", score2);

	SetPos(88, 5);

	printf("下一图形：");

}

/*Map1 begin (15, 1)
  Map2 begin (31, 1)
*/
void Render::DrawGame2(int Map1[32][12], const int* B1, int Map2[32][12], const int* B2) {
	//player1's map
	for (int i = 11; i <= 30; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (Map1[i][j] == -1)
				SetColor(0);
			else if (Map1[i][j] == 0)
				SetColor(10);
			else
				SetColor(Map1[i][j]);
			SetPos(2 * (j + 14), i - 10);
			fwrite("■", 1, 2, stdout);
			if (Map2[i][j] == -1)
				SetColor(0);
			else if (Map2[i][j] == 0)
				SetColor(10);
			else
				SetColor(Map2[i][j]);
			SetPos(2 * (j + 30), i - 10);
			fwrite("■", 1, 2, stdout);
		}
	}

	//player1's next brick
	//7,5
	for (int i = 6; i <= 9; ++i) {
		for (int j = 6; j <= 9; ++j) {
			SetPos(2 * i, j);
			fwrite("  ", 1, 2, stdout);
		}
	}
	SetColor(B1[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = B1[i] + 5;
		int y = B1[i + 1] + 5;
		SetPos(2 * y, x);
		fwrite("■", 1, 2, stdout);
	}
	//player2's next brick 	
	//43,5 
	for (int i = 48; i <= 53; ++i) {
		for (int j = 6; j <= 9; ++j) {
			SetPos(2 * i, j);
			fwrite("  ", 1, 2, stdout);
		}
	}
	SetColor(B2[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = B2[i] + 5;
		int y = B2[i + 1] + 48;
		SetPos(2 * y, x);
		fwrite("■", 1, 2, stdout);
	}
}
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


void Render::Welcome()	//游戏刚进去的界面	

{

	SetColor(3);//设置颜色 

	char x;

	while(1)

	{

		system("cls");

		cout <<"		俄罗斯方块		" << endl;

		cout << "操作方式：" << endl;

		cout <<"单人				双人"<<endl; 

		cout << "↑ - 旋转			w - 旋转" << endl;

		cout << "↓ - 加速下移			s - 加速下移"  << endl;

		cout << "← - 左移			a - 左移" << endl;

		cout << "→ - 右移			d - 右移" << endl;

		cout <<"按1选择单人模式-按2选择双人模式" << endl;

		SetPos(20, 10);//控制光标位置， 列， 行

		x = getchar();

		if(x <= '9' && x >= '0')

		{

			type = x - '0';//模式 

			break;

		}

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

void Render::DrawMap1(int score)				//单人画游戏时界面

{

	int i;

	for(i = 0; i <= 10; i++)	

	{

		SetColor(5);

		SetPos(i * 2, 0);

		cout << "■";

		SetPos(i * 2, 21);

		cout << "■";

	}

	

	for(i = 0; i <= 21; i++) 

	{

		SetColor(5);

		SetPos(0, i);

		cout << "■";

		SetPos(11*2, i);

		cout << "■";

	}

	

	for(i = 16; i < 30; i++)		

	{

		SetColor(0);

		SetPos(i * 2, 0);

		cout << "☆";

		SetPos(i * 2, 10);

		cout << "☆";

	}

	

	for(i = 0; i <= 10; i++)	

	{

		SetColor(0);

		SetPos(32, i);

		cout << "☆";

		SetPos(60, i);

		cout << "☆";

	}

	

	SetPos(34, 2);

	cout << "分数: " << score; 

	SetPos(34, 5);

	cout << "下一图形:";

 } 

void Render::DrawGame1(int Map[32][12], int BrickCol, const int* NextBrick) {
	for (int i = 11; i <= 30; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (Map[i][j] == -1) {
				SetColor(0);
				SetPos(2 * j, (i - 10));
				cout << "■";
			}
			else if (Map[i][j] == 1) {
				SetColor(BrickCol);
				SetPos(2 * j, (i - 10));
				cout << "■";
			}
			else {
				SetPos(2 * j, i - 10);
				cout << "  ";
			}
		}
	}
	for (int i = 22; i <= 26; ++i) {
		for (int j = 6; j <= 9; ++j) {
			SetPos(2 * i, j);
			cout << "  ";
		}
	}
	SetColor(NextBrick[0]);
	for (int i = 1; i <= 7; i += 2) {
		int x = NextBrick[i] + 5;
		int y = NextBrick[i + 1] + 21;
		SetPos(2 * y, x);
		cout << "■";
	}

}



//-1不能移动的方块，0空，1正在移动的方块， 
void Render::DrawMap2(int score1, int score2)				//双人画游戏时界面

{

	int i;

	SetColor(0);

//第一个计分的人 

	for(i = 0; i < 13; i++)		//宽13格计分 

	{

		SetColor(0);

		SetPos(i * 2, 0);

		cout << "☆";

		SetPos(i * 2, 10);

		cout << "☆";

	}

	

	for(i = 0; i <= 10; i++)		//高10格计分 

	{

		SetPos(0, i);

		cout << "☆";

		SetPos(13*2, i);

		cout << "☆";

	}

//第二个人计分的人 

	for(i = 43; i < 57; i++)		//宽13格计分 

	{

		SetPos(i * 2, 0);

		cout << "☆";

		SetPos(i * 2, 10);

		cout << "☆";

	}

	

	for(i = 0; i <= 10; i++)		//高10格计分 

	{

		SetPos(43*2, i);

		cout << "☆";

		SetPos(57*2, i);

		cout << "☆";

	}

//第一个人的界面 

	for(i = 14; i < 25; i++)		//宽13格计分 

	{

		SetColor(5);

		SetPos(i * 2, 21);

		cout << "■";

	}

	for(i = 0; i <= 21; i++)		//高21格计分 

	{

		SetColor(5);

		SetPos(50, i);

		cout << "■";

		SetPos(28, i);

		cout << "■";

	}

//第二个人的界面 

	for(i = 30; i < 42; i++)		//宽13格计分 

	{

		SetColor(5);

		SetPos(i * 2, 21);

		cout << "■";

	}

	for(i = 0; i <21; i++)		//高21格计分 

	{

		SetColor(5);

		SetPos(60, i);

		cout << "■";

		SetPos(82, i);

		cout << "■";

	}



	SetColor(3);

	//Input_score();

	SetPos(2, 2);

	cout << "分数: " << score1; 

	SetPos(2, 5);

	cout << "下一图形:";

	SetPos(88, 2);

	cout << "分数: " << score2; 

	SetPos(88, 5);

	cout << "下一图形:";

} 



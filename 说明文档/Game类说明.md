# 游戏类

(更新中)

##源码

```cpp
class Game {
private:
	Player *player[2];
	Render render;
	int GameMode,CountPlayer;
	static int FramesCount, FramesTime;
	static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER;

	void welcome();
	void carryCommand(char c);
	void setGameMode();
	void play();

public:	
	Game();	
	~Game();
	void run();
	void renderMap();
}; 
```

---

##属性说明

```cpp
int GameMode;
```

游戏模式

```cpp
int CountPlayer;
```

游戏的人数

```cpp
static int FramesCount;
```

上一次下落一格后，到现在经历的帧数（感觉可以去掉 static 修饰）

```cpp
static int FramesTime;
```

每一帧的时间


```cpp
static const char ESC, LEFT, RIGHT, UP, DOWN, DIRECTIONS, ENTER;
```

对应按键的 ASCII 码

---

##方法说明

###欢迎/帮助界面

```cpp
void welcome();
```

暂未实现

---

###执行指令

```cpp
void carryCommand(char c);
```

> 执行合法的指令

实现参考

```cpp
if(c==DIRECTIONS)
    c=_getch();
//方向键由两个 ASCII 码保存，其中第一位相同
if(legalCommand(c)){
    if(CountPlayer==1||fist_player_order(c))
        player[1]->run();
    else
        player[2]->run();
}
```

---

###设置游戏模式

```cpp
void setGameMode();
```

实现参考

```cpp
delete player[0];
delete player[1];
char c;
while(!isLegalGameMode())
    c=_getch();
setMode(c){
    CountPlayer=;
    GameMode=;
}

for(i->0:1)
    if(i<CountPlayer)
        player[i]=new Player(StartGame=true);
    else
        player[i]=new Player(StartGame=false);
```

---

###运行单次游戏

```cpp
void play();
```

(目前已处理好单人部分)

实现参考

```cpp
int FlamesLimit=10;
//满多少帧后下落一格
player[0]->setName();
player[1]->setName();
for(time){
    if(_kbhit()){
        carryCommand(_getch());
        Sleep_to_supply_time();
    }
    Sleep_to_supply_time();
    //用睡眠来保证程序每一帧的时间相同

    if(FlamesCount>=FlamesLimit)
        move(down);
    renderMap();
    //渲染
}
```

---

###构造函数

```cpp
Game();	
```

> 两个玩家指针初始化为 NULL

---

###析构函数

```cpp
~Game();
```

> 释放两个玩家指针，并赋值为 NULL

---

###运行游戏

```cpp
void run();
```

实现参考

```cpp
Hide_Cur();//隐藏光标
welcome();
while(notEscape()){
    setGameMode();
    play();
}
```

---

###渲染地图

```cpp
void renderMap();
```

（由于渲染类还会写好，故不提供实现参考）

> 调用渲染类，对地图进行渲染
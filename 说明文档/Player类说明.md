#玩家类

##源码

```cpp
class Player {
private:
	static int UP_LIM, DOWN_LIM, LEFT_LIM, RIGHT_LIM;
	int CountScore;
	bool MapSqure[32][12];
	bool GameOver;
	std::string Name;
	Brick NowBrick, NextBrick;

	bool isOverlap();
	bool carryCommand(int Direction);
	bool touchBottom();
	bool touchCeiling();
	void addToMap();
	int delLine();
	int renewBrick();
	friend void Game::renderMap();

public:
	bool IsGameOver();
	int getScore();
	std::string getName();
	Player(bool StartGame=0);
	void setName(const std::string& Name_);
	int run(int Direction);
	int addLine(int CountLine);
};
```

---

##属性说明

```cpp
static int UP_LIM, DOWN_LIM, LEFT_LIM, RIGHT_LIM;
```

分别表示地图的四个边界

枚举顺序：

```cpp
for(int i=UP_LIM;i<=DOWN_LIM;i++)
    for(int j=LEFT_LIM;j<=RIGHT_LIM;j++)
```

其他属性意义如其名

---

##方法说明


###判重
```cpp
bool isOverlap();
```

实现参考：

```cpp
const int *Tmp=NowBrick.getInformation();
for(int i=1;i<9;i+=2)
    if(MapSqure[ Tmp[i] ][ Tmp[i+1] ])
        return 1;
return 0;
```

---

###执行指令

```cpp
bool carryCommand(int Direction);
```

> 用于执行有效的指令。同时，返回指令是否执行成功

实现参考

```cpp
if(legalCommand){
    move(legalCommand);
    if(!isOverlap())
        return true;
    demove(legalCommand);
    return false;
}
return false;
```

---

###判定触底

```cpp
bool touchBottom();
```

实现参考

```cpp
move(down);
bool Result=isOverlap();
demove(down);
return Result
```

---

###判定触顶

```cpp
bool touchCeiling();
```

>触顶后代表游戏结束

实现参考

```cpp
for(i->1:10)
    for(j->1:10)
        if(MapSqure[i][j])
            return true;
return false;
```

---

###加入地图

```cpp
void addToMap();
```

> 将触底的方块加入地图

实现参考

```cpp
const int *Tmp=NowBrick.getInformation();
for(int i=1;i<=9;i+=2)
    MapSqure[ Tmp[i] ][ Tmp[i+1] ]=1;
```

---

###删行

```cpp
int delLine();
```

> 删除满的行，并返回删除的行数

实现参考

```cpp
int Lines[4],CountDeleteLines=0;
select_lines_which_working_bricks_in();
for(i->0:3)
    if( fullLine(Lines[i]) ){
        delete_this_line(Line[i]);
        CountDeleteLines=0;
    }
for(i->(DOWN_LIM-1):UP_LIM)
    if( !emptyLine(i) )
        while( emptyLine(i+1) )//下一行是空的
            fallDownLine(i);
return CountDeleteLines;
```

---

###更新方块

```cpp
int renewBrick();
```

> 生成新的方块，并设定坐标。用于前一方块触底，故先会执行删行操作，并返回删除的行数

实现参考

```cpp
int countDeleteLines=delLine();
NowBrick=NextBrick;
NextBrick.Operation(update);
NowBrick.setPos(i,mid y)
while(NowBrick.DownLine>10)
    NowBrick.move(down);
```

---

###友元函数：渲染

```cpp
friend void Game::renderMap();
```

描述与实现参考见Game类

---

###是否游戏结束

```cpp
bool IsGameOver();
```

---

###获取分数

```cpp
int getScore();
```

---

###获取姓名

```cpp
std::string getName();
```

---

###设置姓名

```cpp
void setName(const std::string& Name_);
```

---

###构造函数

```cpp
Player(bool StartGame=0);
```

实现参考

```cpp
clear(MapSqure);
NowBrick.Operation(update);
NextBrick.Operation(update);

NowBrick.setPos(i,mid y)
while(NowBrick.DownLine>10)
    NowBrick.move(down);
```

---

###运行指令

```cpp
int run(int Direction);
```

> 运行合法的指令，并返回删除的行数

实现参考

```cpp
if(GameOver)//游戏已经结束，不做修改
    return 0;
int CountDeleteLine = 0;

if (Direction == 0 && touchBottom()) {
    //已经触底的情况下进行下落一格操作
	addToMap();
	CountDeleteLine = renewBrick();
}
else {
	if (!carryCommand(Direction))
		return 0;
    if (Direction == Brick::Down && touchBottom()) {
        //按下后触碰到底边
		addToMap();
		CountDeleteLine = renewBrick();
    }
}
if (touchCeiling()) {
    //判断是否游戏结束
	GameOver = 1;
	return 0;
}
return CountDeleteLine;
```

---

###增加行数

```cpp
int addLine(int CountLine);
```

> 第一次加行后，可能会恰好删除几行，故返回加行的数量。但第二次加行一定不存在删除行的情况（即使出现，也特判处理）

实现方法

```cpp
for( i->UP_LIM:(DOWN_LIM-CountLine) )
    move_line(i)_up(CountLine)

for( i->DOWN_LIM:(DOWN_LIM-CountLine+1) )
    random_line(i)

int CountDeleteLine=0;
if(!isOverlap()){
    while(isOverlap())
        move(up);
}
if(touchBottom()){
    addToMap();
    CountDeleteLine=renewBrick();
}
if(touchCeiling()){
    GameOver=1;
    return 0;
}
return CountDeleteLine;
```
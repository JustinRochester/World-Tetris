计分:long long int score
地图:bool[10][25] map
姓名:string name

bool running:是否游戏还未结束

run():
传入指令->碰撞判定->执行指令->合并方块类
exist map[x][y]=1 ,y>20 =>lost

消行 delLine()：
只考虑四个方块所在的行是否消行

加行 addLine()：
优先把所有地图上移一格，随机一个 0~1022 的 int ，二进制填充一行

---

f(i,1,I,+infty)
游戏类，单位时间内，读入一个队列指令{

玩家1扫一遍，找到第一个有效指令，找不到返回找不到
玩家1执行
玩家1是否消行->玩家2加行
玩家1是否碰到上边界->玩家1结束
玩家1返回对应返回内容

玩家2扫一遍，找到第一个有效指令，找不到返回找不到
玩家2执行
玩家2是否消行->玩家1加行
玩家2是否碰到上边界->玩家2结束
玩家2返回对应返回内容

渲染类渲染
}
如果出现五次单位时间，两个玩家的方块都下降1
如果玩家1、玩家2均结束->结算

碰到上边界：
exist map[x][y]=1 ,y>20 =>lost

玩家从队列中取出指令
如果不违法，则执行
如果出现“下”指令，则清空队列（后续考虑下后还能移动）

---


finished:属性

```cpp
int count;
bool map[10][25];
string name;
bool finished
```

```cpp
addOrder();
finished =bool run(direction,int &count){
    if(finished) return 1;
    if( touchLimit(direction) )//touch left or right
        return 0;
    squre.move(direction)
    if( touchBottom() ){
        addToMap();
        squre=nextsqure;
        nextsqure.update();
    }
    count=delLine();//update map
    return 0;
}
display()//return map,squre,nextsqure
addLine(count)//单人模式不调用
finished =bool touchCeiling(){//游戏结束
    return 1;
}
```
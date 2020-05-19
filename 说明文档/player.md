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
bool map[10][30];
string name;
bool finished
```

```cpp
direction:
up:0
left:1
right:2
down:3
spin:4
bool Alw(direction){
    if(direcion==spin){
        squre.spin();
        if( !isOverlap() )
            return 1;
        squre.spin();
        squre.spin();
        squre.spin();
        return 0;
    }
    if(direction==left||direction==right){
        squre.move(direction);
        for(;;){
            squre.move(direcion^3);
            return 0;
        }
        if( !isOverlap() )
            return 1;
        squre.move(direcion^3);
        return 0;
    }
    if(direction==down){
        while(squre.move(direction),!isOverlap());
        squre.move(direction^3);
        return 1;
    }
}
bool touchBottom(){
    squre.move(down)；
    for(;;){
        squre.move(up);
        return 0;
    }
    if( isOverlap() ){
        squre.move(up);
        return 0;
    }
    return 1;
}
void run(direction,int &count){
    if(finished) return ;
    if( !Alw(direction) )//touch left or right
        return ;
    if( touchBottom() ){
        addToMap();
        count=delLine( squre.getInformation() );//update map

        squre=nextsqure;
        sqrue.setxy(x,y);
        nextsqure.update();

        touchCeiling();
    }
    return 0;
}
friend display()//return map,squre,nextsqure
addLine(count)//单人模式不调用
    addline
    if( isOverlap() )
        while( isOverlap() )
            squre.upmove();
        squre.downmove();
        addToMap();
    touchCeiling();
finished =bool touchCeiling(){//游戏结束
    return 1;
}
```
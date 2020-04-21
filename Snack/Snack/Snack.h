#include<stdio.h>//标准输入输出头文件
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//蛇的最大长度
#define SnackLengthMax 500


//坐标
class Coor
{
public:
	int x;
	int y;
};
//方向
enum Dierection
{
	goup=72,
	godown=80,
	goleft=75,
	goright=77,
	goup1 = 119,
	godown1 = 115,
	goleft1 = 97,
	goright1 = 100
};
//蛇
class Snack
{
public:
	//蛇的节数，每一节就是一个正方形
	int jieshu;
	//定义一个结构体数组，存放蛇的坐标
	class Coor location[SnackLengthMax];
	//蛇的方向
	Dierection dicy;
	bool isDead=0;
};
class Food
{
public:
	struct Coor location;
	bool isEaten = 0;
};
void superInit();
void initSnack();
void drawSnack();
void moveSnack();
void changeDicy();
void drawFood();
void isDead(Snack *textSnack);
void initFood();
void eatFood();
void vsDead(Snack *snack1, Snack *snack2);
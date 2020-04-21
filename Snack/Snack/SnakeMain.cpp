#include"Snack.h"
#include<iostream>
using namespace std;



Snack snack;
Snack snack1;
Snack *ptrSnack = &snack;
Snack *ptrSnack1 = &snack1;
Food food;
Food food1;
int main()
{	
	srand((unsigned int)time(NULL));
	superInit();
	initSnack();
	initFood();
	while (1)
	{
		if (food.isEaten == 1)
		{
			food.location.x = rand() % 75 * 20;
			food.location.y = rand() % 42 * 20;
		}
		else if (food1.isEaten == 1)
		{
			food1.location.x = rand() % 75 * 20;
			food1.location.y = rand() % 42 * 20;
		}
		cleardevice();
		drawFood();
		drawSnack();
		moveSnack();

		eatFood();
		Sleep(100);
		cleardevice();
		while (_kbhit())
		{
			changeDicy();
		}
		isDead(&snack);
		isDead(&snack1);
		vsDead(&snack, &snack1);
		vsDead(&snack1, &snack);
		if (snack.isDead||snack1.isDead)
		{
			cleardevice();
			settextstyle(100, 0, L"微软雅黑");
			if(snack.isDead ==1)
				outtextxy(500, 360, L"玩家2绿色蛇Game Over");
			else if(snack1.isDead==1)
				outtextxy(500, 360, L"玩家1红蛇Game Over");
			Sleep(5000);
			return 0;
		}
	}
	/*
	//初始化一个显示区域
	initgraph(1280, 720);
	//设置cleardevice()时刷新的颜色
	setbkcolor(BLUE);
	//使用一种颜色去刷新显示区域，若未设置则默认为黑色
	cleardevice();
	//设置文字格式(高，宽，字体)，宽设置为0会默认去匹配字体的高
	settextstyle(50,20,L"黑体");
	//在屏幕某个位置显示定点显示文字
	outtextxy(680, 320, L"泉水姐姐超级粉丝");
	//绘制一个圆形,只需要圆心位置和半径
	circle(500, 500, 100);
	//绘制一个矩形,只需要两个点作为参数
	rectangle(10, 50, 300, 500);
	*/
	int a;
	cin >> a;
	return 3;
}
//原始初始化
void superInit()
{
	//初始化界面
	initgraph(1520, 855);
	//初始化音乐
	//playsound()函数只能播放WAV格式
	mciSendString(L"open D:\\C++\\Snack\\Snack\\ZARD-揺れる想い.mp3 alias BGM",0, 0, 0);//向声卡驱动发送字符串消息
	mciSendString(L"play BGM", 0, 0, 0);
	settextstyle(170, 0, L"黑体");
	outtextxy(518, 288, L"双恰蛇");
	settextstyle(40, 0, L"楷体");
	outtextxy(909, 618, L"郑毅、曹世皎、杨硕、龚如晗");
	settextstyle(20, 0, L"微软雅黑");
	outtextxy(1137, 690, L"版权所有，违者必究");
	Sleep(5000);

}
//初始化蛇
void initSnack()
{
	//初始化蛇
	snack.jieshu = 4;
	snack.dicy = godown;
	snack.location[3].x = 900;
	snack.location[3].y = 320;
	snack.location[2].x = 900;
	snack.location[2].y = 340;
	snack.location[1].x = 900;
	snack.location[1].y = 360;
	snack.location[0].x = 900;
	snack.location[0].y = 380;

	snack1.jieshu = 4;
	snack1.dicy = godown1;
	snack1.location[3].x = 300;
	snack1.location[3].y = 320;
	snack1.location[2].x = 300;
	snack1.location[2].y = 340;
	snack1.location[1].x = 300;
	snack1.location[1].y = 360;
	snack1.location[0].x = 300;
	snack1.location[0].y = 380;
}
//绘制蛇
void drawSnack()
{	
	setlinecolor(RED);
	setfillcolor(GREEN);
	for (int i = 0; i < snack.jieshu; i++)
	{
		fillrectangle(snack.location[i].x, snack.location[i].y,
			snack.location[i].x + 20, snack.location[i].y + 20);
	}
	setlinecolor(GREEN);
	setfillcolor(RED);
	for (int i = 0; i < snack1.jieshu; i++)
	{
		fillrectangle(snack1.location[i].x, snack1.location[i].y,
			snack1.location[i].x + 20, snack1.location[i].y + 20);
	}
}
//蛇的移动
void moveSnack()
{	
	for (int i = snack.jieshu - 1; i > 0; i--)
	{
		snack.location[i].x = snack.location[i - 1].x;
		snack.location[i].y = snack.location[i - 1].y;
	}
	switch (snack.dicy)
	{
		case goup:snack.location[0].y -=20; break;
		case godown:snack.location[0].y  += 20; break;
		case goleft:snack.location[0].x  -= 20; break;
		case goright:snack.location[0].x  += 20; break;
	}

	for (int i = snack1.jieshu - 1; i > 0; i--)
	{
		snack1.location[i].x = snack1.location[i - 1].x;
		snack1.location[i].y = snack1.location[i - 1].y;
	}
	switch (snack1.dicy)
	{
	case goup1:snack1.location[0].y -= 20; break;
	case godown1:snack1.location[0].y += 20; break;
	case goleft1:snack1.location[0].x -= 20; break;
	case goright1:snack1.location[0].x += 20; break;
	}
	//蛇的后一节和前一节交换位置坐标
	/*snack.location[3].x = snack.location[2].x;
	snack.location[3].y = snack.location[2].y;
	snack.location[2].x = snack.location[1].x;
	snack.location[2].y = snack.location[1].y;
	snack.location[1].x = snack.location[0].x;
	snack.location[1].y = snack.location[0].y;*/
}
//改变蛇的方向
void changeDicy()
{
	int nowDicy = _getch();
	if (!(nowDicy == snack.dicy || nowDicy == snack1.dicy))
	{
		switch (nowDicy)
		{
		case goup: snack.dicy = goup; break;
		case godown: snack.dicy = godown; break;
		case goleft: snack.dicy = goleft; break;
		case goright: snack.dicy = goright; break;
		case 119: snack1.dicy = goup1; break;
		case 115: snack1.dicy = godown1; break;
		case 97: snack1.dicy = goleft1; break;
		case 100: snack1.dicy = goright1; break;
		}
	}
}
//初始化食物
void initFood()
{	
	food.location.x = rand()%74*20;
	food.location.y = rand()%41*20;
	food1.location.x = rand()%74*20;
	food1.location.y = rand()%41*20;
}
//画食物
void drawFood()
{
	setfillcolor(GREEN);
	fillrectangle(food.location.x, food.location.y,
				food.location.x + 20, food.location.y + 20);
	setfillcolor(RED);
	fillrectangle(food1.location.x, food1.location.y,
		food1.location.x + 20, food1.location.y + 20);
}
//吃食物
void eatFood()
{
	if (snack.location[0].x ==food.location.x && snack.location[0].y ==food.location.y)
	{
		snack.jieshu++;
		food.isEaten = 1;
	}
	else food.isEaten = 0;
	if (snack1.location[0].x == food1.location.x && snack1.location[0].y == food1.location.y)
	{
		snack1.jieshu++;
		food1.isEaten = 1;
	}
	else food1.isEaten = 0;
}
//判断撞墙死亡函数
void isDead(Snack *textSnack)
{
	if (textSnack->location[0].x == -20 || textSnack->location[0].x == 1520 ||
		textSnack->location[0].y == -20 || textSnack->location[0].y == 860)
	{
		textSnack->isDead = 1;
	}
}
//判断双蛇互撞死亡函数
void vsDead(Snack *snack1, Snack *snack2)
{
	for (int i = 0; i < snack2->jieshu; i++)
	{
		if (snack1->location[0].x == snack2->location[i].x&&
			snack1->location[0].y == snack2->location[i].y)
			snack1->isDead = 1;
	}
}
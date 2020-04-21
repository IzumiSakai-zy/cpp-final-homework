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
			settextstyle(100, 0, L"΢���ź�");
			if(snack.isDead ==1)
				outtextxy(500, 360, L"���2��ɫ��Game Over");
			else if(snack1.isDead==1)
				outtextxy(500, 360, L"���1����Game Over");
			Sleep(5000);
			return 0;
		}
	}
	/*
	//��ʼ��һ����ʾ����
	initgraph(1280, 720);
	//����cleardevice()ʱˢ�µ���ɫ
	setbkcolor(BLUE);
	//ʹ��һ����ɫȥˢ����ʾ������δ������Ĭ��Ϊ��ɫ
	cleardevice();
	//�������ָ�ʽ(�ߣ�������)��������Ϊ0��Ĭ��ȥƥ������ĸ�
	settextstyle(50,20,L"����");
	//����Ļĳ��λ����ʾ������ʾ����
	outtextxy(680, 320, L"Ȫˮ��㳬����˿");
	//����һ��Բ��,ֻ��ҪԲ��λ�úͰ뾶
	circle(500, 500, 100);
	//����һ������,ֻ��Ҫ��������Ϊ����
	rectangle(10, 50, 300, 500);
	*/
	int a;
	cin >> a;
	return 3;
}
//ԭʼ��ʼ��
void superInit()
{
	//��ʼ������
	initgraph(1520, 855);
	//��ʼ������
	//playsound()����ֻ�ܲ���WAV��ʽ
	mciSendString(L"open D:\\C++\\Snack\\Snack\\ZARD-�e����뤤.mp3 alias BGM",0, 0, 0);//���������������ַ�����Ϣ
	mciSendString(L"play BGM", 0, 0, 0);
	settextstyle(170, 0, L"����");
	outtextxy(518, 288, L"˫ǡ��");
	settextstyle(40, 0, L"����");
	outtextxy(909, 618, L"֣�㡢����𨡢��˶��������");
	settextstyle(20, 0, L"΢���ź�");
	outtextxy(1137, 690, L"��Ȩ���У�Υ�߱ؾ�");
	Sleep(5000);

}
//��ʼ����
void initSnack()
{
	//��ʼ����
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
//������
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
//�ߵ��ƶ�
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
	//�ߵĺ�һ�ں�ǰһ�ڽ���λ������
	/*snack.location[3].x = snack.location[2].x;
	snack.location[3].y = snack.location[2].y;
	snack.location[2].x = snack.location[1].x;
	snack.location[2].y = snack.location[1].y;
	snack.location[1].x = snack.location[0].x;
	snack.location[1].y = snack.location[0].y;*/
}
//�ı��ߵķ���
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
//��ʼ��ʳ��
void initFood()
{	
	food.location.x = rand()%74*20;
	food.location.y = rand()%41*20;
	food1.location.x = rand()%74*20;
	food1.location.y = rand()%41*20;
}
//��ʳ��
void drawFood()
{
	setfillcolor(GREEN);
	fillrectangle(food.location.x, food.location.y,
				food.location.x + 20, food.location.y + 20);
	setfillcolor(RED);
	fillrectangle(food1.location.x, food1.location.y,
		food1.location.x + 20, food1.location.y + 20);
}
//��ʳ��
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
//�ж�ײǽ��������
void isDead(Snack *textSnack)
{
	if (textSnack->location[0].x == -20 || textSnack->location[0].x == 1520 ||
		textSnack->location[0].y == -20 || textSnack->location[0].y == 860)
	{
		textSnack->isDead = 1;
	}
}
//�ж�˫�߻�ײ��������
void vsDead(Snack *snack1, Snack *snack2)
{
	for (int i = 0; i < snack2->jieshu; i++)
	{
		if (snack1->location[0].x == snack2->location[i].x&&
			snack1->location[0].y == snack2->location[i].y)
			snack1->isDead = 1;
	}
}
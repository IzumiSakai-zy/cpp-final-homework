#include<stdio.h>//��׼�������ͷ�ļ�
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//�ߵ���󳤶�
#define SnackLengthMax 500


//����
class Coor
{
public:
	int x;
	int y;
};
//����
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
//��
class Snack
{
public:
	//�ߵĽ�����ÿһ�ھ���һ��������
	int jieshu;
	//����һ���ṹ�����飬����ߵ�����
	class Coor location[SnackLengthMax];
	//�ߵķ���
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
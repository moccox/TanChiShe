#include "Snake.h"
#include <time.h>
#include <stdlib.h>

void snake :: go_up()
{ 
	//�������ƣ�y-1
	head++;
	head->x = (head - 1)->x;
	head->y = ((head - 1)->y - 1);
	//�Ƿ������β���ⲿ�ж�
}

void  snake :: go_left()
{
	//�������ƣ�x-1
	head++;
	head->x = ((head - 1)->x - 1);
	head->y = (head - 1)->y;
	//�Ƿ������β���ⲿ�ж�
}

void  snake :: go_down()
{
	//�������ƣ�y+1
	head++;
	head->x = (head - 1)->x;
	head->y = ((head - 1)->y + 1);
	//�Ƿ������β���ⲿ�ж�
}

void  snake :: go_right()
{
	//�������ƣ�x+1
	head++;
	head->x = ((head - 1)->x + 1);
	head->y = (head - 1)->y;
	//�Ƿ������β���ⲿ�ж�
}



void food :: produce(int width, int height)
{
	//��width��height�ķ�Χ�ڲ����������
	int i;
	srand((unsigned)time(0));
	i = rand() % width;
	x = i;
	i = rand() % height;
	y = i;
}

food :: food(int a, int b)
{
	x = a;
	y = b;
}

snake :: snake(int width, int height)
{
	//�½�����������ͼ��ջ��������ͷ����βָ��ջ��
	head = tail = p = new point[width * height];
}

snake::~snake()
{
	 delete[] p;
}
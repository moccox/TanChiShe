#include "Snake.h"
#include <time.h>
#include <stdlib.h>

void snake :: go_up()
{ 
	//�������ƣ�y-1
		y--;
}

void  snake :: go_left()
{
	//�������ƣ�x-1
		x--;
}

void  snake :: go_down()
{
	//�������ƣ�y+1
		y++;
}

void  snake :: go_right()
{
	//�������ƣ�x+1
		x++;
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

snake :: snake(int a, int b)
{
	x = a;
	y = b;
}
#include "Snake.h"
#include <time.h>
#include <stdlib.h>

void snake :: go_up()
{ 
	//坐标上移，y-1
	head++;
	head->x = (head - 1)->x;
	head->y = ((head - 1)->y - 1);
	//是否擦除蛇尾在外部判断
}

void  snake :: go_left()
{
	//坐标左移，x-1
	head++;
	head->x = ((head - 1)->x - 1);
	head->y = (head - 1)->y;
	//是否擦除蛇尾在外部判断
}

void  snake :: go_down()
{
	//坐标下移，y+1
	head++;
	head->x = (head - 1)->x;
	head->y = ((head - 1)->y + 1);
	//是否擦除蛇尾在外部判断
}

void  snake :: go_right()
{
	//坐标右移，x+1
	head++;
	head->x = ((head - 1)->x + 1);
	head->y = (head - 1)->y;
	//是否擦除蛇尾在外部判断
}



void food :: produce(int width, int height)
{
	//在width、height的范围内产生随机坐标
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
	//新建足以铺满地图的栈，并将蛇头和蛇尾指向栈底
	head = tail = p = new point[width * height];
}

snake::~snake()
{
	 delete[] p;
}
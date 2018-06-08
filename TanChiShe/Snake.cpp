#include "Snake.h"
#include <time.h>
#include <stdlib.h>

void snake :: go_up()
{ 
	//坐标上移，y-1
		y--;
}

void  snake :: go_left()
{
	//坐标左移，x-1
		x--;
}

void  snake :: go_down()
{
	//坐标下移，y+1
		y++;
}

void  snake :: go_right()
{
	//坐标右移，x+1
		x++;
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

snake :: snake(int a, int b)
{
	x = a;
	y = b;
}
#include <iostream>
#include "Snake.h"
#include <Windows.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)

#define W 80
#define H 24
using namespace std;

void MapInit(char *p,int width,int height); //初始化
void MapShow(char map[][H]);	//输出地图现状
void FoodPut(char A[][H],food b);		//随机放置食物
void RightAhead(snake &head, snake &tail, char *p,char A[][H]); //往右前进
void LeftAhead(snake &head, snake &tail, char *p,char A[][H]);//往左前进
void UpAhead(snake &head, snake &tail, char *p, char A[][H]); //往上前进
void DownAhead(snake &head, snake &tail, char *p, char A[][H]);//往下前进
void ChangeDirection(char s, string &direction);//改变方向
void Cut_Tail(snake &tail, char *p);	//擦除蛇尾
int main (void)
{
	char m_map[W][H];	//地图
	char *p = &m_map[0][0];
	snake m_head(3,1), m_tail(1,1);	//蛇头、蛇尾
	food m_food(0,0);	//食物
	string snake_direction;	//蛇的前进方向（flag）
	


	MapInit(p,W,H);	//初始化地图
	int x, y;	//初始化蛇
	for (x = m_head.x; x >= m_tail.x; x--){
		for (y = m_head.y; y >= m_tail.y; y--){
			*(p + (W * y) + x) = '@';
		}
	}
	FoodPut(m_map, m_food);	//初始化食物
	snake_direction = "right";	//初始化蛇的前进方向（向右）

	MapShow(m_map);
	
	//游戏开始

	while (1){
		int i;
		for (i = 0; i < 5000; i++);
		if (kbhit()){
			char s;
			s=getch();
			ChangeDirection(s, snake_direction);
		}
		
		if (snake_direction == "right"){
			p = &m_map[0][0];
			RightAhead(m_head, m_tail, p, m_map);
		}

		if (snake_direction == "left"){
			p = &m_map[0][0];
			LeftAhead(m_head, m_tail, p, m_map);
		}
		if (snake_direction == "up"){
			p = &m_map[0][0];
			UpAhead(m_head, m_tail, p, m_map);
		}

		if (snake_direction == "down"){
			p = &m_map[0][0];
			DownAhead(m_head, m_tail, p, m_map);
		}
		MapShow(m_map);
	}
	//system("pause");
	return 0;
}

void MapInit(char *p,int width,int height)
{
	int i,j;

	for (i = 0; i < width; i++)
	{
		if (i % 2 == 0){
			*p = '#';
			 p++;
		}
		else{
			*p = ' ';
			 p++;
		}

	}


	for (i = 0; i < (height - 2);i++){
		*p = '#';
		p++;
		for (j = 0; j < (width - 2); j++){
			*p = NULL;
			p++;
		}
		*p = '#';
		p++;
	}


	for (i = 0; i < width; i++)
	{
		if (i % 2 == 0){
			*p = '#';
			p++;
		}
		else{
			*p = ' ';
			p++;
		}

	}

}

void MapShow(char map[][H])
{
	system("cls");
	int i, j;
	for (i = 0; i < W; i++){
		for (j = 0; j < H; j++){
			cout << map[i][j];
		}
	}
}

void FoodPut(char A[][H],food b)
{
	while (1){
		/*循环产生随机坐标，该处为空则填入食物，结束本循环；该处不为空则继续循环产生随机坐标直到有空的为止*/
		b.produce(W, H);	//初始化食物
		if (A[b.x][b.y] == NULL){
			/*因为是见缝插针随机式地放置食物，所以不需要用到指针，只要该处是空白的就可以*/
			A[b.x][b.y] = '*';
			break;
		}

	}
}

void RightAhead(snake &head, snake &tail, char *p, char A[][H])
{
	head.go_right();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//撞墙
		|| *(p + (W*head.y) + head.x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);
	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//吃
		food f(0, 0);	//放置新食物
		FoodPut(A, f);
	}

}

void LeftAhead(snake &head,snake &tail,char *p,char A[][H])
{
	head.go_left();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//撞墙
		|| *(p + (W*head.y) + head.x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);

	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//吃
		food f(0,0);	//放置新食物
		FoodPut(A, f);
	}

}

void UpAhead(snake &head, snake &tail, char *p, char A[][H])
{
	head.go_up();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//撞墙
		|| *(p + (W*head.y) + head.x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);

	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//吃
		food f(0, 0);	//放置新食物
		FoodPut(A, f);

	}

}

void DownAhead(snake &head, snake &tail, char *p, char A[][H])
{
	head.go_down();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//撞墙
		|| *(p + (W*head.y) + head.x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);

	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//吃
		food f(0, 0);	//放置新食物
		FoodPut(A, f);

	}

}

void ChangeDirection(char s,string &direction)
{
	switch (s){
	case 77:{//→
		if (direction == "left") break;	//避免缩骨功
		else{
			direction = "right";
			break;
		}
	}
	case 72:{//↑
		if (direction == "down") break;
		else{
			direction = "up";
			break;
		}
	}
	case 75:{//←
		if (direction == "right") break;
		else{
			direction = "left";
			break;
		}
	}
	case 80:{//↓
		if (direction == "up") break;
		else{
			direction = "down";
			break;
		}
	}
	}
}

void Cut_Tail(snake &tail, char *p){
	if (*(p + (W*tail.y) + tail.x + 1) == '@'){	//蛇身在右边
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_right();
	}else if (*(p + (W*(tail.y + 1)) + tail.x)=='@'){	//蛇身在下边
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_down();
	} else if (*(p + (W*tail.y) + tail.x - 1) == '@'){	//蛇身在左边
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_left();
	}else{
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_up();
	}
}
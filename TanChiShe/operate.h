#ifndef OPERATE_H
#define OPERATE_H

#include <iostream>
#include "Snake.h"
#include <Windows.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)

#define W 80
#define H 24
using namespace std;

void MapInit(char *p, int width, int height); //初始化
void MapShow(char map[][H]);	//输出地图现状
void FoodPut(char A[][H], food b);		//随机放置食物
void RightAhead(snake &m_snake, char *p, char A[][H]); //往右前进
void LeftAhead(snake &m_snake, char *p, char A[][H]);//往左前进
void UpAhead(snake &m_snake, char *p, char A[][H]); //往上前进
void DownAhead(snake &m_snake, char *p, char A[][H]);//往下前进
void ChangeDirection(char s, string &direction);//改变方向

#endif
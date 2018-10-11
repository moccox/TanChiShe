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

void MapInit(char *p, int width, int height); //��ʼ��
void MapShow(char map[][H]);	//�����ͼ��״
void FoodPut(char A[][H], food b);		//�������ʳ��
void RightAhead(snake &m_snake, char *p, char A[][H]); //����ǰ��
void LeftAhead(snake &m_snake, char *p, char A[][H]);//����ǰ��
void UpAhead(snake &m_snake, char *p, char A[][H]); //����ǰ��
void DownAhead(snake &m_snake, char *p, char A[][H]);//����ǰ��
void ChangeDirection(char s, string &direction);//�ı䷽��

#endif
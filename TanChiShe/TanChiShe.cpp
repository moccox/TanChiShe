#include <iostream>
#include "Snake.h"
#include <Windows.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)

#define W 80
#define H 24
using namespace std;

void MapInit(char *p,int width,int height); //��ʼ��
void MapShow(char map[][H]);	//�����ͼ��״
void FoodPut(char A[][H],food b);		//�������ʳ��
void RightAhead(snake &head, snake &tail, char *p,char A[][H]); //����ǰ��
void LeftAhead(snake &head, snake &tail, char *p,char A[][H]);//����ǰ��
void UpAhead(snake &head, snake &tail, char *p, char A[][H]); //����ǰ��
void DownAhead(snake &head, snake &tail, char *p, char A[][H]);//����ǰ��
void ChangeDirection(char s, string &direction);//�ı䷽��
void Cut_Tail(snake &tail, char *p);	//������β
int main (void)
{
	char m_map[W][H];	//��ͼ
	char *p = &m_map[0][0];
	snake m_head(3,1), m_tail(1,1);	//��ͷ����β
	food m_food(0,0);	//ʳ��
	string snake_direction;	//�ߵ�ǰ������flag��
	


	MapInit(p,W,H);	//��ʼ����ͼ
	int x, y;	//��ʼ����
	for (x = m_head.x; x >= m_tail.x; x--){
		for (y = m_head.y; y >= m_tail.y; y--){
			*(p + (W * y) + x) = '@';
		}
	}
	FoodPut(m_map, m_food);	//��ʼ��ʳ��
	snake_direction = "right";	//��ʼ���ߵ�ǰ���������ң�

	MapShow(m_map);
	
	//��Ϸ��ʼ

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
		/*ѭ������������꣬�ô�Ϊ��������ʳ�������ѭ�����ô���Ϊ�������ѭ�������������ֱ���пյ�Ϊֹ*/
		b.produce(W, H);	//��ʼ��ʳ��
		if (A[b.x][b.y] == NULL){
			/*��Ϊ�Ǽ���������ʽ�ط���ʳ����Բ���Ҫ�õ�ָ�룬ֻҪ�ô��ǿհ׵ľͿ���*/
			A[b.x][b.y] = '*';
			break;
		}

	}
}

void RightAhead(snake &head, snake &tail, char *p, char A[][H])
{
	head.go_right();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//ײǽ
		|| *(p + (W*head.y) + head.x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);
	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//��
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);
	}

}

void LeftAhead(snake &head,snake &tail,char *p,char A[][H])
{
	head.go_left();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//ײǽ
		|| *(p + (W*head.y) + head.x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);

	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//��
		food f(0,0);	//������ʳ��
		FoodPut(A, f);
	}

}

void UpAhead(snake &head, snake &tail, char *p, char A[][H])
{
	head.go_up();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//ײǽ
		|| *(p + (W*head.y) + head.x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);

	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//��
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);

	}

}

void DownAhead(snake &head, snake &tail, char *p, char A[][H])
{
	head.go_down();
	if (*(p + (W*head.y) + head.x) == '#' || *(p + (W*head.y) + head.x) == ' '	//ײǽ
		|| *(p + (W*head.y) + head.x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*head.y) + head.x) == NULL){
		*(p + (W*head.y) + head.x) = '@';
		Cut_Tail(tail, p);

	}
	else if (*(p + (W*head.y) + head.x) == '*'){
		*(p + (W*head.y) + head.x) = '@';	//��
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);

	}

}

void ChangeDirection(char s,string &direction)
{
	switch (s){
	case 77:{//��
		if (direction == "left") break;	//�������ǹ�
		else{
			direction = "right";
			break;
		}
	}
	case 72:{//��
		if (direction == "down") break;
		else{
			direction = "up";
			break;
		}
	}
	case 75:{//��
		if (direction == "right") break;
		else{
			direction = "left";
			break;
		}
	}
	case 80:{//��
		if (direction == "up") break;
		else{
			direction = "down";
			break;
		}
	}
	}
}

void Cut_Tail(snake &tail, char *p){
	if (*(p + (W*tail.y) + tail.x + 1) == '@'){	//�������ұ�
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_right();
	}else if (*(p + (W*(tail.y + 1)) + tail.x)=='@'){	//�������±�
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_down();
	} else if (*(p + (W*tail.y) + tail.x - 1) == '@'){	//���������
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_left();
	}else{
		*(p + (W*tail.y) + tail.x) = NULL;
		tail.go_up();
	}
}
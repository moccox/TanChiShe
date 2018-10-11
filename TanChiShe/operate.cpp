#include "operate.h"


void MapInit(char *p, int width, int height)
{
	int i, j;

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


	for (i = 0; i < (height - 2); i++){
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

void FoodPut(char A[][H], food b)
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

void RightAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_right();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//撞墙
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//擦除蛇尾
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//吃,不用擦除蛇尾
		food f(0, 0);	//放置新食物
		FoodPut(A, f);
	}

}

void LeftAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_left();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//撞墙
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//擦除蛇尾
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//吃，不用擦除蛇尾
		food f(0, 0);	//放置新食物
		FoodPut(A, f);
	}

}

void UpAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_up();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//撞墙
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//擦除蛇尾
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//吃,不用擦除蛇尾
		food f(0, 0);	//放置新食物
		FoodPut(A, f);

	}

}

void DownAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_down();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//撞墙
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//撞身
	{
		cout << "游戏结束！" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//擦除蛇尾
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//吃,不用擦除蛇尾
		food f(0, 0);	//放置新食物
		FoodPut(A, f);

	}

}

void ChangeDirection(char s, string &direction)
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
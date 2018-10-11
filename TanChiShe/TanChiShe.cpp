#include "operate.h"


int main (void)
{
	char m_map[W][H];	//地图
	char *p = &m_map[0][0];
	snake m_snake(W,H);	//蛇
	food m_food(0,0);	//食物
	string snake_direction;	//蛇的前进方向（flag）
	


	MapInit(p,W,H);	//初始化地图
	{	//初始化蛇头、蛇身
		m_snake.head->x = 1;
		m_snake.head->y = 1;
		*(p + (W * m_snake.head->y) + m_snake.head->x) = '@';
		m_snake.go_right();
		*(p + (W * m_snake.head->y) + m_snake.head->x) = '@';
		m_snake.go_right();
		*(p + (W * m_snake.head->y) + m_snake.head->x) = '@';
	}
	{	//初始化蛇尾
		m_snake.tail->x = 1;
		m_snake.tail->y = 1;
		*(p + (W * m_snake.tail->y) + m_snake.tail->x) = '@';
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
			RightAhead(m_snake, p, m_map);
		}

		if (snake_direction == "left"){
			p = &m_map[0][0];
			LeftAhead(m_snake, p, m_map);
		}
		if (snake_direction == "up"){
			p = &m_map[0][0];
			UpAhead(m_snake, p, m_map);
		}

		if (snake_direction == "down"){
			p = &m_map[0][0];
			DownAhead(m_snake, p, m_map);
		}
		MapShow(m_map);
	}
	//system("pause");
	return 0;
}

#include "operate.h"


int main (void)
{
	char m_map[W][H];	//��ͼ
	char *p = &m_map[0][0];
	snake m_snake(W,H);	//��
	food m_food(0,0);	//ʳ��
	string snake_direction;	//�ߵ�ǰ������flag��
	


	MapInit(p,W,H);	//��ʼ����ͼ
	{	//��ʼ����ͷ������
		m_snake.head->x = 1;
		m_snake.head->y = 1;
		*(p + (W * m_snake.head->y) + m_snake.head->x) = '@';
		m_snake.go_right();
		*(p + (W * m_snake.head->y) + m_snake.head->x) = '@';
		m_snake.go_right();
		*(p + (W * m_snake.head->y) + m_snake.head->x) = '@';
	}
	{	//��ʼ����β
		m_snake.tail->x = 1;
		m_snake.tail->y = 1;
		*(p + (W * m_snake.tail->y) + m_snake.tail->x) = '@';
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

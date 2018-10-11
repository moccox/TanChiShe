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
		/*ѭ������������꣬�ô�Ϊ��������ʳ�������ѭ�����ô���Ϊ�������ѭ�������������ֱ���пյ�Ϊֹ*/
		b.produce(W, H);	//��ʼ��ʳ��
		if (A[b.x][b.y] == NULL){
			/*��Ϊ�Ǽ���������ʽ�ط���ʳ����Բ���Ҫ�õ�ָ�룬ֻҪ�ô��ǿհ׵ľͿ���*/
			A[b.x][b.y] = '*';
			break;
		}

	}
}

void RightAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_right();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//ײǽ
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//������β
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//��,���ò�����β
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);
	}

}

void LeftAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_left();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//ײǽ
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//������β
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//�ԣ����ò�����β
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);
	}

}

void UpAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_up();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//ײǽ
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//������β
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//��,���ò�����β
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);

	}

}

void DownAhead(snake &m_snake, char *p, char A[][H])
{
	m_snake.go_down();
	if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '#' || *(p + (W*m_snake.head->y) + m_snake.head->x) == ' '	//ײǽ
		|| *(p + (W*m_snake.head->y) + m_snake.head->x) == '@')	//ײ��
	{
		cout << "��Ϸ������" << endl;
		system("pause");
		return;
	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == NULL){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';
		{	//������β
			*(p + (W*m_snake.tail->y) + m_snake.tail->x) = NULL;
			m_snake.tail++;
		}

	}
	else if (*(p + (W*m_snake.head->y) + m_snake.head->x) == '*'){
		*(p + (W*m_snake.head->y) + m_snake.head->x) = '@';	//��,���ò�����β
		food f(0, 0);	//������ʳ��
		FoodPut(A, f);

	}

}

void ChangeDirection(char s, string &direction)
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
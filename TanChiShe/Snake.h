#ifndef SNAKE_H
#define	SNAKE_H

class point{  //����
public:
	int x;	//������
	int y;	//������
};

class food : public point{ //ʳ����
public:
	food(int a, int b);		//���캯��
	void produce(int width, int height); //������������꣬width��heightΪ��ͼ�Ŀ���
};

class snake {
public:
	snake(int width, int height);	//���캯��
	~snake();
	point *head, *tail;	//��ͷ��ջ��������β��ջ�ף�
    point *p;	//�˵�̶�ָ��ջ�ף�����delete�ͷ��ڴ�
	void go_up();	//��������
	void go_left();	//��������
	void go_down();	//��������
	void go_right();//��������
};

#endif
#ifndef SNAKE_H
#define	SNAKE_H

class point{  //点类
public:
	int x;	//横坐标
	int y;	//纵坐标
};

class food : public point{ //食物类
public:
	food(int a, int b);		//构造函数
	void produce(int width, int height); //产生随机的坐标，width、height为地图的宽、高
};

class snake {
public:
	snake(int width, int height);	//构造函数
	~snake();
	point *head, *tail;	//蛇头（栈顶）、蛇尾（栈底）
    point *p;	//此点固定指向栈底，用来delete释放内存
	void go_up();	//坐标上移
	void go_left();	//坐标左移
	void go_down();	//坐标下移
	void go_right();//坐标右移
};

#endif
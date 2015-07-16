#ifndef SNAKEBASIC_H_
#define SNAKEBASIC_H_

const int N = 20;

struct snake
{
	int x, y;
	snake *next;
};

template <class T>
class SnakeBasic							//Ä£°åÐé»ùÀà
{
public:
	bool judge_life() { return life; }
	virtual void print() = 0;
protected:
	bool life;
	T *head;
	T *tail;
};

template<class T>
class SnakeRunning :public SnakeBasic<snake>
{
public:
	SnakeRunning();
	~SnakeRunning();
	void print();
	void modify_direc(char c);
	bool game_over();
	T save();
	void load();
private:
	static void init();
	static char map[N][N];
	void move(int x, int y);
	void put_food();
};

#endif
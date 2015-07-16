#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include"snakebasic.h"
using namespace std;

template<class T>
SnakeRunning<T>::SnakeRunning()
{
	init();
	put_food();
	life = true;

	for (int i = 1; i < 10; i++)
	{
		if (i == 1)
		{
			head = tail = new snake;
			head->x = 1;
			head->y = i;
			head->next = NULL;
			map[head->x][head->y] = '¨€';
		}
		else
		{
			snake* temp = new snake;
			temp->next = NULL;
			temp->x = 1;
			temp->y = i;
			tail->next = temp;
			tail = temp;
			map[tail->x][tail->y] = '¨€';
		}
	}
	map[tail->x][tail->y] = '¡ö';
}

template<class T>
void SnakeRunning<T> ::init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i > 0 && i < N - 1 && j > 0 && j < N - 1)
				map[i][j] = ' ';
			else
				map[i][j] = '*';
		}
	}
}

template<class T>
void SnakeRunning<T>::put_food()
{
	int x, y;
	srand(static_cast<int>(time(NULL)));

	do
	{
		x = rand() % N;
		y = rand() % N;
	} while (map[x][y] != ' ');

	map[x][y] = 'o';
}

template<class T>
bool SnakeRunning::game_over()
{
	cout << "Sorry\nGame Over!!" << endl;
	cout << "Wanna play again? y/n" << endl;
	for (;;)
	{
		switch (cin.get())
		{
		case 'y':
			cin.ignore();
			return true;
		case 'n':
			cin.ignore();
			return false;
		default:
			cerr << "Error! Input again!" << endl;
			cin.ignore();
		}
	}
}

template<class T>
void SnakeRunning::print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

template<class T>
char SnakeRunning::map[N][N] = { ' ' };

template<class T>
void SnakeRunning::modify_direc(char c)
{
	switch (c)
	{
	case 'a':
	case 'A':
		move(0, -1);
		break;
	case 'd':
	case 'D':
		move(0, 1);
		break;
	case 's':
	case 'S':
		move(1, 0);
		break;
	case 'w':
	case 'W':
		move(-1, 0);
		break;
	}
}

template<class T>
void SnakeRunning::move(int x, int y)
{
	if (map[tail->x + x][tail->y + y] == '*' ||
		map[tail->x + x][tail->y + y] == '¨€')
	{
		life = false;
		return;
	}

	else
	{
		snake* temp = new snake;
		temp->x = tail->x + x;
		temp->y = tail->y + y;
		temp->next = NULL;

		if (map[temp->x][temp->y] == ' ')
		{
			snake* t = head;
			map[head->x][head->y] = ' ';
			head = head->next;
			delete t;
		}

		else
		{
			put_food();
		}

		map[tail->x][tail->y] = '¨€';
		map[temp->x][temp->y] = '¡ö';
		tail->next = temp;
		tail = temp;
	}
}

template<class T>
SnakeRunning::~SnakeRunning()
{
	while (head != NULL)
	{
		snake* temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
void SnakeRunning::save()
{

}
#include"menu_ColorTextChoose.h"
#include"snakebasic.h"
#include<Windows.h>
#include<conio.h>
#include<fstream>

void new_game();
void con_game();
void ser_game();

int main()
{
	ColorTextChoose menu;
	switch (menu.TextGoing())
	{
	case 1:new_game(); break;
	//case 2:con_game(); break;
	//case 3:ser_game(); break;
	case 4:
	case -1:return 0;
	default:cerr << "Error!" << endl;
	}
	return 0;
}

void new_game()
{
	SnakeRunning<snake> game;
	game.print();
	char direct = 'd';

	while (1)
	{
		while (!_kbhit())
		{
			game.modify_direc(direct);

			system("cls");
			game.print();
			Sleep(1000);
			if (!game.judge_life())
				break;
		}
		if (!game.judge_life())
			break;

		char c = _getch();
		if (c == 'S' || c == 's' || c == 'W' || c == 'w' || c == 'A' || c == 'a' || c == 'D' || c == 'd' )
			direct = c;
		//if (c == '27')
		//{
		//	{
		//		ofstream fout("data.dat");

		//	}			
		//	break;
		//}
	}
}
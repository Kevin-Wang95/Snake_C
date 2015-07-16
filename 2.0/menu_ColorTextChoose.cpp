#include<iostream>
#include<conio.h>      
#include<windows.h>
#include<string>
#include"menu_ColorTextChoose.h"
using namespace std;

void menu();

ColorTextChoose::ColorTextChoose()
{
	str[0] = "	1、开始新游戏		";
	str[1] = "	2、继续游戏  		";
	str[2] = "	3、查询排行榜		";
	str[3] = "	4、退出游戏			";

	index = 0;
}

int ColorTextChoose::TextGoing()			//实际运行函数
{
	this->showText();
	while (true)
	{
		char buffer = _getch();
		switch (buffer)
		{

		case 'w':
		case 'W':
			if (index != 0)
				index--;
			this->showText();
			break;//按w向上
		case 's':
		case 'S':
			if (index != 3)
				index++;
			this->showText();
			break;//按s向下
		case 13:
			if (index == 3)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//退格
		}
	}
}

void ColorTextChoose::showText()			//显示按钮
{
	system("color 07");//还原原系统的字体颜色和背景色
	system("cls");      //清空控制台
	menu();
	cout << "按 w/s 选择菜单,Enter进入,Esc退出" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i != index)
		{
			//没选子项没选中和选择下拉框的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF);//设置白字黑背景
		}
		else
		{
			//没选子项的情况选中当前项的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//设置文本背景设为红色,前景色为白色
		}
		cout << str[i] << endl;//输出主字符穿菜单选项

	}//显示主菜单
}

void menu()
{
	cout << "===================================" << endl;
	cout << "|                                 |" << endl;
	cout << "|             WELCOME             |" << endl;
	cout << "|                                 |" << endl;
	cout << "|               TO                |" << endl;
	cout << "|                                 |" << endl;
	cout << "|           THE WORLD OF          |" << endl;
	cout << "|                                 |" << endl;
	cout << "|              SNAKE              |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "===================================" << endl;
}
#include<iostream>
#include<conio.h>      
#include<windows.h>
#include<string>
#include"menu_ColorTextChoose.h"
using namespace std;

void menu();

ColorTextChoose::ColorTextChoose()
{
	str[0] = "	1����ʼ����Ϸ		";
	str[1] = "	2��������Ϸ  		";
	str[2] = "	3����ѯ���а�		";
	str[3] = "	4���˳���Ϸ			";

	index = 0;
}

int ColorTextChoose::TextGoing()			//ʵ�����к���
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
			break;//��w����
		case 's':
		case 'S':
			if (index != 3)
				index++;
			this->showText();
			break;//��s����
		case 13:
			if (index == 3)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//�˸�
		}
	}
}

void ColorTextChoose::showText()			//��ʾ��ť
{
	system("color 07");//��ԭԭϵͳ��������ɫ�ͱ���ɫ
	system("cls");      //��տ���̨
	menu();
	cout << "�� w/s ѡ��˵�,Enter����,Esc�˳�" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i != index)
		{
			//ûѡ����ûѡ�к�ѡ������������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF);//���ð��ֺڱ���
		}
		else
		{
			//ûѡ��������ѡ�е�ǰ������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//�����ı�������Ϊ��ɫ,ǰ��ɫΪ��ɫ
		}
		cout << str[i] << endl;//������ַ����˵�ѡ��

	}//��ʾ���˵�
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
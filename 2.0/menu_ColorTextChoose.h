#ifndef MENU_H_
#define MENU_H_

#define whF FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY  //�Ա�־λ����������óɰ��ֺ��
#define whF_rBc  BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY  //�Ա�־λ����������óɺ��ְ׵�
#include<iostream>  
#include<string>    
using namespace std;

class ColorTextChoose
	//ʵ����
{
private:
	string str[4];
	//str Ϊ�˵�
	int index;
public:
	ColorTextChoose();  //���캯����ʼ������
	int TextGoing();			//ʵ�����к���
	void showText();			//��ʾ��ť
};

#endif
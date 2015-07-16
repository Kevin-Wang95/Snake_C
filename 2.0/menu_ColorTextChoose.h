#ifndef MENU_H_
#define MENU_H_

#define whF FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY  //对标志位进行组合设置成白字红底
#define whF_rBc  BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY  //对标志位进行组合设置成红字白底
#include<iostream>  
#include<string>    
using namespace std;

class ColorTextChoose
	//实现类
{
private:
	string str[4];
	//str 为菜单
	int index;
public:
	ColorTextChoose();  //构造函数初始化数据
	int TextGoing();			//实际运行函数
	void showText();			//显示按钮
};

#endif
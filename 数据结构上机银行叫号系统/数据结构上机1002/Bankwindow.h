#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include"User.h"
using namespace std;

class bankwindow									//银行窗口基类
{
public:
	bool isbuy;
	int id;
	user client;
	char type;
	bankwindow(int d = 0, bool is = 1, char ty = NULL) :client(0, 1, NULL)
	{
		id = d;
		isbuy = is;
		type = ty;
	}
	void handleuser()
	{
		isbuy = 0;
	}
};


class nwindow :public bankwindow						//普通窗口
{
public:
	nwindow(int d = 0, bool is=0,char ty='n'):
		bankwindow(d,is,ty){}
};


class vwindow :public bankwindow						//VIP窗口
{
public:
	vwindow(int d = 0, bool is = 0, char ty = 'v') :
		bankwindow(d, is, ty) {}
};


class owindow :public bankwindow						//对共窗口
{
public:
	owindow(int d = 0, bool is = 0, char ty = 'o') :
		bankwindow(d, is, ty) {}
};
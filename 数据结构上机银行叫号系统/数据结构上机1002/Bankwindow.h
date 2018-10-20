#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include"User.h"
using namespace std;

class bankwindow									//���д��ڻ���
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


class nwindow :public bankwindow						//��ͨ����
{
public:
	nwindow(int d = 0, bool is=0,char ty='n'):
		bankwindow(d,is,ty){}
};


class vwindow :public bankwindow						//VIP����
{
public:
	vwindow(int d = 0, bool is = 0, char ty = 'v') :
		bankwindow(d, is, ty) {}
};


class owindow :public bankwindow						//�Թ�����
{
public:
	owindow(int d = 0, bool is = 0, char ty = 'o') :
		bankwindow(d, is, ty) {}
};
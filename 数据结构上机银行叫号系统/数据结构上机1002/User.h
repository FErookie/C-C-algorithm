#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class user											//用户基类
{
public:
	int id;
	int iswait;
	int arrivetime;
	int servetime;
	void getserve()
	{
		iswait = 0;
	}
	user(int d = 0, int s = 1, char ty = NULL)
	{
		id = d;
		iswait = s;
		type = ty;
		servetime = 4;
	}
	char type;
};


class nuser :public user							//普通账户类型
{
public:
	nuser(int d = 0, int s = 1, char ty = 'n') :
		user(d, s, ty) {}
};

class vuser :public user							//VIP账户类型
{
public:
	vuser(int d = 0, int s = 1, char ty = 'v') :
		user(d, s, ty) {}
};


class ouser :public user							//对公账户类型
{
public:
	ouser(int d = 0, int s = 1, char ty = 'o') :
		user(d, s, ty) {}
};
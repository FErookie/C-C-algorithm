#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class user											//�û�����
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


class nuser :public user							//��ͨ�˻�����
{
public:
	nuser(int d = 0, int s = 1, char ty = 'n') :
		user(d, s, ty) {}
};

class vuser :public user							//VIP�˻�����
{
public:
	vuser(int d = 0, int s = 1, char ty = 'v') :
		user(d, s, ty) {}
};


class ouser :public user							//�Թ��˻�����
{
public:
	ouser(int d = 0, int s = 1, char ty = 'o') :
		user(d, s, ty) {}
};
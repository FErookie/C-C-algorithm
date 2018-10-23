#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include<ctime>
#include<stdlib.h>
#include"User.h"
#include"Bankwindow.h"
using namespace std;

class sim										//银行类
{
public:
	queue<nuser> nuqueue;						//普通账户队列
	queue<vuser> vuqueue;						//VIP账户队列
	queue<ouser> ouqueue;						//对公账户队列
	nwindow nw[3];								//普通窗口
	vwindow vw;									//VIP窗口
	owindow ow;									//对共窗口
	static int j;
	static int m;
	static int g;
	void userenter();							//用户进银行
	void simuserenter();						//生成用户
	void calluser();							//分配窗口
	/*void fu()
	{
	j=1;
	}*/
	void simu();
	void handle() {
		for (int i = 0; i<3; i++)
			nw[i].handleuser();
		ow.handleuser();
		vw.handleuser();
	}
};
int sim::j = 1;
int sim::m = 1;
int sim::g = 1;
void sim::simuserenter()
{
	nuser *n;
	vuser *v;
	ouser *o;
	int a = 18;					//生成客户
	int b = 3;
	int c = 3;

	for (int i = 0; i<a; i++)
	{
		n = new nuser;
		n->id = j;
		nuqueue.push(*n);
		j++;
	}
	for (int i = 0; i < b; i++)
	{
		v = new vuser;
		v->id = g;
		g++;
		vuqueue.push(*v);
	}
	for (int i = 0; i < c; i++)
	{
		o = new ouser;
		o->id = m;
		m++;
		ouqueue.push(*o);
	}
}

void sim::calluser()
{
	int i;
	for (i = 0; i<3; i++)
	{
		if (!nuqueue.empty() && nw[i].isbuy == 0)
		{
			nw[i].isbuy = 1;
			nw[i].type = nuqueue.front().type;
			nw[i].id = nuqueue.front().id;
			nuqueue.pop();
		}
	}
	if (!vuqueue.empty() && vw.isbuy == 0)
	{
		vw.isbuy = 1;
		vw.type = vuqueue.front().type;
		vw.id = vuqueue.front().id;
		vuqueue.pop();
	}
	else if (vuqueue.empty() && vw.isbuy == 0 && !nuqueue.empty())
	{
		vw.isbuy = 1;
		vw.type = nuqueue.front().type;
		vw.id = nuqueue.front().id;
		nuqueue.pop();
	}
	if (!ouqueue.empty() && ow.isbuy == 0)
	{
		ow.isbuy = 1;
		ow.type = ouqueue.front().type;
		ow.id = ouqueue.front().id;
		ouqueue.pop();
	}
	else if (ouqueue.empty() && ow.isbuy == 0 && !nuqueue.empty())
	{
		ow.isbuy = 1;
		ow.type = nuqueue.front().type;
		ow.id = nuqueue.front().id;
		nuqueue.pop();
	}
}
void sim::userenter()
{
	int i;
	for (i = 0; i<3; i++)
	{
		if (nw[i].isbuy == 1)
			cout << "普通" << i + 1 << "窗口正在服务" << nw[i].type << nw[i].id << "顾客！\n";
		else
			cout << "普通" << i + 1 << "窗口空闲！！\n";
	}
	if (vw.isbuy == 1)
		cout << "VIP窗口正在服务" << vw.type << vw.id << "顾客！\n";
	else
		cout << "VIP窗口空闲！！\n";
	if (ow.isbuy == 1)
		cout << "对公窗口正在服务" << ow.type << ow.id << "顾客！\n";
	else
		cout << "对公窗口空闲！！\n";
	if (!nuqueue.empty())
		cout << "普通顾客还有	" << nuqueue.size() << "	人在等候！" << endl;
	else
		cout << "普通顾客已经无人等待！" << endl;
	if (!vuqueue.empty())
		cout << "VIP顾客还有	" << vuqueue.size() << "	人在等候！" << endl;
	else
		cout << "VIP顾客已经无人等待！" << endl;
	if (!ouqueue.empty())
		cout << "对公顾客还有	" << ouqueue.size() << "	人在等候！" << endl;
	else
		cout << "对公顾客已经已经无人等待！" << endl;
}
void sim::simu()
{
	long t1, t2;
	simuserenter();
	t1 = time(0);
	t2 = time(0);
	while (1)
	{
		cout << endl << "营业开始" << endl;		
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 2)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "第二秒" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 4)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "第四秒" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 6)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "第六秒" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 8)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "第八秒" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 12)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "第十秒" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 12)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "营业结束" << endl; 
		handle();
		calluser();
		userenter();
		break;
	}
}

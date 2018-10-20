#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include<ctime>
#include<stdlib.h>
#include"User.h"
#include"Bankwindow.h"
using namespace std;

class sim										//������
{
public:
	queue<nuser> nuqueue;						//��ͨ�˻�����
	queue<vuser> vuqueue;						//VIP�˻�����
	queue<ouser> ouqueue;						//�Թ��˻�����
	nwindow nw[3];								//��ͨ����
	vwindow vw;									//VIP����
	owindow ow;									//�Թ�����
	static int j;
	static int m;
	static int g;
	void userenter();							//�û�������
	void simuserenter();						//�����û�
	void calluser();							//���䴰��
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
	int a = rand() % 10;					//������ɿͻ�
	int b = rand() % 3;
	int c = rand() % 3;

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
			cout << "��ͨ" << i + 1 << "�������ڷ���" << nw[i].type << nw[i].id << "�˿ͣ�\n";
		else
			cout << "��ͨ" << i + 1 << "���ڿ��У���\n";
	}
	if (vw.isbuy == 1)
		cout << "VIP�������ڷ���" << vw.type << vw.id << "�˿ͣ�\n";
	else
		cout << "VIP���ڿ��У���\n";
	if (ow.isbuy == 1)
		cout << "�Թ��������ڷ���" << ow.type << ow.id << "�˿ͣ�\n";
	else
		cout << "�Թ����ڿ��У���\n";
	if (!nuqueue.empty())
		cout << "��ͨ�˿ͻ���	" << nuqueue.size() << "	���ڵȺ�" << endl;
	else
		cout << "��ͨ�˿��Ѿ����˵ȴ���" << endl;
	if (!vuqueue.empty())
		cout << "VIP�˿ͻ���	" << vuqueue.size() << "	���ڵȺ�" << endl;
	else
		cout << "VIP�˿��Ѿ����˵ȴ���" << endl;
	if (!ouqueue.empty())
		cout << "�Թ��˿ͻ���	" << ouqueue.size() << "	���ڵȺ�" << endl;
	else
		cout << "�Թ��˿��Ѿ��Ѿ����˵ȴ���" << endl;
}
void sim::simu()
{
	long t1, t2;
	simuserenter();
	t1 = time(0);
	t2 = time(0);
	while (1)
	{
		cout << endl << "Ӫҵ��ʼ" << endl;
		calluser();
		userenter();
		while (fabs(t2 - t1 - 2)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "�ڶ���" << endl;
		simuserenter();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 4)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "������" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 6)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "������" << endl;
		simuserenter();
		userenter();
		while (fabs(t2 - t1 - 8)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "�ڰ���" << endl;
		handle();
		calluser();
		userenter();
		while (fabs(t2 - t1 - 12)>10e-6)
		{
			t2 = time(0);
		}
		cout << endl << "Ӫҵ����" << endl; 
		handle();
		calluser();
		userenter();
		break;
	}
}
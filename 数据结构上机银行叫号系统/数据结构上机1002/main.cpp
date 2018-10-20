#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include<ctime>
#include"User.h"
#include"Bankwindow.h"
#include"Simulater.h"
using namespace std;

int main()
{
	sim s;			//新建一个银行
	s.simu();		//银行开始运行

	system("pause");
	return 0;
}
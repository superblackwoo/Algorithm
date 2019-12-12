// quick_sorting.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

void read(){
	int i = 0;
	ifstream ifs;
	ifs.open("C:\\Users\\Administrator\\Desktop\\算法实验\\实验一\\input1-data.txt",ios::in);
	if(!ifs.is_open()){
		cout<<"File open error"<<endl;
		return;
	}
	string buf;
	while (getline(ifs,buf)){
		i++;
		cout<<buf<<"     "<<i<<endl;
	}
	ifs.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	read();
	return 0;
}


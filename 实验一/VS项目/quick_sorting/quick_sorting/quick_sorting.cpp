// quick_sorting.cpp : �������̨Ӧ�ó������ڵ㡣
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
	ifs.open("C:\\Users\\Administrator\\Desktop\\�㷨ʵ��\\ʵ��һ\\input1-data.txt",ios::in);
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


#pragma once
#include<iostream>
#include<string>
using namespace std;

namespace space {
	class string {
	public:
		string();    //无参构造
		string(const char* str);      //初始化列表
		~string();      //析构函数

	private:
		char* _str;
		int _size;  //个数
		int _capacity; //容量  有效字符个数  不包含\0
	};
}

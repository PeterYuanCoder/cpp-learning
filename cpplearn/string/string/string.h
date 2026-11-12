#pragma once
#include<iostream>
#include<string>
using namespace std;

namespace space {
	class string {
	public:
		string();    //无参构造
		string(const char* str);      //初始化列表
		string(const string& s);    //s1(s2)
		string& operator=(const string& s);    //s1=s2
		~string();      //析构函数

		void reserve(size_t n);     //预留空间

		const char* c_str() const { return _str; }  //返回c风格的字符串指针
		size_t size() const { return _size; }


	private:
		char* _str;
		int _size;  //个数
		int _capacity; //容量  有效字符个数  不包含\0
	};
}

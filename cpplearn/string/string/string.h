#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
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
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = string::npos);
		size_t find(char ch, size_t pos = 0) const;
		void swap(string* s);

		const char* c_str() const { return _str; }  //返回c风格的字符串指针
		size_t size() const { return _size; }


		// 特殊,只有整形的const静态成员支持这么写
		static const size_t npos = -1;

	private:
		char* _str;
		int _size;  //个数
		int _capacity; //容量  有效字符个数  不包含\0
	};
}

#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

namespace space {
	class string {
	public:

		// 迭代器
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin() { return _str; }
		iterator end() { return _str + _size; }

		const_iterator begin() const { return _str; }
		const_iterator end() const { return _str + _size; }


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
		size_t find(const char* s, size_t pos = 0) const;
		string substr(size_t pos = 0, size_t len = npos) const;
		void swap(string* s);


		const char* c_str() const { return _str; }  //返回c风格的字符串指针
		size_t size() const { return _size; }
		size_t capacity() const { return _capacity; }
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// 特殊,只有整形的const静态成员支持这么写
		static const size_t npos = -1;

	private:
		char* _str;
		int _size;  //个数
		int _capacity; //容量  有效字符个数  不包含\0
	};


	string operator+ (const string& lhs, const string& rhs);
	string operator+ (const string& lhs, const char* rhs);
	string operator+ (const char* lhs, const string& rhs);

	bool operator== (const string& lhs, const string& rhs);
	bool operator!= (const string& lhs, const string& rhs);

	bool operator>(const string& lhs, const string& rhs);
	bool operator<(const string& lhs, const string& rhs);
	bool operator>= (const string& lhs, const string& rhs);
	bool operator<= (const string& lhs, const string& rhs);


	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
	istream& getline(istream& in, string& s);

}


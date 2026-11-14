#define _CRT_SECURE_NO_WARNINGS

#include"class_partner.h"


//声明和定义分离，需要确定类域
void Date::Init(int year, int month, int day)
{
	_year = year;
	this->_month = month;
	this->_day = day;
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//无参构造函数
Date::Date()
{
	_year = 1;
	_month = 1;
	_day = 1;
}

//带参构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}


//拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//普通构造函数
Date::Date(Date* d)
{
	_year = d->_year;
	_month = d->_month;
	_day = d->_day;
}

//重载访问私有成员变量
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}


//运算符重载
Date Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}



// C++升级struct升级成了类
// 1、类里面可以定义函数
// 2、struct名称就可以代表类型

// C++兼容C中struct的用法
typedef struct ListNodeC
{
	struct ListNodeC* next;
	int val;
}LTNode;

// 不再需要typedef，ListNodeCPP就可以代表类型
struct ListNodeCPP
{
	void Init(int x)
	{
		next = nullptr;
		val = x;
	}

	ListNodeCPP* next;
	int val;
};


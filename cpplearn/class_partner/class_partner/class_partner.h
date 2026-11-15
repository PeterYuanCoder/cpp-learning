#pragma once


#include<iostream>
using namespace std;

//
//class Time
//{
//public:
//    Time(int hour)
//        :_hour(hour)
//    {
//        cout << "Time()" << endl;
//    }
//private:
//    int _hour;
//};

class Date
{
public:
	//成员函数
	void Init(int year, int month, int day);
    void Print() const;

	Date();    //无参构造函数
	//Date(int year, int month, int day);     //带参构造函数
	//Date(int year = 1, int month = 1, int day = 1);      //全缺省构造函数

    Date(const Date& d);       //拷贝构造函数
    Date(Date* d);           //普通构造函数

    friend bool operator==(const Date& d1, const Date& d2);    //友元函数     也可以放在类里面，重载为成员函数

    Date operator=(const Date& d);           //运算符重载

    //初始化列表
    Date(int year = 1, int month = 1, int day = 1)
        :_year(year)
        , _month(month)
        , _day(day)
    {

    }

private:
	//成员变量

    // 注意这⾥不是初始化，这⾥给的是缺省值，这个缺省值是给初始化列表的
    // 如果初始化列表没有显⽰初始化，默认就会⽤这个缺省值初始化
    int _year = 1;
	int _month = 1;
	int _day;

};//分号不能少

// 重载为全局的面临对象访问私有成员变量的问题
// 有几种方法可以解决:
// 1、成员放公有
// 2、Date提供getxxx函数
// 3、友元函数
// 4、重载为成员函数
bool operator==(const Date& d1, const Date& d2);



typedef int STDataType;
class Stack
{
public:
    Stack(int n = 4)
    {
        _a = (STDataType*)malloc(sizeof(STDataType) * n);
        if (nullptr == _a)
        {
            perror("malloc申请空间失败");
            return;
        }

        _capacity = n;
        _top = 0;
    }

    ~Stack()
    {
        cout << "~Stack" << endl;
        free(_a);
        _a = nullptr;
        _top = _capacity = 0;
    }

private:
    STDataType* _a;
    size_t _capacity;
    size_t _top;
};

// 两个Stack实现队列
class MyQueue
{
public:
    //编译器默认生成MyQueue的构造函数调用了Stack的构造，完成了两个成员的初始化
private:
    Stack pushst;
    Stack popst;
};




class A
{
public:
    //把内置类型 `int(a)`，隐式转换成类类型 `A` 的临时对象。

    //初始化列表
    A(int a1)
        :_a1(a1)
    {

    }
    //构造函数explicit就不再支持隐式类型转换
    explicit A(int a1, int a2)
        :_a1(a1)
        , _a2(a2)
    {

    }
    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }

    int Git() const
    {
        return _a1 + _a2;
    }

private:
    int _a1 = 1;
    int _a2 = 1;
};


class B
{
public:
    B()
    {
        ++_scount;
    }

    B(const B& t)
    {
        ++_scount;
    }

    ~B()
    {
        --_scount;
    }

    static int GetBCount()
    {
        return _scount;
    }
private:
    // 类里面声明
    static int _scount;
};




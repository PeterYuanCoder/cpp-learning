#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<algorithm>

#include"list.h"
using namespace std;

void test_list()
{
	list<int> lt1(10, 1);
	list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.emplace_back(3);
	lt2.emplace_back(3);

	
	list<int> lt3 = { 3,3,3,3,3 };

	list<int>::iterator it = lt1.begin();
	while (it != lt1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : lt3)
	{
		cout << e << " ";
	}
}


void test_list1()
{
	list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.emplace_back(4);
	lt2.emplace_back(5);

	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	reverse(lt2.begin(), lt2.end());
	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it2 = find(lt2.begin(), lt2.end(),3);
	if (it2 != lt2.end())
	{
		lt2.erase(it2);     //注意区分 it 和 lt
	}
}

bool single_digit(const int& value) { return (value % 2 == 0); }
void test_list2()
{
	list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.emplace_back(4);
	lt2.emplace_back(5);
	lt2.emplace_back(5);
	lt2.emplace_back(5);
	lt2.emplace_back(5);
	
	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;


	auto it2 = find(lt2.begin(), lt2.end(), 3);
	if (it2 != lt2.end())
	{
		lt2.splice(lt2.begin(), lt2, it2);   //接和，，转移
	}

	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;


	//fand + erase
	lt2.remove(3);
	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	//满足条件删除
	lt2.remove_if(single_digit);
	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt1 = { 1,7,8,2,3,3,4,5,6,6,6,6 };
	for (auto& e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	lt1.sort();    //排序

	lt1.unique();           //去重但是必须有序   
	for (auto& e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_space_list1()
{
	space::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	lt1.push_front(10);
	lt1.push_front(20);
	lt1.push_front(30);
	lt1.push_front(40);

	for (auto& e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_list2();
	test_space_list1();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1;
//	string s2("hello world");
//	cout << s2 << endl;
//	cout << s2.size() << endl;   //size()不算字符串后面的'\0'
//
//	string s3("我是冠军");     
//	cout << s3.size() << endl;
//	return 0;
//}



//int main()
//{
//	string s1 = "12345";
//	
//	//下标+[]遍历
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	
//	//迭代器       行为像指针一样，通过访问容器的方式访问
//	//begin是第一个元素     end是最后一个元素的下一个元素
//	//左闭右开
//
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//
//	//范围for       自动依次取容器数据给对象    自动判断开始和结束位置 自动迭代
//	for (auto x : s1)
//	{
//		cout << x << " ";
//	}
//
//	return 0;
//}
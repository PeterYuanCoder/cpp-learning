#define _CRT_SECURE_NO_WARNINGS

#include"string.h"


//string 类的常见构造

//int main()
//{
//	string  s1;    //空的string 类的对象
//	string s2("hello world");
//	string s3(s1);      //构造拷贝函数
//	return 0;
//}


//string 容量操作函数

//size    返回有效字符个数
//length   返回字符串有效长度
//capacity  返回容量大小          小于15，编译器默认为15   只变大不缩小
//empty    测试字符串是否为空串   是返回true  不是返回false
//clear  清空有效字符
//resever   为字符串预留空间
//resize    将有效字符个数改为n个，其余的位置使用字符c来填充

//int main()
//{
//	string s1 = "hello world!!!";
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	cout << boolalpha;             //不加这一句返回的是0，而不是false
//	cout << s1.empty() << endl;
//	s1.clear();
//	cout << s1.empty() << endl;     //清空有效字符之后，就是返回true
//
//
//	string s2;
//	s2.reserve(100);     //预留100空间，capacity返回值空间必须大于100
//	cout << s2.capacity() << endl;
//
//	string s3 = "I like C";
//	s3.resize(s3.size() + 2, '+');
//	cout << s3 << endl;
//
//	return 0;
//}





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



//c_str  将cpp文件风格转换成c文件风格

//int main()
//{
//	string filename = "string.cpp";
//	FILE* fout = fopen(filename.c_str(), "r");
//	if (fout == nullptr)
//	{
//		perror("fopen fail");
//		return -1;
//	}
//	char ch = fgetc(fout);         //读取文件中的一个字符，文件指针向后移动一位
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//	return 0;
//}



//getline

//int main()
//{
//	string s1;
//	getline(cin, s1);
//	cout << s1 << endl;
//	
//	//使用cin输入字符串时，会将空格和\n看成结束      输入hello world  只会输出hello
//	string s2;
//	cin >> s2;
//	cout << s2 << endl;
//	return 0;
//}



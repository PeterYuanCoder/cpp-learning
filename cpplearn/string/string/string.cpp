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


//operator[]  下标访问方式
//迭代器访问
//范围for

//string 类对象的访问和遍历方式

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




//string 类的修改操作

//1. push_back     字符串尾插一个"字符" (不是字符串)

//int main()
//{
//	string s1 = "hello world";
//	s1.push_back('!');
//	cout << s1;
//	return 0;
//}


//2. append    在字符串后追加一个字符串

//int main()
//{
//	string s1;
//	string s2 = "hello world";
//	string s3 = "I love C";
//	
//	s1.append(s2);
//	cout << s1 << endl;
//	s2.append(s2);
//	cout << s2 << endl;
//
//	s2.append("!");
//	cout<<s2<<endl;
//	s3.append(2,'+');
//	cout << s3 << endl;
//	s3.append("+++", 2);   //从"+++"中取两个追加
//	cout << s3 << endl;
//
//	return 0;
//}



//3. operatot+=          在字符串后追加字符串

//int main()
//{
//	string s1;
//	string s2 = " world";
//	s1 += "hello";
//	cout << s1 << endl;
//
//	s1 += s2;
//	cout << s1 << endl;
//	
//	s1 += "!";
//	cout << s1 << endl;
//	return 0;
//}




//4. c_str  将cpp文件风格转换成c文件风格

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



//5. fing+npos    从字符串pos位置开始往后找字符c，返回该字符在字符串中的位置
//find       从字符串pos位置开始往前找字符c，返回该字符在字符串中的位置

//int main()
//{
//	string s1 = "hello world";
//	size_t top = s1.find("world");   //返回类型一定要是size_t
//	cout << top << endl;
//	size_t tmp = s1.rfind("o");
//	cout << tmp << endl;
//	return 0;
//}



//6. substr   在str中从pos位置开始，截取n个字符，然后将其返回

//int main()
//{
//	string s1 = "hello world";
//	string  s2 = s1.substr(0, 5);
//	cout << s2 << endl;
//	return 0;
//}


//7.insert       往前插入

//int main()
//{
//	string s1 = "hello";
//	string s2 = " world";
//	s1.insert(s1.size(), s2);
//	cout << s1 << endl;
//	s1.insert(s1.size(), "!");
//	cout << s1 << endl;
//	s1.insert(s1.size(), " hello world", 5);       //从字符串中取n个插入，到s1中。
//	cout << s1 << endl;
//	return 0;
//}


//8. erase         删除字符


//int main()
//{
//	//下标删除
//	string s1 = "hello world";
//	s1.erase(2,3);         //不给删除个数则是直接删到尾，或者不穿参直接全删
//	cout << s1 << endl;
//	
//	//迭代器删除
//	string s2 = "I love C++";
//	s2.erase(s2.begin() + 2);    //删除下标为2的字符
//	cout << s2 << endl;
//	
//	string s3 = "I love you";
//	s3.erase(s3.begin() + 2, s3.begin() + 5);    //左闭右开
//	cout << s3 << endl;
//	return 0;
//}


//string 类非成员函数


//1. operator+

//int main()
//{
//	string s1 = "hello";
//	string s2 = " world";
//	cout << s1 + s2 << endl;
//	return 0;
//}



//2. getline           获取一行字符串

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



//string 类的模拟实现

namespace space
{
	//构造函数
	string::string()
		:_str(new char[1])
		, _size(0)
		, _capacity(0)
	{
		_str[0] = '\0';
	}
	//初始化列表
	string::string(const char* str)
		:_size(strlen(str))
	{
		_capacity = _size;
		_str = new char[_size + 1];
		strcpy(_str, str);
	}

	string::string(const string& s)
		:_str(new char[s._capacity + 1])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		cout << "string::string(const string& s)" << endl;
		strcpy(_str, s._str);
	}

	//s1=s2
	//s1=s1
	string& string::operator=(const string& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}


	//析构函数
	string::~string()
	{
		delete _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	void string::reserve(size_t n)
	{
		if (_capacity > 0)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = 0;
		}
	}
}
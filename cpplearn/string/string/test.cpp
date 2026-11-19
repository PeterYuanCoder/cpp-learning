#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

#include"string.h"

void func(const space::string& s) {
	for (auto& ch : s) {
		cout << ch << " ";
	}
	cout << endl;

	// 迭代器
	//bit::string::const_iterator it = s.begin();
	auto it = s.begin();
	while (it != s.end()) {
		// *it = 'x';
		cout << *it << '%';
		++it;
	}
	cout << endl;
}

void teststring1() {
	std::string s3;
	cout << s3.c_str() << endl;

	space::string s2;
	cout << s2.c_str() << endl;

	space::string s1("hello world");
	cout << s1.c_str() << endl;

	// 下标+[]  最常用
	for (size_t i = 0; i < s1.size(); i++) {
		s1[i]++;
		cout << s1[i] << '|';
	}
	cout << endl;

	for (auto& ch : s1) {
		ch--;
	}
	cout << endl;

	// 迭代器
	space::string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << '%';
		++it;
	}
	cout << endl;
}

void teststring2() {
	/*std::string s1("hello");
	s1.append("xxxxxxxxxxxx");

	cout << s1.c_str() << endl;

	s1 += ' ';
	s1 += "yyyyyyyyyyyyyy";
	cout << s1.c_str() << endl;*/

	string s1("string.cpp");
	string s2("aaaa");
	const char* p1 = "bb";
	//cout << (s1 < s2) << endl;
	//cout << (s2 < p1) << endl;
	//cout << (p1 < s2) << endl;

	cout << s1 + p1 << endl;
	cout << p1 + s1 << endl;
	cout << s1 + p1 + s2 + p1 << endl;
}

void teststring3() {
	space::string s1("hello world");
	s1.insert(5, ' ');
	s1.insert(0, 'x');
	cout << s1.c_str() << endl;

	space::string s2;
	s2.insert(0, 'x');
	cout << s2.c_str() << endl;

	space::string s3("hello world");
	s3.insert(5, "xxx");
	s3.insert(0, "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
	cout << s3.c_str() << endl;

	space::string s4("hello worldxxxxxxxxxxxx");
	//s4.erase(11, 20);
	s4.erase(11);
	cout << s4.c_str() << endl;

	s4.erase(6, 3);
	cout << s4.c_str() << endl;

	space::string s5("abcabexxxx");
	cout << s5.find("abe") << endl;
	cout << s5.find("abx") << endl;

	space::string ret = s5.substr(3, 4);
	//cout << &ret << endl;
	cout << ret.c_str() << endl;

	space::string s6(s5);
	cout << s5.c_str() << endl;
	cout << s6.c_str() << endl;

	s6 = s3;
	cout << s6.c_str() << endl;
	cout << s3.c_str() << endl;

	s6 = s6;
	cout << s6.c_str() << endl;
}

void teststring4() {
	space::string s1("hello world");
	space::string s2("xxxx");
	const char* str = "yyyy";
	cout << s1 + s2 << endl;
	cout << s1 + str << endl;
	cout << str + s1 << endl;

	

	space::string s3;
	//cin >> s3;
	getline(cin, s3);
	cout << s3 << endl;
}

int main() {
	teststring1();

	return 0;
}
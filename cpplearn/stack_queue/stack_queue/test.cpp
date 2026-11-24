#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include"queue.h"
#include<stack>
#include<list>
#include<queue>
#include<algorithm>

//int main() {
//	//bit::stack<int> st;
//	//bit::stack<int, vector<int>> st;
//	space::stack<int, list<int>> st;
//	//std::stack<int, list<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty()) {
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//
//	//std::queue<int, list<int>> q;
//	//std::queue<int, vector<int>> q; // 不支持pop_front
//	//bit::queue<int> q;
//	space::queue<int, list<int>> q;
//	//bit::queue<int, vector<int>> q; // 不支持pop_front
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	while (!q.empty()) {
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}


////////////////////////////////////////////////////////////////////////

// 前置声明：priority_queue.h 的默认模板参数 Compare = Less<T> 需要在使用前看到 Less
template <class T> class Less;
template <class T> class Greater;

#include"priority_queue.h"

template <class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template <class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

//调用std里面的仿函数
void TestPriorityQueue1()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	//默认情况下大的优先级高

	//调整成小的优先级高
	priority_queue<int, vector<int>, greater<int>> q1(v.begin(), v.end());

	int k;
	cin >> k;
	while (k-- && !q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
}


void TestPriorityQueue2()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	//默认情况下大的优先级高


	// bit::priority_queue<int, vector<int>, Less<int>> q1;
	//bit::priority_queue<int, vector<int>, Greater<int>> q1;
	space::priority_queue <int,vector<int> > q1;
	for (auto& e : v)
		q1.push(e);

	int k;
	cin >> k;
	while (k-- && !q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
}

//int main()
//{
//	//TestPriorityQueue1();
//	TestPriorityQueue2();
//	return 0;
//}




/////////////////////////////////////////////////////////////////
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	// 友元声明
	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

class LessPDate {
public:
	bool operator()(const Date* x, const Date* y) {
		return *x < *y;
	}
};


// 特化
//template<>
//class Less<Date*> 
//{
//public:
//	bool operator()(Date* const & x, Date* const & y) {
//		return *x < *y;
//	}
//};



// 所有指针都用指向对象去比较，偏特化
template<class T>
class Less<T*>
{
public:
	bool operator()(T* const& x, T* const& y) {
		return *x < *y;
	}
};

class Conditional {
public:
	bool operator()(int x) {
		return x % 2 && x % 11 == 0;
	}
};



void TestPriorityQueue3() {
	// 自行写仿函数，控制比较逻辑，量身定做
	//space::priority_queue<Date*, vector<Date*>, LessPDate> q1;
	space::priority_queue<Date*> q1;
	q1.push(new Date(2026, 10, 29));
	q1.push(new Date(2026, 10, 28));
	q1.push(new Date(2026, 10, 30));
	q1.push(new Date(2020, 1, 30));
	q1.push(new Date(2021, 3, 30));

	int k;
	cin >> k;
	while (k-- && !q1.empty()) {
		cout << *q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	vector<int> v{ 3,2,7,6,0,4,1,9,8,5,2,2,3 };
	std::priority_queue<int, vector<int>, greater<int>> q2;
	for (auto& e : v)
		q2.push(e);

	cin >> k;
	while (k-- && !q2.empty()) {
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;

	// 升序
	sort(v.begin(), v.end());

	// 降序
	sort(v.begin(), v.end(), greater<int>());

	std::vector<int> myvector;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);

	std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), Conditional());
	std::cout << "The first odd value is " << *it << '\n';
}

int main() {
	TestPriorityQueue3();

	return 0;
}
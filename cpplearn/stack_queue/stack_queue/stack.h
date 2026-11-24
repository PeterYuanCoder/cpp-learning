#pragma once
#include<deque>
#include<iostream>
#include<stack>
using namespace std;

namespace space {
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x) { return _con.push_back(x); }
		void pop() { return _con.pop_back(); }
		size_t size() { return _con.size(); }
		bool empty() { return _con.empty(); }
		T& top() { return _con.back(); }
	private:
		Container _con;
	};
}

#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include"queue.h"
#include<stack>
#include<list>
#include<queue>
int main() {
	//bit::stack<int> st;
	//bit::stack<int, vector<int>> st;
	space::stack<int, list<int>> st;
	//std::stack<int, list<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	//std::queue<int, list<int>> q;
	//std::queue<int, vector<int>> q; // 不支持pop_front
	//bit::queue<int> q;
	space::queue<int, list<int>> q;
	//bit::queue<int, vector<int>> q; // 不支持pop_front
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
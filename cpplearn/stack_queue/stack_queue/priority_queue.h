#pragma once

//可以控制队列出来的顺序，可以让大的先出，或者是先让小的先出

//本质二叉树

#include<vector>
#include<iostream>
using namespace std;
namespace space
{
	//template <class T, class Container = std::vector<T>, class Compare = std::less<T>>

	//解耦
	//Compare

	template <class T, class Container = std::vector<T>, class Compare = Less<T>>

	class priority_queue
	{
	public:
		priority_queue(){}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last) {
			// 建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--) {
				adjust_down(i);
			}
		}

		void adjust_up(int child)
		{
			int parent = (child - 1) / 2;
			Compare compare;
			while (child > 0)
			{
				if (compare(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}


		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		//向下调整算法
		void adjust_down(int parent)
		{
			int child = parent * 2 + 1;
			Compare compare;

			while (child < _con.size())
			{
				if (child + 1 < _con.size() && compare(_con[child],_con[child + 1]))
				{
					child++;
				}
				if (compare(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}


		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			//向下调整算法
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}

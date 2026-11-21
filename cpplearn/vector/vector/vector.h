#pragma once

#include<assert.h>
#include<iostream>
using namespace std;

namespace space
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }
		vector()       //无参构造
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T* operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserse(size_t n);
		//void resize(size_t n, const T& val);

		void push_back(const T& x);
		void pop_back();

		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);

		size_t capacity() const { return _end_of_storage - _start; }
		size_t size() const { return _finish - _start; }
		bool empty()const { return _start == _finish; }
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	template<class T>
	void vector<T>::reserse(size_t n)
	{
		//不考虑缩容
		if (n > capacity())
		{
			size_t old_size = size();
			T* tmp = new T[n];
			if (_start != nullptr)
			{
				memcpy(tmp, _start, sizeof(T) * old_size);
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + old_size;
			_end_of_storage = _start + n;
		}
	}

	template<class T>
	void vector<T>::push_back(const T& x)
	{
		//扩容
		if (_finish == _end_of_storage)
		{
			size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
			reserve(newCapacity);
		}
		*_finish = x;
		_finishi++;
	}

	template<class T>
	void pop_back()
	{
		assert(!empty);
		--_finish;
	}



	template<class T>
	void vector<T>::insert(iterator pos, const T& x)
	{
		assert(pos >= _start);
		assert(pos <= _finish);
		//扩容 迭代器失效
		if (_finish == _end_of_storage)
		{
			size_t len = _finish - _start;
			size_t newCapacity = capacity == 0 ? 4 : capacity * 2;
			reserve(newCapacity);
			pos = _start + len;      // 扩容后更新pos，解决pos失效的问题
		}
		memmove(pos + 1, pos, sizeof(T) * (_finish - pos));
		*_finish = x;
		_finish++;
	}


	// 无法区分内嵌类型和静态成员变量,typename 告诉编译器这里是内嵌类型
	template<class T>
	typename vector<T>::iterator vector<T>::erase(iterator pos) {
		assert(pos >= _start);
		assert(pos < _finish);

		iterator it = pos + 1;
		while (it < _finish) {
			*(it - 1) = *it;
			++it;
		}
		--_finish;

		return pos;
	}

}

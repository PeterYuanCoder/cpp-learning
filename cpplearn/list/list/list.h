#pragma once
#include<assert.h>
namespace space
{
	template<class T>
	struct list_node            //struct 默认是共有
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& x = T())      //初始化列表
			:_next(nullptr)
			, _prev(nullptr)
		,_val(x){

		}
	};

	//Node* 不支持迭代器功能,使用类封装,重载运算符
	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;
		list_iterator(Node* node)
		:_node(node){

		}
		T& operator*()
		{
			return _node->_val;
		}

		list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		list_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		bool operator!=(const list_iterator<T>& it)
		{
			return _node != it._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T> iterator;  //使用类封装达到迭代器的功能

		iterator begin()
		{
			return list_iterator<T>(_head->_next);
		}
		iterator end()
		{
			return list_iterator<T>(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}

		// lt2(lt1)
		list(list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		list<T>& operator=(list lt)
		{
			swap(lt);
			return *this;
		}
		


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//erase返回下一个位置的迭代器
				it = erase(it);
				
			}
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			
			tail->_next = newnode;
			newnode->_prev = tail->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		//pos前插入
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			//prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			_size--;
			return iterator(next);
		}

		void pop_back()
		{
			erase(end()--);
		}
		void pop_front()
		{
			erase(begin());
		} 
	private:
		Node* _head;
		size_t _size;
	};
}
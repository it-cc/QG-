#pragma once
#include "MyLinkedList.hpp"
using namespace std;

template <class T>
class MyLinkedStack
{
private:
	MyLinkedList<T> list;
public:
	void push(const T& val);
	T pop();
	T top();
	int size();
	void clear();
};

// 向栈顶加入元素
template <class T>
void MyLinkedStack<T>::push(const T& val)
{
	list.push_back(val);
}

// 查看栈顶元素
template <class T>
T MyLinkedStack<T>::pop()
{
	if (list.isEmpty())
	{
		throw out_of_range("栈为空！");
	}
	T val = list.back();
	list.pop_back();
	return val;
}

// 从栈顶弹出元素
template <class T>
T MyLinkedStack<T>::top()
{
	if (list.isEmpty())
	{
		throw out_of_range("栈为空！");
	}
	return list.back();
}

// 返回栈中的元素个数
template <class T>
int MyLinkedStack<T>::size()
{
	return list.getSize();
}

template <class T>
void MyLinkedStack<T>::clear()
{
	while (!list.isEmpty())
	{
		list.pop_back();
	}
}
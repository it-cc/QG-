#pragma once
#pragma once
#include "MyLinkedList.hpp"

template <class T>
class MyLinkedQueue
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

template <class T>
void MyLinkedQueue<T>::push(const T& val)
{
	list.push_back(val);
}


template <class T>
T MyLinkedQueue<T>::pop()
{
	if (list.isEmpty())
	{
		throw out_of_range("队列为空！");
	}
	T val = list.front();
	list.pop_front();
	return val;
}


template <class T>
T MyLinkedQueue<T>::top()
{
	if (list.isEmpty())
	{
		throw out_of_range("队列为空！");
	}
	return list.front();
}


template <class T>
int MyLinkedQueue<T>::size()
{
	return list.getSize();
}


template <class T>
void MyLinkedQueue<T>::clear()
{
	while (!list.isEmpty())
	{
		list.pop_front();
	}
}
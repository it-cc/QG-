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

// ��ջ������Ԫ��
template <class T>
void MyLinkedStack<T>::push(const T& val)
{
	list.push_back(val);
}

// �鿴ջ��Ԫ��
template <class T>
T MyLinkedStack<T>::pop()
{
	if (list.isEmpty())
	{
		throw out_of_range("ջΪ�գ�");
	}
	T val = list.back();
	list.pop_back();
	return val;
}

// ��ջ������Ԫ��
template <class T>
T MyLinkedStack<T>::top()
{
	if (list.isEmpty())
	{
		throw out_of_range("ջΪ�գ�");
	}
	return list.back();
}

// ����ջ�е�Ԫ�ظ���
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
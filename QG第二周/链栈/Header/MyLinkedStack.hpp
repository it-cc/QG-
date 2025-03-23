#pragma once

#include <list>
#include <iostream>
using namespace std;

template<typename E>
class MyLinkedStack 
{
private:
    list<E> list;

public:
    void push(const E& e);
    E pop();
    E peek() const;
    int size() const;
    void clearStack();
};

// ��ջ������Ԫ�أ�ʱ�临�Ӷ� O(1)
template<typename E>
void MyLinkedStack<E>::push(const E& e)
{
    list.push_back(e);
}

// ��ջ������Ԫ�أ�ʱ�临�Ӷ� O(1)
template<typename E>
E MyLinkedStack<E>::pop()
{
    if (list.empty()) 
    {
        throw out_of_range("ջΪ�գ�");
    }
    E value = list.back();
    list.pop_back();
    return value;
}

// �鿴ջ��Ԫ�أ�ʱ�临�Ӷ� O(1)
template<typename E>
E MyLinkedStack<E>::peek() const
{
    if (list.empty())
    {
        throw out_of_range("ջΪ�գ�");
    }
    return list.back();
}

// ����ջ�е�Ԫ�ظ�����ʱ�临�Ӷ� O(1)
template<typename E>
int MyLinkedStack<E>::size() const
{
    return list.size();
}

template<typename E>
void MyLinkedStack<E>::clearStack()
{
    while (!list.empty())
    {
        list.pop_back();
    }
}
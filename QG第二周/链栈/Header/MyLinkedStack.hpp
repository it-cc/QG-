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

// 向栈顶加入元素，时间复杂度 O(1)
template<typename E>
void MyLinkedStack<E>::push(const E& e)
{
    list.push_back(e);
}

// 从栈顶弹出元素，时间复杂度 O(1)
template<typename E>
E MyLinkedStack<E>::pop()
{
    if (list.empty()) 
    {
        throw out_of_range("栈为空！");
    }
    E value = list.back();
    list.pop_back();
    return value;
}

// 查看栈顶元素，时间复杂度 O(1)
template<typename E>
E MyLinkedStack<E>::peek() const
{
    if (list.empty())
    {
        throw out_of_range("栈为空！");
    }
    return list.back();
}

// 返回栈中的元素个数，时间复杂度 O(1)
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
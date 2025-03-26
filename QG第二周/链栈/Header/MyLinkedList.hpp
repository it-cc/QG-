#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class MyLinkedList 
{
private:
	struct Node
	{
		T val;
		Node* next;
		Node(T val) :val(val), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	int size;

public:
	MyLinkedList()
	{
		head = new Node(T());
		tail = head;
		size = 0;
	}
	// ***** 增 *****
	void push_back(T val);
	void push_front(T val);
	void insert(int index, T val);//插入到index的后面

	// ***** 删 *****
	void pop_back();
	void pop_front();
	void erase(int index);

	// ***** 查 *****
	T back();
	T front();
	void print();

	// ***** 改 *****
	void set(int index,T val);

	// ***** 工具函数 *****
	bool isEmpty();
	int getSize();
	~MyLinkedList();

private:
	bool isElementIndex(int index);//判断index是否是有效的元素索引
	bool isPositionIndex(int index);//判断index是否是有效的位置索引
	void checkElementIndex(int index);
	void checkPositionIndex(int index);
	Node* getNode(int index);

};

// ***** 增*****
template<typename T>
void MyLinkedList<T>::push_back(T val)
{
	Node* newnode = new Node(val);
	tail->next = newnode;
	tail = newnode;
	size++;
	
}

template<typename T>
void MyLinkedList<T>::push_front(T val)
{
	Node* newnode = new Node(val);
	Node* next = head->next;
	head->next = newnode;
	newnode->next = next;
	if (isEmpty())
	{
		tail = newnode;
	}
	size++;
}

template<typename T>
void MyLinkedList<T>::insert(int index, T val)
{
	checkPositionIndex(index);
	if (index == size) 
	{
		push_back(val);
		return;
	}
	Node* prev = head;//prev用于找到前一个结点
	for (int i = 0; i < index; i++)
	{
		prev = prev->next;
	}
	Node* next = prev->next;
	Node* newNode = new Node(val);
	prev->next = newNode;
	newNode->next = next;
	size++;
}

// ***** 删 *****
template<typename T>
void MyLinkedList<T>::pop_back()
{
	if (isEmpty())
	{
		throw out_of_range("无可删除的元素！");
	}
	Node* prev = head;
	while (prev->next != tail)
	{
		prev = prev->next;
	}
	delete tail;
	prev->next = nullptr;
	tail = prev;
	size--;
}

template<typename T>
void MyLinkedList<T>::pop_front()
{
	if (isEmpty())
	{
		throw out_of_range("无可删除的元素！");
	}
	Node* first = head->next;
	head->next = first->next;
	if (size == 1)
	{
		tail = head;
	}
	delete first;
	size--;
}

template<typename T>
void MyLinkedList<T>::erase(int index)
{
	checkElementIndex(index);
	Node* prev = head;
	for (int i = 0; i < index; i++)
	{
		prev = prev->next;
	}
	Node* curr = prev->next;
	Node* next = curr->next;
	prev->next = next;
	if (index == size - 1)
	{
		tail = prev;
	}
	delete curr;
	size--;
}

// ***** 查 *****
template<typename T>
T MyLinkedList<T>::back()
{
	if (isEmpty())
	{
		throw out_of_range("链表中没有元素！");
	}
	return tail->val;
}

template<typename T>
T MyLinkedList<T>::front()
{
	if (isEmpty())
	{
		throw out_of_range("链表中没有元素！");
	}
	return head->next->val;
}

template<typename T>
void MyLinkedList<T>::print()
{
	if (isEmpty())
	{
		throw out_of_range("链表中没有元素！");
	}
	Node* curr = head->next;
	for (int i = 0; i < size; i++)
	{
		cout << curr->val << "->";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

// ***** 改 *****
template<typename T>
void  MyLinkedList<T>::set(int index,T val)
{
	checkElementIndex(index);
	getNode(index)->val=val;
}

// ***** 其他工具函数 *****
template<typename T>
bool MyLinkedList<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
int MyLinkedList<T>::getSize()
{
	return size;
}


template<typename T>
MyLinkedList<T>::~MyLinkedList()
{
	Node* curr = head;
	while (curr != nullptr)
	{
		Node* next = curr->next;
		delete curr;
		curr = next;
	}
}

template<typename T>
bool MyLinkedList<T>::isElementIndex(int index)
{
	return index >= 0 && index < size;
}


template<typename T>
bool MyLinkedList<T>::isPositionIndex(int index)
{
	return index >= 0 && index <= size;
}

// 检查 index 索引位置是否可以存在元素
template<typename T>
void MyLinkedList<T>::checkElementIndex(int index)
{
	if(!isElementIndex(index))
	{ 
		throw out_of_range("无效的索引！index:"+to_string(index)+"size:"+to_string(size));
	}
}

// 检查 index 索引位置是否可以添加元素
template<typename T>
void MyLinkedList<T>::checkPositionIndex(int index)
{
	if (!isPositionIndex(index))
	{
		throw out_of_range("该位置无法插入元素！index" + to_string(index) + "size:" + to_string(size));
	}
}

// 返回 index 对应的 Node
// 注意：请保证传入的 index 是合法的
template<typename T>
typename MyLinkedList<T>::Node* MyLinkedList<T>::getNode(int index)
{
	Node* node = head->next;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	return node;
}
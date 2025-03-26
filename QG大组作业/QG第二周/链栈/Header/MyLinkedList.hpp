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
	// ***** �� *****
	void push_back(T val);
	void push_front(T val);
	void insert(int index, T val);//���뵽index�ĺ���

	// ***** ɾ *****
	void pop_back();
	void pop_front();
	void erase(int index);

	// ***** �� *****
	T back();
	T front();
	void print();

	// ***** �� *****
	void set(int index,T val);

	// ***** ���ߺ��� *****
	bool isEmpty();
	int getSize();
	~MyLinkedList();

private:
	bool isElementIndex(int index);//�ж�index�Ƿ�����Ч��Ԫ������
	bool isPositionIndex(int index);//�ж�index�Ƿ�����Ч��λ������
	void checkElementIndex(int index);
	void checkPositionIndex(int index);
	Node* getNode(int index);

};

// ***** ��*****
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
	Node* prev = head;//prev�����ҵ�ǰһ�����
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

// ***** ɾ *****
template<typename T>
void MyLinkedList<T>::pop_back()
{
	if (isEmpty())
	{
		throw out_of_range("�޿�ɾ����Ԫ�أ�");
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
		throw out_of_range("�޿�ɾ����Ԫ�أ�");
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

// ***** �� *****
template<typename T>
T MyLinkedList<T>::back()
{
	if (isEmpty())
	{
		throw out_of_range("������û��Ԫ�أ�");
	}
	return tail->val;
}

template<typename T>
T MyLinkedList<T>::front()
{
	if (isEmpty())
	{
		throw out_of_range("������û��Ԫ�أ�");
	}
	return head->next->val;
}

template<typename T>
void MyLinkedList<T>::print()
{
	if (isEmpty())
	{
		throw out_of_range("������û��Ԫ�أ�");
	}
	Node* curr = head->next;
	for (int i = 0; i < size; i++)
	{
		cout << curr->val << "->";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

// ***** �� *****
template<typename T>
void  MyLinkedList<T>::set(int index,T val)
{
	checkElementIndex(index);
	getNode(index)->val=val;
}

// ***** �������ߺ��� *****
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

// ��� index ����λ���Ƿ���Դ���Ԫ��
template<typename T>
void MyLinkedList<T>::checkElementIndex(int index)
{
	if(!isElementIndex(index))
	{ 
		throw out_of_range("��Ч��������index:"+to_string(index)+"size:"+to_string(size));
	}
}

// ��� index ����λ���Ƿ�������Ԫ��
template<typename T>
void MyLinkedList<T>::checkPositionIndex(int index)
{
	if (!isPositionIndex(index))
	{
		throw out_of_range("��λ���޷�����Ԫ�أ�index" + to_string(index) + "size:" + to_string(size));
	}
}

// ���� index ��Ӧ�� Node
// ע�⣺�뱣֤����� index �ǺϷ���
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
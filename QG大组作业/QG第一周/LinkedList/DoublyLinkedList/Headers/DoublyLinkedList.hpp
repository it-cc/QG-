#include <iostream>
#include <stdexcept>
#include <string>


template<typename E>
class MyLinkedList 
{
    // ����ͷβ�ڵ�
    struct Node 
    {
        E val;
        Node* next;
        Node* prev;

        Node(E value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // ���캯����ʼ������ͷβ�ڵ�
    MyLinkedList() 
    {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // ***** �� *****

    void addLast(E e) 
    {
        Node* x = new Node(e);
        Node* temp = tail->prev;
        // temp <-> x
        temp->next = x;
        x->prev = temp;

        x->next = tail;
        tail->prev = x;
        // temp <-> x <-> tail
        size++;
    }

    void addFirst(E e) 
    {
        Node* x = new Node(e);
        Node* temp = head->next;
        // head <-> temp
        temp->prev = x;
        x->next = temp;

        head->next = x;
        x->prev = head;
        // head <-> x <-> temp
        size++;
    }

    void add(int index, E element) 
    {
        checkPositionIndex(index);
        if (index == size) 
        {
            addLast(element);
            return;
        }

        // �ҵ� index ��Ӧ�� Node
        Node* p = getNode(index);
        Node* temp = p->prev;
        // temp <-> p

        // ��Ҫ����� Node
        Node* x = new Node(element);

        p->prev = x;
        temp->next = x;

        x->prev = temp;
        x->next = p;

        // temp <-> x <-> p

        size++;
    }

    // ***** ɾ *****

    E removeFirst() 
    {
        if (size < 1) 
        {
            throw std::out_of_range("No elements to remove");
        }
        // ����ڵ�Ĵ��������ǲ��ÿ��ǿ�ָ�������
        Node* x = head->next;
        Node* temp = x->next;
        // head <-> x <-> temp
        head->next = temp;
        temp->prev = head;

        delete x;
        // head <-> temp

        size--;
        return temp->val;
    }

    E removeLast() 
    {
        if (size < 1) 
        {
            throw std::out_of_range("No elements to remove");
        }
        Node* x = tail->prev;
        Node* temp = tail->prev->prev;
        // temp <-> x <-> tail

        tail->prev = temp;
        temp->next = tail;

        delete x;
        // temp <-> tail

        size--;
        return temp->val;
    }

    E remove(int index) 
    {
        checkElementIndex(index);
        // �ҵ� index ��Ӧ�� Node
        Node* x = getNode(index);
        Node* prev = x->prev;
        Node* next = x->next;
        // prev <-> x <-> next
        prev->next = next;
        next->prev = prev;

        delete x;
        // prev <-> next

        size--;

        return next->val;
    }

    // ***** �� *****

    E get(int index) 
    {
        checkElementIndex(index);
        // �ҵ� index ��Ӧ�� Node
        Node* p = getNode(index);

        return p->val;
    }

    E getFirst() 
    {
        if (size < 1) 
        {
            throw std::out_of_range("No elements in the list");
        }

        return head->next->val;
    }

    E getLast() 
    {
        if (size < 1) 
        {
            throw std::out_of_range("No elements in the list");
        }

        return tail->prev->val;
    }

    // ***** �� *****

    E set(int index, E val) 
    {
        checkElementIndex(index);
        // �ҵ� index ��Ӧ�� Node
        Node* p = getNode(index);

        E oldVal = p->val;
        p->val = val;

        return oldVal;
    }

    // ***** �������ߺ��� *****

    int getSize() const 
    {
        return size;
    }

    bool isEmpty() const 
    {
        return size == 0;
    }

private:
    Node* getNode(int index)
    {
        checkElementIndex(index);
        Node* p = head->next;
        // TODO: �����Ż���ͨ�� index �жϴ� head ���� tail ��ʼ����
        for (int i = 0; i < index; i++) 
        {
            p = p->next;
        }
        return p;
    }

    bool isElementIndex(int index) const 
    {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) const 
    {
        return index >= 0 && index <= size;
    }

     //��� index ����λ���Ƿ���Դ���Ԫ��
    void checkElementIndex(int index) const 
    {
        if (!isElementIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    // ��� index ����λ���Ƿ�������Ԫ��
    void checkPositionIndex(int index) const 
    {
        if (!isPositionIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

public:
    void display() 
    {
        std::cout << "size = " << size << std::endl;
        for (Node* p = head->next; p != tail; p = p->next) 
        {
            std::cout << p->val << " <-> ";
        }
        std::cout << "null" << std::endl;
        std::cout << std::endl;
    }

    ~MyLinkedList() 
    {
        while (size > 0) 
        {
            removeFirst();
        }
        delete head;
        delete tail;
    }
};
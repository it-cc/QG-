//
// Created by k on 25-4-7.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include "Menu.h"
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
using namespace std;
template <typename T>
class MyPriorityQueue
{
private:
    // 堆数组
    std::vector<T> heap;

    // 堆中元素的数量
    int size;

    // 元素比较器
    std::function<bool(const T&, const T&)> comparator;

    // 父节点的索引
    int parent(int node)
    {
        return (node - 1) / 2;
    }

    // 左子节点的索引
    int left(int node)
    {
        return node * 2 + 1;
    }

    // 右子节点的索引
    int right(int node)
    {
        return node * 2 + 2;
    }

    // 交换数组的两个元素
    void swap(int i, int j)
    {
        std::swap(heap[i], heap[j]);
    }

    // 调整堆的大小
    void resize(int capacity)
    {
        if (capacity > size)
        {
            heap.resize(capacity);
        }
    }

    // 上浮操作，时间复杂度是树高 O(logN)
    void swim(int node)
    {
        while (node > 0 && comparator(heap[parent(node)], heap[node]))
        {
            swap(parent(node), node);
            node = parent(node);
        }
    }

    // 下沉操作，时间复杂度是树高 O(logN)
    void sink(int node)
    {
        while (left(node) < size || right(node) < size)
        {
            // 比较自己和左右子节点，看看谁最小
            int min = node;
            if (left(node) < size && comparator(heap[min], heap[left(node)]))
            {
                min = left(node);
            }
            if (right(node) < size && comparator(heap[min], heap[right(node)]))
            {
                min = right(node);
            }
            if (min == node)
            {
                break;
            }
            // 如果左右子节点中有比自己小的，就交换
            swap(node, min);
            node = min;
        }
    }

public:
    // 构造函数
    MyPriorityQueue(int capacity, std::function<bool(const T&, const T&)> comparator)
        : heap(capacity), size(0), comparator(std::move(comparator)) {}

    // 返回堆的大小
    int getSize() const
    {
        return size;
    }

    // 判断堆是否为空
    bool isEmpty() const
    {
        return size == 0;
    }

    // 查，返回堆顶元素，时间复杂度 O(1)
    const T& peek() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Priority queue underflow");
        }
        return heap[0];
    }

    // 增，向堆中插入一个元素，时间复杂度 O(logN)
    void push(const T& x)
    {
        // 扩容
        if (size == heap.size())
        {
            resize(2 * heap.size());
        }
        // 把新元素追加到最后
        heap[size] = x;
        // 然后上浮到正确位置
        swim(size);
        size++;
    }

    // 删，删除堆顶元素，时间复杂度 O(logN)
    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Priority queue underflow");
        }
        T res = heap[0];
        // 把堆底元素放到堆顶
        swap(0, size - 1);
        size--;
        // 然后下沉到正确位置
        sink(0);
        // 缩容
        if (size > 0 && size == heap.size() / 4)
        {
            resize(heap.size() / 2);
        }
        return res;
    }
};

void handleHeapOperations(MyPriorityQueue<int> &heap)
{
    system("pause");
    system("cls");
    int choice, value;
    while (true)
    {
        Menu::menu();
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout << "请输入要插入的值：";
            cin>>value;
            heap.push(value);
            cout<<"插入成功！"<<endl;
            break;
            case 2:
                try
                {
                    cout << "弹出的元素为：" << heap.pop() << endl;
                }
            catch (const underflow_error& e)
            {
                cerr << e.what();
            }
            break;
            case 3:
                try
                {
                    cout << "堆顶的元素为：" << heap.peek() << endl;
                }
            catch (const underflow_error& e)
            {
                cerr << e.what()<<endl;;
            }
            break;
            case 4:
                cout << "元素的数量为" << heap.getSize() << endl;
            break;
            case 5:
                // 退出系统
                cout << "欢迎下次使用！" << endl;
                system("pause");
            return;
            default:
                cerr << "请重新选择！" << endl;
        }
        system("pause");
        system("cls");
    }
}



#endif //PRIORITYQUEUE_H

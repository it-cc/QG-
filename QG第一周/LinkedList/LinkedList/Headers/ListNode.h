#pragma once
#include <iostream>
using namespace std;
#define LEN sizeof(ListNode)


class ListNode 
{
public:
    // 默认构造函数
    ListNode() : val(0), next(nullptr) {}

    // 带参数的构造函数
    ListNode(int value) : val(value), next(nullptr){}


    // 成员函数
    void insertNode(ListNode* head);

    void deleteNode(ListNode*& head);

    void searchNode(ListNode* head);

    ListNode* exchangeNode(ListNode* head);//单链表奇偶调换

    ListNode* MidNode(ListNode* head);//找到单链表的中点

    bool hasCycle(ListNode* head);//判断是否成环

    ListNode* reverseList(ListNode* head);//反转链表（非递归）

    ListNode* reverseList_recursion(ListNode* head);//反转链表（递归）

    ListNode* creatList();//创建链表

    void for_each(ListNode* head);//遍历链表


    //成员变量
    int val;
    ListNode* next;
};

void menu();

#pragma once
#include <iostream>
using namespace std;
#define LEN sizeof(ListNode)


class ListNode 
{
public:
    // Ĭ�Ϲ��캯��
    ListNode() : val(0), next(nullptr) {}

    // �������Ĺ��캯��
    ListNode(int value) : val(value), next(nullptr){}


    // ��Ա����
    void insertNode(ListNode* head);

    void deleteNode(ListNode*& head);

    void searchNode(ListNode* head);

    ListNode* exchangeNode(ListNode* head);//��������ż����

    ListNode* MidNode(ListNode* head);//�ҵ���������е�

    bool hasCycle(ListNode* head);//�ж��Ƿ�ɻ�

    ListNode* reverseList(ListNode* head);//��ת�����ǵݹ飩

    ListNode* reverseList_recursion(ListNode* head);//��ת�����ݹ飩

    ListNode* creatList();//��������

    void for_each(ListNode* head);//��������


    //��Ա����
    int val;
    ListNode* next;
};

void menu();

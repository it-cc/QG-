#include "ListNode.h"

ListNode* ListNode::creatList()
{
    cout << "��ʼ�����������������ֵ������ -1 ʱ�������롣" << endl;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int value;
    while (true)
    {
        cout << "������һ������������ -1 ��������";
        // ��������Ƿ�Ϊ��Ч������
        cin >> value;

        if (value == -1) 
        {
            cout << "�����������������ɡ�" << endl;
            break;
        }

        ListNode* newNode = new ListNode(value);
        if (!head) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
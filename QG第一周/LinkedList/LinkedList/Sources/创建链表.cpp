#include "ListNode.h"

ListNode* ListNode::creatList()
{
    cout << "开始创建链表。请输入结点的值，输入 -1 时结束输入。" << endl;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int value;
    while (true)
    {
        cout << "请输入一个整数（输入 -1 结束）：";
        // 检查输入是否为有效的整数
        cin >> value;

        if (value == -1) 
        {
            cout << "输入结束，链表创建完成。" << endl;
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
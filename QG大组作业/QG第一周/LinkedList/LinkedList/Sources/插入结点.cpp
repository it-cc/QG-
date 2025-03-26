#include "ListNode.h"

void ListNode::insertNode(ListNode* head)
{
    if (head == nullptr) return;

    int givenValue, newValue;
    cout << "请输入要插入的位置前面的数据: ";
    cin >> givenValue;

    cout << "请输入要插入的值: ";
    cin >> newValue;

    // 移动指针，找到指定的数
    ListNode* pCurrent = head;
    ListNode* pNext = head->next;
    
    while (pCurrent != nullptr) {
        if (pCurrent->val == givenValue) break;
        pCurrent = pNext;
        pNext = pNext->next;
    }

    // 如果未找到指定位置
    if (pCurrent == nullptr) {
        cout << "未找到指定位置，插入失败。" << endl;
        return;
    }

    // 创建新结点
    ListNode* newnode = new ListNode(newValue);
    // 连接插入的结点
    pCurrent->next = newnode;
    newnode->next = pNext;
    cout << "插入成功。" << endl;
}
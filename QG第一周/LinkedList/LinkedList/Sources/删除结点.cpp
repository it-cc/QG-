#include "ListNode.h"

void ListNode::deleteNode(ListNode*& head)
{
    if (head == nullptr) return;

    cout << "请输入要删除的数据: ";
    int givenNum;
    // 输入错误处理
    while (!(cin >> givenNum)) {
        cout << "输入无效，请输入一个整数: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 处理要删除的节点是头节点的情况
    if (head->val == givenNum) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        cout << "删除成功" << endl;
        return;
    }

    ListNode* pPrev = head;
    ListNode* pCurrent = pPrev->next;
    // 如果找不到指定的数字，pCurrent 会移动到 nullptr
    while (pCurrent != nullptr) {
        // 找到了指定的数
        if (pCurrent->val == givenNum) 
        {
            pPrev->next = pCurrent->next;
            delete pCurrent;
            cout << "删除成功" << endl;
            return;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
    cout << "删除失败，没有这个数据" << endl;
}
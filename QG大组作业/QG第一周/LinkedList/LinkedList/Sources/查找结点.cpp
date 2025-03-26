#include "ListNode.h"

void ListNode::searchNode(ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "链表为空，无法查询!" << endl;
        return;
    }
   
    ListNode* pCurrent = head;
    cout << "请输入要查找的数据" << endl;
    int givenValue;
    cin >> givenValue;
    while (pCurrent != NULL)
    {
        if (pCurrent->val == givenValue)
        {
            cout << "存在此数据!" << endl;
            break;
        }
        pCurrent = pCurrent->next;
    }
    if (pCurrent == NULL)
    {
        printf("不存在此数据!");
    }
}
#include "ListNode.h"

void ListNode::searchNode(ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "����Ϊ�գ��޷���ѯ!" << endl;
        return;
    }
   
    ListNode* pCurrent = head;
    cout << "������Ҫ���ҵ�����" << endl;
    int givenValue;
    cin >> givenValue;
    while (pCurrent != NULL)
    {
        if (pCurrent->val == givenValue)
        {
            cout << "���ڴ�����!" << endl;
            break;
        }
        pCurrent = pCurrent->next;
    }
    if (pCurrent == NULL)
    {
        printf("�����ڴ�����!");
    }
}
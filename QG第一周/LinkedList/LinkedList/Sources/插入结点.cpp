#include "ListNode.h"

void ListNode::insertNode(ListNode* head)
{
    if (head == nullptr) return;

    int givenValue, newValue;
    cout << "������Ҫ�����λ��ǰ�������: ";
    cin >> givenValue;

    cout << "������Ҫ�����ֵ: ";
    cin >> newValue;

    // �ƶ�ָ�룬�ҵ�ָ������
    ListNode* pCurrent = head;
    ListNode* pNext = head->next;
    
    while (pCurrent != nullptr) {
        if (pCurrent->val == givenValue) break;
        pCurrent = pNext;
        pNext = pNext->next;
    }

    // ���δ�ҵ�ָ��λ��
    if (pCurrent == nullptr) {
        cout << "δ�ҵ�ָ��λ�ã�����ʧ�ܡ�" << endl;
        return;
    }

    // �����½��
    ListNode* newnode = new ListNode(newValue);
    // ���Ӳ���Ľ��
    pCurrent->next = newnode;
    newnode->next = pNext;
    cout << "����ɹ���" << endl;
}
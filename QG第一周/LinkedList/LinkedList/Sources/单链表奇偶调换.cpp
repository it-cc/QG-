#include "ListNode.h"
ListNode* ListNode::exchangeNode(ListNode* head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    while (head && head->next)
    {
        // ���浱ǰ�ڵ����һ���ڵ�
        ListNode* first = head;
        ListNode* second = head->next;

        // �����ڵ�
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // ����ָ��
        prev = first;
        head = first->next;
    }

    return dummy.next;
}
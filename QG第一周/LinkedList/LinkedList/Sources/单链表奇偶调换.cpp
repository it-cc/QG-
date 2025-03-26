#include "ListNode.h"
ListNode* ListNode::exchangeNode(ListNode* head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    while (head && head->next)
    {
        // 保存当前节点和下一个节点
        ListNode* first = head;
        ListNode* second = head->next;

        // 交换节点
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // 更新指针
        prev = first;
        head = first->next;
    }

    return dummy.next;
}
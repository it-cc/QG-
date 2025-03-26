#include "ListNode.h"

ListNode* ListNode::reverseList_recursion(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	ListNode* last = reverseList_recursion(head->next);
	head->next->next = head;
	head->next = nullptr;
	return last;
}
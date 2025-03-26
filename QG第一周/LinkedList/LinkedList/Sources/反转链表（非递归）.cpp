#include "ListNode.h"

ListNode* ListNode::reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		cout << "链表的结点少于两个，无法反转" << endl;
		return head;
	}

	ListNode* prev = nullptr, * curr = head, * next = head->next;
	while (curr != nullptr)
	{
		curr->next = prev;//反转结点
		//指针后移
		prev = curr;
		curr = next;
		if (next != nullptr)
		{
			next = next->next;
		}
	}
	return prev;
}
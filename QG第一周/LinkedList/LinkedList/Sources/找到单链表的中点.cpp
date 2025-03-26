#include "ListNode.h"
ListNode* ListNode::MidNode(ListNode* head)
{
	if (head == nullptr) return head;
	//¿ìÂýÖ¸Õë
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
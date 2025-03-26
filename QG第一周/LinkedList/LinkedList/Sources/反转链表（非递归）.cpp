#include "ListNode.h"

ListNode* ListNode::reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		cout << "����Ľ�������������޷���ת" << endl;
		return head;
	}

	ListNode* prev = nullptr, * curr = head, * next = head->next;
	while (curr != nullptr)
	{
		curr->next = prev;//��ת���
		//ָ�����
		prev = curr;
		curr = next;
		if (next != nullptr)
		{
			next = next->next;
		}
	}
	return prev;
}
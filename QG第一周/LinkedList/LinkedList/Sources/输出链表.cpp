#include "ListNode.h"

void ListNode::for_each(ListNode* head)
{
	if (head==nullptr)
	{
		cout << "链表为空，无法输出" << endl;
	}

	cout << "链表的结构为：";
	while (head != nullptr)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL";
	cout << endl;
}
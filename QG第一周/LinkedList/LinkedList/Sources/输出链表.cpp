#include "ListNode.h"

void ListNode::for_each(ListNode* head)
{
	if (head==nullptr)
	{
		cout << "����Ϊ�գ��޷����" << endl;
	}

	cout << "����ĽṹΪ��";
	while (head != nullptr)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL";
	cout << endl;
}
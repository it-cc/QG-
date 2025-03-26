#include "ListNode.h"
bool ListNode::hasCycle(ListNode* head)
{
	//�������ָ��
	ListNode *slow = head, *fast = head;
	while (fast!=nullptr && fast->next != nullptr)
	{
		//slow��һ����fast������
		slow = slow->next;
		fast = fast->next->next;
		//���slow==fast��˵������ɻ�
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
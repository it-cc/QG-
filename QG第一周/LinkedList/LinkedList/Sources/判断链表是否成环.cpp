#include "ListNode.h"
bool ListNode::hasCycle(ListNode* head)
{
	//定义快慢指针
	ListNode *slow = head, *fast = head;
	while (fast!=nullptr && fast->next != nullptr)
	{
		//slow走一步，fast走两步
		slow = slow->next;
		fast = fast->next->next;
		//如果slow==fast，说明链表成环
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
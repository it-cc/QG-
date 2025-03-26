#include "ListNode.h"

void ListNode::deleteNode(ListNode*& head)
{
    if (head == nullptr) return;

    cout << "������Ҫɾ��������: ";
    int givenNum;
    // ���������
    while (!(cin >> givenNum)) {
        cout << "������Ч��������һ������: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // ����Ҫɾ���Ľڵ���ͷ�ڵ�����
    if (head->val == givenNum) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        cout << "ɾ���ɹ�" << endl;
        return;
    }

    ListNode* pPrev = head;
    ListNode* pCurrent = pPrev->next;
    // ����Ҳ���ָ�������֣�pCurrent ���ƶ��� nullptr
    while (pCurrent != nullptr) {
        // �ҵ���ָ������
        if (pCurrent->val == givenNum) 
        {
            pPrev->next = pCurrent->next;
            delete pCurrent;
            cout << "ɾ���ɹ�" << endl;
            return;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
    cout << "ɾ��ʧ�ܣ�û���������" << endl;
}
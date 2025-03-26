#include <iostream>
using namespace std;
#include "ListNode.h"

int main()
{
    ListNode l;
    ListNode* head = nullptr;

    while (1)
    {
        menu();
        cout << "����������ѡ��:" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            head = l.creatList();
            break;
        case 2:
            if (head) 
            {
                l.for_each(head);
                l.insertNode(head);
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 3:
            if (head) 
            {
                int option;
                cout << "1��������ת    2���ݹ鷴ת" << endl;
                cin >> option;
               
                switch (option)
                {
                case 1:
                    head = l.reverseList(head);
                    break;
                case 2:
                    head = l.reverseList_recursion(head);
                    break;
                default:
                    cout << "��Ч��ѡ��" << endl;
                    break;
                }
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 4:
            if (head) 
            {
                l.for_each(head);
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 5:
            if (head) 
            {
                l.for_each(head);
                l.deleteNode(head);
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 6:
            if (head) 
            {
                ListNode* midNode = l.MidNode(head);
                if (midNode) 
                {
                    cout << "�м����ֵΪ��" << midNode->val << endl;
                }
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 7:
            if (head) 
            {
                int x = l.hasCycle(head);
                if (x == 1)
                {
                    cout << "����ɻ�" << endl;
                }
                else
                {
                    cout << "�����ɻ�" << endl;
                }
            }
            else    
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 8:
            if (head) 
            {
                head = l.exchangeNode(head);
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 9:
            if (head) 
            {
                l.searchNode(head);
            }
            else 
            {
                cout << "���ȴ�������" << endl;
            }
            break;
        case 10:
            break;
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }

        if (choice == 10) 
        {
            break;
        }
        system("pause");
        system("cls");
        
    }
    return 0;
}
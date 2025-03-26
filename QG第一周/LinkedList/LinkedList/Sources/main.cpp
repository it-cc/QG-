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
        cout << "请输入您的选择:" << endl;
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
                cout << "请先创建链表。" << endl;
            }
            break;
        case 3:
            if (head) 
            {
                int option;
                cout << "1：迭代反转    2：递归反转" << endl;
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
                    cout << "无效的选择" << endl;
                    break;
                }
            }
            else 
            {
                cout << "请先创建链表。" << endl;
            }
            break;
        case 4:
            if (head) 
            {
                l.for_each(head);
            }
            else 
            {
                cout << "请先创建链表。" << endl;
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
                cout << "请先创建链表。" << endl;
            }
            break;
        case 6:
            if (head) 
            {
                ListNode* midNode = l.MidNode(head);
                if (midNode) 
                {
                    cout << "中间结点的值为：" << midNode->val << endl;
                }
            }
            else 
            {
                cout << "请先创建链表。" << endl;
            }
            break;
        case 7:
            if (head) 
            {
                int x = l.hasCycle(head);
                if (x == 1)
                {
                    cout << "链表成环" << endl;
                }
                else
                {
                    cout << "链表不成环" << endl;
                }
            }
            else    
            {
                cout << "请先创建链表。" << endl;
            }
            break;
        case 8:
            if (head) 
            {
                head = l.exchangeNode(head);
            }
            else 
            {
                cout << "请先创建链表。" << endl;
            }
            break;
        case 9:
            if (head) 
            {
                l.searchNode(head);
            }
            else 
            {
                cout << "请先创建链表。" << endl;
            }
            break;
        case 10:
            break;
        default:
            cout << "无效的选择，请重新输入。" << endl;
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
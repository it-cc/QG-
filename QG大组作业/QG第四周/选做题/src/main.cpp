#include <iostream>
#include "PriorityQueue.h"
#include "Menu.h"
#include "AVLTree.h"
#include "RBTree.h"

using namespace std;

int main()
{
     Menu::menu3();
     cout << "请输入你的选择：";
     int option;
     cin >> option;
     int capacity;
     switch (option)
     {
          case 1:
          {
               cout << "请输入堆的大小:";
               cin >> capacity;
               MyPriorityQueue<int> minHeap(capacity, [](const int& a, const int& b) { return a > b; });
               cout<<"创建成功！"<<endl;
               handleHeapOperations(minHeap);
               break;
          }
          case 2:
          {
               cout << "请输入堆的大小:";
               cin >> capacity;
               MyPriorityQueue<int> maxHeap(capacity, [](const int& a, const int& b) { return a < b; });
               cout<<"创建成功！"<<endl;
               handleHeapOperations(maxHeap);
               break;
          }
          case 3:
          {
               AVLTree tree;
               system("pause");
               system("cls");
               int choice, value;
               while (true)
               {
                    Menu::menu1();
                    cin>>choice;
                    switch (choice)
                    {
                         case 1:
                              cout << "请输入要插入的值：";
                              cin>>value;
                              tree.insert(value);
                              cout<<"插入成功！"<<endl;
                              break;
                         case 2:
                              cout<<"请输入要删除的值：";
                              cin>>value;
                              tree.deleteKey(value);
                         break;
                         case 3:
                              tree.inorderTraversal();
                         break;
                         case 4:
                              // 退出系统
                              cout << "欢迎下次使用！" << endl;
                              system("pause");
                              return 0;
                         default:
                              cerr << "请重新选择！" << endl;
                    }
                    system("pause");
                    system("cls");
               }
          }
          case 4:
          {
               RBTree RBT;
               system("pause");
               system("cls");
               int choice, value;
               while (true)
               {
                    Menu::menu2();
                    cin>>choice;
                    switch (choice)
                    {
                         case 1:
                              cout << "请输入要插入的值：";
                              cin>>value;
                              RBT.insert(value);
                              cout<<"插入成功！"<<endl;
                              break;
                         case 2:
                         {
                              cout<<"请输入要删除的值：";
                              cin>>value;
                              RBNode* result = RBT.search(value);
                              if (result != RBT.NIL)
                              {
                                   std::cout << "找到节点: " << result->key << std::endl;
                              }
                              else
                              {
                                   std::cout << "未找到节点" << std::endl;
                              }
                              break;
                         }
                         case 3:
                              RBT.inorderTraversal();
                         break;
                         case 4:
                              // 退出系统
                              cout << "欢迎下次使用！" << endl;
                              system("pause");
                              return 0;
                         default:
                              cerr << "请重新选择！" << endl;
                    }
                    system("pause");
                    system("cls");
               }
          }
          default:
               cerr << "请重新选择！" << endl;
     }
     return 0;

}


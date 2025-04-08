#include "BST.h"
#include "Menu.h"

using namespace std;

int main()
{
     BST bst;
     while(true)
     {
          Menu::menu();
          cout<<"请输入你的选择：";
          int option;
          cin>>option;
          int value;
          TreeNode* node;
          switch(option)
          {
               case 1:
                    cout<<"请输入要插入的值：";
                    cin>>value;
                    bst.insert(value);
                    break;
               case 2:
                    cout<<"请输入要删除的值：";
                    cin>>value;
                    bst.deleteNode(value);
                    break;
               case 3:
                    cout<<"请输入要查找的值：";
                    cin>>value;
                    node=bst.search(value);
                    if (node)  cout<<"存在该结点！"<<endl;
                    else  cout<<"不存在该结点!"<<endl;
                    break;
               case 4:
                    cout<<endl<<"1、递归   2、非递归"<<endl;
                    cout<<"请选择遍历方式：";
                    cin>>value;
                    if (value == 1)  bst.preOrder();
                    else if (value == 2)  bst.preOrderNonRecursive();
                    cout<<endl;
                    break;
               case 5:
                    cout<<endl<<"1、递归   2、非递归"<<endl;
                    cout<<"请选择遍历方式：";
                    cin>>value;
                    if (value == 1)  bst.inOrder();
                    else if (value == 2)  bst.inOrderNonRecursive();
                    cout<<endl;
                    break;
               case 6:
                    cout<<endl<<"1、递归   2、非递归"<<endl;
                    cout<<"请选择遍历方式：";
                    cin>>value;
                    if (value == 1)  bst.postOrder();
                    else if (value == 2)  bst.postOrderNonRecursive();
                    cout<<endl;
                    break;
               case 7:
                    bst.levelOrder();
                    cout<<endl;
                    break;
               case 8:
                    //退出系统
                    cout<<"欢迎下次使用！"<<endl;
                    system("pause");
                    return 0;
          }
          system("pause");
          system("cls");
     }
     return 0;
}
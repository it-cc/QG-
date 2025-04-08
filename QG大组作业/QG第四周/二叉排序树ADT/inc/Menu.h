//
// Created by k on 25-4-6.
//

#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;


class Menu
{
public:
     static void menu()
     {
          cout << "**********************************************************************" << endl;
          cout << "*        1、插入结点        *  --------- *        2、删除结点        *" << endl;
          cout << "*        3、查找结点        *            *        4、前序遍历        *" << endl;
          cout << "*        5、中序遍历        *            *        6、后序遍历        *" << endl;
          cout << "*        7、层序遍历        *  --------- *        8、退出系统        *" << endl;
          cout << "**********************************************************************" << endl;
     }
};



#endif //MENU_H

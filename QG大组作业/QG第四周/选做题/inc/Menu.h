//
// Created by k on 25-4-7.
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
          cout << "*        1、插入元素        * 5、退出系统 *        2、弹出元素       *" << endl;
          cout << "*        3、查看堆顶        *  ---------  *        4、查看元素数量   *" << endl;
          cout << "**********************************************************************" << endl;
     }
     static void menu1()
     {
          cout << "**********************************************************************" << endl;
          cout << "*        1、插入元素        *  ---------  *        2、删除元素       *" << endl;
          cout << "*        3、遍历元素        *  ---------  *        4、退出系统       *" << endl;
          cout << "**********************************************************************" << endl;
     }
     static void menu2()
     {
          cout << "**********************************************************************" << endl;
          cout << "*        1、插入元素        *  ---------  *        2、查找元素       *" << endl;
          cout << "*        3、遍历元素        *  ---------  *        4、退出系统       *" << endl;
          cout << "**********************************************************************" << endl;
     }
     static void menu3()
     {
          cout << "*************************************************************************" << endl;
          cout << "*        1、创建小顶堆       *  --------- *        2、创建大顶堆        *" << endl;
          cout << "*        3、创建AVL树        *  --------- *        4、创建红黑树        *" << endl;
          cout << "*************************************************************************" << endl;
     }
};



#endif //MENU_H

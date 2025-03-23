#include "MyLinkedStack.hpp"
void Menu()
{
    cout << "*********************************************" << endl;
    cout << "********** 1、  向栈顶加入元素     **********" << endl;
    cout << "********** 2、  从栈顶弹出元素     **********" << endl;
    cout << "********** 3、  查看栈顶元素       **********" << endl;
    cout << "********** 4、  查看栈中的元素个数 **********" << endl;
    cout << "********** 5、     清空栈          **********" << endl;
    cout << "********** 6、    退出系统         **********" << endl;
    cout << "*********************************************" << endl;
}

int main() 
{
    MyLinkedStack<int> stack;
    int choice=0;
    while (1)
    {
        Menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "请输入向栈顶加入的元素：" ;
            int val;
            cin >> val;
            stack.push(val);
            break;
        case 2:
            try 
            {
                int popped = stack.pop();
                cout << "弹出的元素为: " << popped << endl;
            }
            catch (const out_of_range& e) 
            {
               cerr << "捕获到异常: " << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                int val = stack.peek();
                cout << "栈顶的元素为：" << val << endl;
            }
            catch (const out_of_range& e)
            {
                cerr << "捕获到异常: " << e.what() << endl;
            }
            break;
        case 4:
            cout << "栈中的元素个数为：" << stack.size()<< endl;
            break;
        case 5:
            stack.clearStack();
            cout << "栈已清空！" << endl;
            break;
        case 6:
            cout << "欢迎下次使用。" << endl;
            return 0;
        default:
            cout << "请重新选择！" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
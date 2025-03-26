#include "MyLinkedQueue.hpp"
void Menu()
{
    cout << "*********************************************" << endl;
    cout << "********** 1、  向队列加入元素     **********" << endl;
    cout << "********** 2、  从队列弹出元素     **********" << endl;
    cout << "********** 3、  查看队列元素       **********" << endl;
    cout << "********** 4、  查看队列的元素个数 **********" << endl;
    cout << "********** 5、     清空队列        **********" << endl;
    cout << "********** 6、     退出系统        **********" << endl;
    cout << "*********************************************" << endl;
}

int main()
{
    MyLinkedQueue<int> queue;
    int choice = 0;
    while (1)
    {
        Menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "请输入向队列加入的元素：";
            int val;
            cin >> val;
            queue.push(val);
            break;
        case 2:
            try
            {
                const int popped = queue.pop();
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
                const int value = queue.top();
                cout << "队头的元素为：" << value << endl;
            }
            catch (const out_of_range& e)
            {
                cerr << "捕获到异常: " << e.what() << endl;
            }
            break;
        case 4:
            cout << "队列中的元素个数为：" << queue.size() << endl;
            break;
        case 5:
            queue.clear();
            cout << "队列已清空！" << endl;
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


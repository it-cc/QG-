#include "MyLinkedStack.hpp"
void Menu()
{
    cout << "*********************************************" << endl;
    cout << "********** 1��  ��ջ������Ԫ��     **********" << endl;
    cout << "********** 2��  ��ջ������Ԫ��     **********" << endl;
    cout << "********** 3��  �鿴ջ��Ԫ��       **********" << endl;
    cout << "********** 4��  �鿴ջ�е�Ԫ�ظ��� **********" << endl;
    cout << "********** 5��     ���ջ          **********" << endl;
    cout << "********** 6��    �˳�ϵͳ         **********" << endl;
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
            cout << "��������ջ�������Ԫ�أ�" ;
            int val;
            cin >> val;
            stack.push(val);
            break;
        case 2:
            try 
            {
                int popped = stack.pop();
                cout << "������Ԫ��Ϊ: " << popped << endl;
            }
            catch (const out_of_range& e) 
            {
               cerr << "�����쳣: " << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                int val = stack.peek();
                cout << "ջ����Ԫ��Ϊ��" << val << endl;
            }
            catch (const out_of_range& e)
            {
                cerr << "�����쳣: " << e.what() << endl;
            }
            break;
        case 4:
            cout << "ջ�е�Ԫ�ظ���Ϊ��" << stack.size()<< endl;
            break;
        case 5:
            stack.clearStack();
            cout << "ջ����գ�" << endl;
            break;
        case 6:
            cout << "��ӭ�´�ʹ�á�" << endl;
            return 0;
        default:
            cout << "������ѡ��" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
#include "MyLinkedQueue.hpp"
void Menu()
{
    cout << "*********************************************" << endl;
    cout << "********** 1��  ����м���Ԫ��     **********" << endl;
    cout << "********** 2��  �Ӷ��е���Ԫ��     **********" << endl;
    cout << "********** 3��  �鿴����Ԫ��       **********" << endl;
    cout << "********** 4��  �鿴���е�Ԫ�ظ��� **********" << endl;
    cout << "********** 5��     ��ն���        **********" << endl;
    cout << "********** 6��     �˳�ϵͳ        **********" << endl;
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
            cout << "����������м����Ԫ�أ�";
            int val;
            cin >> val;
            queue.push(val);
            break;
        case 2:
            try
            {
                const int popped = queue.pop();
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
                const int value = queue.top();
                cout << "��ͷ��Ԫ��Ϊ��" << value << endl;
            }
            catch (const out_of_range& e)
            {
                cerr << "�����쳣: " << e.what() << endl;
            }
            break;
        case 4:
            cout << "�����е�Ԫ�ظ���Ϊ��" << queue.size() << endl;
            break;
        case 5:
            queue.clear();
            cout << "��������գ�" << endl;
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


#include "Calculation.h"
int main()
{
    Calculation c;
    int choice=1;
    while (choice)
    {
        cout << "����������������ʽ(���ܼ�����ź�С��)��";
        string input;
        cin >> input;
        cout << "�������׺���ʽΪ: " << input << endl;

        string output = c.transform(input);
        cout << "ת����ĺ�׺���ʽΪ: " << output << endl;

        const int result = c.calculate(output);
        cout << "������Ϊ��" << result << endl;

        cout << "�Ƿ�������㣿1����  0����" << endl;
        cin >> choice;

        system("pause");
        system("cls");
    }
    return 0;
}
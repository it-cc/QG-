#include "Calculation.h"
int main()
{
    Calculation c;
    int choice=1;
    while (choice)
    {
        cout << "请输入四则运算表达式(不能计算根号和小数)：";
        string input;
        cin >> input;
        cout << "输入的中缀表达式为: " << input << endl;

        string output = c.transform(input);
        cout << "转换后的后缀表达式为: " << output << endl;

        const int result = c.calculate(output);
        cout << "计算结果为：" << result << endl;

        cout << "是否继续计算？1：是  0：否" << endl;
        cin >> choice;

        system("pause");
        system("cls");
    }
    return 0;
}
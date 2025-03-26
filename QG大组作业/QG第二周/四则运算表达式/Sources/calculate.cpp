#include "Calculation.h"
int Calculation::calculate(string& output)
{
    stack<int> expression;

    /* 1.从左到右遍历后缀表达式的每一个数字和符号
       2.若是数字，则进栈
       3.若是符号，则把处于栈顶的两个数字出栈，进行运算
       4.运算结果进栈
       5.直到获得最终结果*/
    for (string::iterator it = output.begin(); it != output.end(); it++)
    {
        if (isdigit(*it))
        {
            expression.push(*it - '0'); // 将字符转换为整数
        }
        else
        {
            if (expression.size() < 2)
            {
                cerr << "后缀表达式格式错误!" << endl;
                return 0;
            }
            int a = expression.top();
            expression.pop();
            int b = expression.top();
            expression.pop();
            if (*it == '+') expression.push(b + a);
            else if (*it == '-') expression.push(b - a);
            else if (*it == '*') expression.push(b * a);
            else if (*it == '/')
            {
                if (a == 0)
                {
                    cerr << "除数不能为零!" << endl;
                    return 0;
                }
                expression.push(b / a);
            }
        }
    }
    if (expression.size() != 1)
    {
        cerr << "后缀表达式格式错误!" << endl;
        return 0;
    }
    return expression.top();
}
#include "Calculation.h"
string Calculation::transform(string& input)
{
    stack<char> expression;
    string output;
    for (string::iterator it = input.begin(); it != input.end(); it++)
    {
        // 运算数: 直接输出
        if (isdigit(*it))
        {
            output.push_back(*it);
        }
        // 左括号: 压入堆栈
        else if (*it == '(')
        {
            expression.push(*it);
        }
        // 右括号: 将栈顶的运算符弹出并输出，直到遇到左括号(出栈，不输出)
        else if (*it == ')')
        {
            while (!expression.empty() && expression.top() != '(')
            {
                output.push_back(expression.top());
                expression.pop();
            }
            // 左括号出栈，不输出
            if (!expression.empty() && expression.top() == '(')
            {
                expression.pop();
            }
        }
        /*
        运算符
        若优先级大于栈顶运算符时，则把它压栈;
        若优先级小于等于栈顶运算符时，将栈顶运算符弹出并输出;
        再比较新的栈顶运算符，直到该运算符大于栈顶运算符优先级为止，然后将该运算符压栈;
        */
        else
        {
            while (!expression.empty() && getPriority(*it) <= getPriority(expression.top()))
            {
                output.push_back(expression.top());
                expression.pop();
            }
            expression.push(*it);
        }
    }
    // 若各对象处理完毕，则把堆栈中存留的运算符一并输出
    while (!expression.empty())
    {
        output.push_back(expression.top());
        expression.pop();
    }
    return output;
}
#include "Calculation.h"
int Calculation::calculate(string& output)
{
    stack<int> expression;

    /* 1.�����ұ�����׺���ʽ��ÿһ�����ֺͷ���
       2.�������֣����ջ
       3.���Ƿ��ţ���Ѵ���ջ�����������ֳ�ջ����������
       4.��������ջ
       5.ֱ��������ս��*/
    for (string::iterator it = output.begin(); it != output.end(); it++)
    {
        if (isdigit(*it))
        {
            expression.push(*it - '0'); // ���ַ�ת��Ϊ����
        }
        else
        {
            if (expression.size() < 2)
            {
                cerr << "��׺���ʽ��ʽ����!" << endl;
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
                    cerr << "��������Ϊ��!" << endl;
                    return 0;
                }
                expression.push(b / a);
            }
        }
    }
    if (expression.size() != 1)
    {
        cerr << "��׺���ʽ��ʽ����!" << endl;
        return 0;
    }
    return expression.top();
}
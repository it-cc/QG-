#include "Calculation.h"
string Calculation::transform(string& input)
{
    stack<char> expression;
    string output;
    for (string::iterator it = input.begin(); it != input.end(); it++)
    {
        // ������: ֱ�����
        if (isdigit(*it))
        {
            output.push_back(*it);
        }
        // ������: ѹ���ջ
        else if (*it == '(')
        {
            expression.push(*it);
        }
        // ������: ��ջ��������������������ֱ������������(��ջ�������)
        else if (*it == ')')
        {
            while (!expression.empty() && expression.top() != '(')
            {
                output.push_back(expression.top());
                expression.pop();
            }
            // �����ų�ջ�������
            if (!expression.empty() && expression.top() == '(')
            {
                expression.pop();
            }
        }
        /*
        �����
        �����ȼ�����ջ�������ʱ�������ѹջ;
        �����ȼ�С�ڵ���ջ�������ʱ����ջ����������������;
        �ٱȽ��µ�ջ���������ֱ�������������ջ����������ȼ�Ϊֹ��Ȼ�󽫸������ѹջ;
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
    // ������������ϣ���Ѷ�ջ�д����������һ�����
    while (!expression.empty())
    {
        output.push_back(expression.top());
        expression.pop();
    }
    return output;
}
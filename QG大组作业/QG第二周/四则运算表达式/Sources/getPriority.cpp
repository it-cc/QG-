#include "Calculation.h"
int Calculation::getPriority(const char& op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // 括号优先级最低
}
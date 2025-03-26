#pragma once
#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Calculation
{
public:
	int getPriority(const char& op);
	string transform(string& input);
	int calculate(string& output);
};
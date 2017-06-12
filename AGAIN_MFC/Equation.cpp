#include"stdafx.h"
#include"Random.h"
#include"Equation.h"
#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<stack>
using namespace std;
class Rand rand_; //创建一个Random对象
stack<double> numstack;//数字栈
stack<char> opstack;//符号栈

void Equation::creat()
{
	number[0] = rand_.randomNumber(); //数字
	number[1] = rand_.randomNumber();
	number[2] = rand_.randomNumber();
	number[3] = rand_.randomNumber();
	sign[1] = '+';
	sign[2] = '-';
	sign[3] = '*';
	sign[4] = '/';
	sign_1 = rand_.randOperation();//符号
	sign_2 = rand_.randOperation();
	sign_3 = rand_.randOperation();
	bracket = rand_.randombracket();//括号
}

void Equation::gengerateExpression()
{
	creat();
	stringstream ss;
	if (bracket == 1)
		ss << "(" << number[0] << sign[sign_1] << number[1] << ")" << sign[sign_2] << number[2] << sign[sign_3] << number[3]<<"=";
	if (bracket == 2)
		ss << number[0] << sign[sign_1] << "(" << number[1] << sign[sign_2] << number[2] << ")" << sign[sign_3] << number[3]<<"=";
	if (bracket == 3)
		ss << number[0] << sign[sign_1] << number[1] << sign[sign_2] << "(" << number[2] << sign[sign_3] << number[3] << ")" <<"=";
	if (bracket == 4)
		ss << "(" << number[0] << sign[sign_1] << number[1] << sign[sign_2] << number[2] << ")" << sign[sign_3] << number[3]<<"=" ;
	if (bracket == 5)
		ss << number[0] << sign[sign_1] << "(" << number[1] << sign[sign_2] << number[2] << sign[sign_3] << number[3] << ")" <<"=";
	if (bracket == 6)
		ss << "(" << number[0] << sign[sign_1] << number[1] << ")" << sign[sign_2] << "(" << number[2] << sign[sign_3] << number[3] << ")"<<"=";
	string str = ss.str();
	ss.str(" ");
	S = str;
	calculatResult();
}

int Equation::compare(char x)
{
	switch (x)
	{
	case '*':
	case '/': return 3;
	case '-':
	case '+': return 2;
	case '(': return 1;
	case ')': return -2;
	default:return -1;
	}
}
void Equation::calculatResult()
{
	double num_ = 0;
	for (unsigned int i = 0; i < S.size(); i++)
	{
		if (S[i] >= '0'&&S[i] <= '9')
		{
			num_ = num_ * 10 + S[i] - '0';
			if (i == S.size() - 1)
				numstack.push(num_);
		}
		else
		{
			if (num_)
			{
				numstack.push(num_);
				num_ = 0;
			}
			if (opstack.empty())
				opstack.push(S[i]);
			else if (S[i] == '(')
				opstack.push(S[i]);
			else if (S[i] == ')')
			{
				while (opstack.top() != '(')
					calculate();
				opstack.pop();
			}
			else if (compare(S[i]) > compare(opstack.top()))  //比较优先级函数
				opstack.push(S[i]);
			else if (compare(S[i]) <= compare(opstack.top()))
			{
				calculate();  //运算函数
				opstack.push(S[i]);
			}
			else if (S[i] == '=')
				break;
		}
	}
	while (!opstack.top())
		calculate();
	double result = numstack.top();
	if ((result - (int)result) >= 0.5)
		result = result + 1;
	Result = result;
}

void Equation::calculate()
{
	char p = opstack.top();
	double a, b, result;
	b = numstack.top();
	numstack.pop();
	a = numstack.top();
	numstack.pop();
	switch (p)
	{
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a*b; break;
	case '/':result = a / b; break;
	default: break;
	}
	numstack.push(result);
	opstack.pop();
}

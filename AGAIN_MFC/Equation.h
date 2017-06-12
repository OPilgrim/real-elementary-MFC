#pragma once
#ifndef EQUATION_H
#define EQUATION_H
#include<iostream>
using namespace std;
class Equation
{
private:
	char sign[5];
	int sign_1, sign_2, sign_3;
	int number[4];
	int bracket;
	void calculate();
	int compare(char x);
	string S;
	int Result;
	void creat();
	void calculatResult();
public:
	void gengerateExpression();
	string get_()
	{
		return S;
	}
	int get()
	{
		return Result;
	}
};
#endif // !EQUATION_H

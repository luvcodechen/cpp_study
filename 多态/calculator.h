#pragma once

#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
	int getResult(char oper)
	{
		switch (oper)
		{
		case '+': return num1 + num2;
			break;
		case '-': return num1 - num2;
			break;
		case '*': return num1 * num2;
			break;
		case '/': return num1 / num2;
			break;
		}
	}

	Calculator(int num1, int num2)
		: num1(num1),
		num2(num2)
	{
	}

	int num1;
	int num2;
};


class abstravctCalculator_
{
public:
	int num1;
	int num2;

	abstravctCalculator_(int num1, int num2)
		: num1(num1),
		num2(num2)
	{
	}

	virtual int getResult()
	{
		return 0;
	}
};


class addClass : public abstravctCalculator_
{
public:
	int getResult() override
	{
		return num1 + num2;
	}

	addClass(int num1, int num2)
		: abstravctCalculator_(num1, num2)
	{
	}
};

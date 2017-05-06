#pragma once
#include <string>
#include <exception>
using namespace std;

//	简单工厂模式（simple factory）：
//	根据不同的条件实例不同的对象
//

class Operation
{
public:
	virtual void Set(double num1, double num2)
	{
		num1_ = num1;
		num2_ = num2;
	}
	virtual double GetResult() = 0;


	double num1_;
	double num2_;
};


class AddOperation : public Operation
{
public:
	double GetResult()
	{
		double result = num1_ + num2_;
		return result;
	}
};


class SubOperation : public Operation
{
public:
	double GetResult()
	{
		double result = num1_ - num2_;
		return result;
	}
};


class MultiOperation : public Operation
{
public:
	double GetResult()
	{
		double result = num1_ * num2_;
		return result;
	}
};


class DivOperation : public Operation
{
public:
	double GetResult()
	{
		if (num2_ < 0.000001 && num2_ > -0.000001)
		{
			throw "div by zero";
		}
		double result = num1_ / num2_;
		return result;
	}
};

class SimpleFactory
{
public:
	Operation* CreateOperation(string oper)
	{
		operation_ = NULL;
		if (oper == "+")
		{
			operation_ = new AddOperation();
		}
		else if (oper == "-")
		{
			operation_ = new SubOperation();
		}
		else if (oper == "*")
		{
			operation_ = new MultiOperation();
		}
		else if (oper == "/")
		{
			operation_ = new DivOperation();
		}
		return operation_;
	}

	void DeleteOperation()
	{
		if (operation_)
			delete operation_;
	}

private:
	Operation* operation_;
};
#pragma once
#include <exception>


class Operation
{
public:
	virtual void Set(double num1, double num2)
	{
		num1_ = num1;
		num2_ = num2;
	}
	virtual double GetResult() { return 0; }


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
		if (num2_ < 1e-6 && num2_ > -1e-6) throw "div by zero";
		double result = num1_ / num2_;
		return result;
	}
};
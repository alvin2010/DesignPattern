#pragma once
#include <string>
using namespace std;
#include "operation.h"


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
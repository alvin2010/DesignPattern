#ifndef COMPOSITE_H_
#define COMPOSITE_H_
#include <cstdio>
#include <list>
#include <string>
using namespace std;
//	组合模式（composite）： 将对象组合成树形结构表示
//	使单个对象和组合对象的使用具有一致性
//


class Company
{
public:
	virtual void Add(){}
	virtual void Remove(){}
	virtual void Display(){}
	virtual void OnDuty() {}
};


class ConcreteCompany : public Company
{
private:
	string name_;
	list<Company*> companies_;
public:
	ConcreteCompany(string name)
	{
		name_ = name;
	}

	void Add(ConcreteCompany com)
	{
		companies_.push_back(&com);
	}

	void Remove(ConcreteCompany com)
	{
		companies_.remove(&com);
	}

	void Display()
	{
		printf_s("company %s\n", name_.c_str());
		for (list<Company*>::iterator it = companies_.begin(); companies_.end() != it; it++)
		{
			(*it)->Display();
		}
	}

	void OnDuty()
	{
		for (list<Company*>::iterator it = companies_.begin(); companies_.end() != it; it++)
		{
			(*it)->OnDuty();
		}
	}

};


class HRDepartment : public Company
{
private:
	string name_;
public:
	HRDepartment(string name)
	{
		name_ = name;
	}

	void Display()
	{
		printf_s("department %s\n", name_.c_str());
	}

	void OnDuty()
	{
		printf_s("Hr Duty is Hr\n");
	}

};


class FinanceDepartment : public Company
{
private:
	string name_;
public:
	FinanceDepartment(string name)
	{
		name_ = name;
	}

	void Display()
	{
		printf_s("department %s\n", name_.c_str());
	}

	void OnDuty()
	{
		printf_s("Finance Duty is Finance\n");
	}
};





#endif
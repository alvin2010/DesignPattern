#ifndef VISITOR_H_
#define VISITOR_H_
#include <cstdio>
//
//
//


class Action
{
public:
	virtual	void GetManConclusion() = 0;
	virtual void GetWomanConclusion() = 0;
};

class Success : public Action
{
public:
	void GetManConclusion()
	{
		printf_s("男人成功，背后有一个伟大的女人！\n");
	}

	void GetWomanConclusion()
	{
		printf_s("女人成功，背后有一个伟大的男人！\n");
	}
};


class Failure : public Action
{
public:
	void GetManConclusion()
	{
		printf_s("男人失败找原因！\n");
	}

	void GetWomanConclusion()
	{
		printf_s("女人失败找借口！\n");
	}
};

class Person1
{
public:
	virtual void Accept(Action* action) = 0;
};


class Man : public Person1
{
public:
	void Accept(Action* action)
	{
		action->GetManConclusion();
	}
};

class Woman : public Person1
{
public:
	void Accept(Action* action)
	{
		action->GetWomanConclusion();
	}
};


#endif
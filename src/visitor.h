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
		printf("���˳ɹ���������һ��ΰ����Ů�ˣ�\n");
	}

	void GetWomanConclusion()
	{
		printf("Ů�˳ɹ���������һ��ΰ�������ˣ�\n");
	}
};


class Failure : public Action
{
public:
	void GetManConclusion()
	{
		printf("����ʧ����ԭ����\n");
	}

	void GetWomanConclusion()
	{
		printf("Ů��ʧ���ҽ��ڣ�\n");
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
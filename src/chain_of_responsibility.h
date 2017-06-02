#ifndef CHAIN_OF_RESPONSIBILITY_H_
#define CHAIN_OF_RESPONSIBILITY_H_
#include <cstdio>

//	职责链模式（）：使多个对象都有机会处理请求
//	将这些对象连着一个链，沿着这个链传递请求
//


enum Request_Type
{
	AddSalary = 0,
	AskForLeave
};

class Request
{
private:
	int num_;
	int type_;
public:
	void SetNum(int num)
	{
		num_ = num;
	}


	int GetNum()
	{
		return num_;
	}

	void SetType(int type)
	{
		type_ = type;
	}

	int GetType()
	{
		return type_;
	}

};

class Manager
{
protected:
	Manager* super_;
public:
	void SetSuper(Manager* super)
	{
		super_ = super;
	}
	virtual void Handle(Request request) = 0;
};


class CommonManager :public Manager
{
public:
	void Handle(Request request)
	{
		if (request.GetType() == AskForLeave && request.GetNum() <= 2)
		{
			printf("请假小于两天，CommonManager批了\n");
		}
		else
		{
			if (super_ != NULL)
			{
				printf("超过职权，交由MajorManager处理\n");
				super_->Handle(request);
			}
		}
	}
};


class MajorManager : public Manager
{
public:
	void Handle(Request request)
	{
		if (request.GetType() == AskForLeave && request.GetNum() > 2 || request.GetType() == AddSalary && request.GetNum() <= 500 )
		{
			if (request.GetType() == AskForLeave)
			{
				printf("请假大于两天，MajorManager批了\n");
			}
			else
			{
				printf("加薪小于500，MajorManager批了\n");
			}
		}
		else
		{
			if (super_ != NULL)
			{
				printf("超过职权，交由GeneralManager处理\n");
				super_->Handle(request);
			}
		}
	}
};


class GeneralManager : public Manager
{
public:
	void Handle(Request request)
	{
		if (request.GetType() == AddSalary && request.GetNum() > 500)
		{
			printf("加薪超过500，GeneralManager批了\n");
		}
		else
		{
		}
	}
};


#endif

#ifndef CHAIN_OF_RESPONSIBILITY_H_
#define CHAIN_OF_RESPONSIBILITY_H_
#include <cstdio>

//	职责链模式（chain of responsibility）：
//
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
		if (request.GetType() == Request_Type::AskForLeave && request.GetNum() <= 2)
		{
			printf_s("请假两天，项目经理批准啦！\n");
		}
		else
		{
			if (super_ != NULL)
			{
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
		if (request.GetType() == Request_Type::AskForLeave && request.GetNum() > 2 || request.GetType() == Request_Type::AddSalary && request.GetNum() <= 500 )
		{
			if (request.GetType() == Request_Type::AskForLeave)
			{
				printf_s("请假超过两天天，总监批准啦！\n");
			}
			else
			{
				printf_s("加薪小于500，项目经理批准啦！\n");
			}
		}
		else
		{
			if (super_ != NULL)
			{
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
		if (request.GetType() == Request_Type::AddSalary && request.GetNum() > 500)
		{
			printf_s("加薪超过500，总经理没批准/(ㄒoㄒ)/~~！\n");
		}
		else
		{
		}
	}
};


#endif
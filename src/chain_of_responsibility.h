#ifndef CHAIN_OF_RESPONSIBILITY_H_
#define CHAIN_OF_RESPONSIBILITY_H_
#include <cstdio>

//	ְ����ģʽ������ʹ��������л��ᴦ������
//	����Щ��������һ�����������������������
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
			printf("���С�����죬CommonManager����\n");
		}
		else
		{
			if (super_ != NULL)
			{
				printf("����ְȨ������MajorManager����\n");
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
				printf("��ٴ������죬MajorManager����\n");
			}
			else
			{
				printf("��нС��500��MajorManager����\n");
			}
		}
		else
		{
			if (super_ != NULL)
			{
				printf("����ְȨ������GeneralManager����\n");
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
			printf("��н����500��GeneralManager����\n");
		}
		else
		{
		}
	}
};


#endif

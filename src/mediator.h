#ifndef MEDIATOR_H_
#define MEDIATOR_H_
#include <cstdio>
#include <string>
using namespace std;


//	中介者模式（mediator）：迪米特原则
//		
//

class Country;
class UnitedNation
{
public:
	virtual void Declare(string msg, Country* country) = 0;
};


class Country
{
private:
	UnitedNation* mediator_;

public:
	Country(UnitedNation* mediator)
	{
		mediator_ = mediator;
	}

	UnitedNation* GetMediator() { return mediator_; }

	virtual void SetName(string name) = 0;
	virtual string GetName() = 0;
};


class US : public Country
{
private:
	string name_;
public:
	US(UnitedNation* mediator) : Country(mediator)
	{

	}

	void SetName(string name)
	{
		name_ = name;
	}

	string GetName()
	{
		return name_;
	}

	void Declare(string msg)
	{
		this->GetMediator()->Declare(msg, this);
	}


	void GetMessage(string msg)
	{
		printf("US get message: %s\n", msg.c_str());
	}
};


class Iraq : public Country
{
private:
	string name_;
public:
	void SetName(string name)
	{
		name_ = name;
	}

	string GetName()
	{
		return name_;
	}

	Iraq(UnitedNation* mediator) : Country(mediator)
	{

	}

	void Declare(string msg)
	{
		this->GetMediator()->Declare(msg, this);
	}


	void GetMessage(string msg)
	{
		printf("US get message: %s\n", msg.c_str());
	}
};


class UNSecurityCouncil : public UnitedNation
{
private:
	US* us_;
	Iraq* iraq_;
public:
	void Declare(string msg, Country* country)
	{
		if (country->GetName() == "美国")
		{
			iraq_->GetMessage(msg);
		}
		else
		{
			us_->GetMessage(msg);
		}
	}
};

#endif
#pragma once
#include <stdio.h>

//	装饰模式（decorator）：动态给对象增加
//	一些额外职责。
//	向旧类中添加新代码，而增加的代码主要
//	起修饰旧类的核心逻辑

class Person
{
private:
	int id_;

public:
	Person() : id_(0){}
	Person(int id) : id_(id){}
	virtual ~Person(){}

	virtual void Show(){ printf("%d\n",id_); }
};



class Clothes : public Person
{
public:
	Clothes() {}
	virtual ~Clothes() {}

	void Decorator(Person* p)
	{
		person_ = p;
	}

	virtual void Show()
	{
		if (person_)
		{
			person_->Show();
		}
	}
protected:
	Person* person_;
};


class TShirt : public Clothes
{
public:
	void Show()
	{
		printf("TShirt ");
		person_->Show();
	}
};


class Shoes : public Clothes
{
public:
	void Show()
	{
		printf("Shoes ");
		person_->Show();
	}
};


class Trouser : public Clothes
{
public:
	void Show()
	{
		printf("Trouser ");
		person_->Show();
	}
};
#ifndef OBSERVER_H_
#define OBSERVER_H_
#include <cstdio>
#include <string>
#include <list>
using namespace std;


//	观察者模式（Observer）：一对多的依赖关系
//	让多个观察者监听同一个通知对象


//	观察者
class Observer
{
public:
	virtual void Update() = 0;
};

//	通知者
class Subject
{
public:
	virtual void Attach(Observer* o) = 0;
	virtual void Detach(Observer* o) = 0;
	virtual void Notify() = 0;
};



class ConcreteSub : public Subject
{
private:
	list<Observer*> l_observer_;
	string status_;
public:
	void Attach(Observer* o)
	{
		l_observer_.push_back(o);
	}

	void Detach(Observer* o)
	{
		l_observer_.remove(o);
	}

	void Notify()
	{
		list<Observer*>::iterator it = l_observer_.begin();
		for (; it != l_observer_.end(); it++)
		{
			(dynamic_cast<Observer*>(*it))->Update();
		}
	}

	void SetState(string s)
	{
		status_ = s;
	}

	string GetState()
	{
		return status_;
	}
	
};


class ConcreteObserver : public Observer
{
private:
	ConcreteSub sub_;
	string name_;
	string status_;
public:
	void Update()
	{
		status_ = sub_.GetState();
		printf_s("%s\n",sub_.GetState().c_str());
	}

	ConcreteObserver(string name) : name_(name){}
	void SetSub(ConcreteSub sub)
	{
		sub_ = sub;
	}

	ConcreteSub GetSub()
	{
		return sub_;
	}
};


#endif


#ifndef OBSERVER_H_
#define OBSERVER_H_
#include <cstdio>
#include <string>
#include <list>
using namespace std;


//	�۲���ģʽ��observer�����ö���۲��߶���ͬʱ
//	����ͬһ��������󣬵��������״̬�����仯ʱ��
//	�ܹ�֪ͨ���еĹ۲���


//	�۲���
class Observer
{
public:
	virtual void Update() = 0;
};

//	֪ͨ��
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

	void SetState(const char* s)
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
	ConcreteSub* sub_;
	string name_;
	string status_;
public:
	void Update()
	{
		status_ = sub_->GetState();
		printf("%s",sub_->GetState().c_str());
	}

	ConcreteObserver(const char* name) : name_(name){}
	void SetSub(ConcreteSub* sub)
	{
		sub_ = sub;
	}

	ConcreteSub* GetSub()
	{
		return sub_;
	}
};


#endif


#ifndef FLY_WEIGHT_H_
#define FLY_WEIGHT_H_
#include <cstdio>
#include <string>
#include <map>
using namespace std;
//	��Ԫģʽ��flyweight�������ù�����֧�ִ���ϸ����
//	����
//

class Website
{
public:
	virtual void Use() = 0;
};


class ConcreteWebsite : public Website
{
private:
	string name_;

public:
	ConcreteWebsite(string name)
	{
		name_ = name;
	}


	void Use(/*�ⲿ״̬*/)
	{
		printf("name: %s\n", name_.c_str());
	}
};


class WebSiteFactory
{
private:
	map<string, Website*> flyweight_;
public:

	Website* GetConcreteWebsite(string key)
	{
		map<string, Website*>::iterator it = flyweight_.find(key);
		if (it == flyweight_.end())
		{
			flyweight_.insert(make_pair(key, new ConcreteWebsite(key)));
		}
		else
		{
			return it->second;
		}

	}


	void Clear()
	{
		map<string, Website*>::iterator it = flyweight_.begin();
		for (; it != flyweight_.end(); it++)
		{
			delete it->second;
		}
	}

	void Show()
	{
		map<string, Website*>::iterator it = flyweight_.begin();
		for (; it != flyweight_.end(); it++)
		{
			it->second->Use();
		}
	}


	int GetCount()
	{
		return flyweight_.size();
	}
};


#endif
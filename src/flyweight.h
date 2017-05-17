#ifndef FLY_WEIGHT_H_
#define FLY_WEIGHT_H_
#include <cstdio>
#include <string>
#include <map>
using namespace std;
//	
//	
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


	void Use()
	{
		printf(": %s\n", name_.c_str());
	}
};


class WebSiteFactory
{
private:
	map<string, Website*> flyweight;
public:

	Website* GetConcreteWebsite(string key)
	{
		map<string, Website*>::iterator it = flyweight.find(key);
		if (it == flyweight.end())
		{
			flyweight.insert(make_pair(key, new ConcreteWebsite(key)));
		}
		else
		{
			return it->second;
		}

	}

	int GetCount()
	{
		return flyweight.size();
	}
};


#endif
#pragma once
#include <cstdio>
#include <string>
using namespace std;
//	代理模式（Proxy）： 为其他对象提供代理
//	以控制这个对象的访问权限
//

class IPersuer
{
public:
	virtual void SendFlower() = 0;
	virtual void SendFood() = 0;
	virtual void TellJoker() = 0;
};



class Persuer : public IPersuer
{
public:
	void SendFlower()
	{
		printf_s("Send Flower\n");
	}


	void SendFood()
	{
		printf_s("Send Food\n");
	}

	void TellJoker()
	{
		printf_s("Tell Joker\n");
	}
};


class Proxy : public IPersuer
{
private:
	IPersuer* persuer_;
public:
	void SetPersuer(IPersuer* persuer)
	{
		persuer_ = persuer;
	}

	void SendFlower()
	{
		persuer_->SendFlower();
	}

	void SendFood()
	{
		persuer_->SendFood();
	}

	void TellJoker()
	{
		persuer_->TellJoker();
	}
};
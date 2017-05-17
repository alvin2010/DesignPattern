#pragma once
#include <cstdio>
#include <string>
using namespace std;



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
		printf("Send Flower\n");
	}


	void SendFood()
	{
		printf("Send Food\n");
	}

	void TellJoker()
	{
		printf("Tell Joker\n");
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
#pragma once
#include <cstdio>
#include <string>
using namespace std;
//	����ģʽ��Proxy���� Ϊ���������ṩ����
//	�Կ����������ķ���Ȩ��
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
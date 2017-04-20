#pragma once

//	����ģʽ��Proxy���� δ���������ṩ����
//	�Կ����������ķ���Ȩ��
//
//
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
	Persuer persuer_;
public:
	void SendFlower()
	{
		persuer_.SendFlower();
	}

	void SendFood()
	{
		persuer_.SendFood();
	}

	void TellJoker()
	{
		persuer_.TellJoker();
	}
};
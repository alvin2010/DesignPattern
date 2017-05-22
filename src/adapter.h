#ifndef ADAPTER_H_
#define ADAPTER_H_
#include <cstdio>


//	适配器模式（adapter）：将一个类的
//	接口转换为客户希望的接口


class Player
{
public:
	virtual void Defense() {}
	virtual void Attack() {}
};



class Forward : public Player
{
public:
	void Defense()
	{
		printf("Forward Defense\n");
	}

	void Attack()
	{
		printf("Forward Attack\n");
	}

};


class Center : public Player
{
public:
	void Defense()
	{
		printf("Center Defense\n");
	}

	void Attack()
	{
		printf("Center Attack\n");
	}
};


class Guard : public Player
{
public:
	void Defense()
	{
		printf("Guard Defense\n");
	}

	void Attack()
	{
		printf("Guard Attack\n");
	}
};


class ForeignCenter
{
public:
	void Defense()
	{
		printf("ForeignCenter Defense\n");
	}

	void Attack()
	{
		printf("ForeignCenter Attack\n");
	}
};


class Translator : public Player
{
private:
	ForeignCenter foreign_center_;

public:	
	
	void Defense()
	{
		foreign_center_.Defense();
	}

	void Attack()
	{
		foreign_center_.Attack();
	}

};

#endif
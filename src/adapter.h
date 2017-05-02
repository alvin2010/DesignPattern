#ifndef ADAPTER_H_
#define ADAPTER_H_
#include <cstdio>

//	适配器模式（adapter）：将一个类的接口
//	转换成客户所需要的另外一个接口
//


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
		printf_s("Forward Defense\n");
	}

	void Attack()
	{
		printf_s("Forward Attack\n");
	}

};


class Center : public Player
{
public:
	void Defense()
	{
		printf_s("Center Defense\n");
	}

	void Attack()
	{
		printf_s("Center Attack\n");
	}
};


class Guard : public Player
{
public:
	void Defense()
	{
		printf_s("Guard Defense\n");
	}

	void Attack()
	{
		printf_s("Guard Attack\n");
	}
};


class ForeignCenter : public Player
{
public:
	void Defense()
	{
		printf_s("ForeignCenter Defense\n");
	}

	void Attack()
	{
		printf_s("ForeignCenter Attack\n");
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
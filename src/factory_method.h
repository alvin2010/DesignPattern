#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <cstdio>

//	工厂方法（factory_method）：定义一个创建对象的
//	接口，让子类决定实例化哪一个类
//

class LeiFeng
{
public:
	virtual void Sweep() = 0;

	virtual void Sing() = 0;


	virtual void Wash() = 0;

	virtual ~LeiFeng(){}
};


class Volunteer : public LeiFeng
{
public:
	virtual ~Volunteer(){}

	virtual void Sweep()
	{
		printf("Volunteer sweep\n");
	}

	virtual void Sing()
	{
		printf("Volunteer sing\n");
	}


	virtual void Wash()
	{
		printf("Volunteer wash\n");
	}
};


class Graduate : public LeiFeng
{
public:
	virtual ~Graduate() {}

	virtual void Sweep()
	{
		printf("Sweep sweep\n");
	}

	virtual void Sing()
	{
		printf("Sweep sing\n");
	}


	virtual void Wash()
	{
		printf("Sweep wash\n");
	}
};


class IFactory
{
public:
	virtual LeiFeng* CreateLeifeng() = 0;
	virtual void ReleaseLeifeng(LeiFeng* lf) = 0;
};


class GraduateFactory : public IFactory
{
public:
	LeiFeng* CreateLeifeng()
	{
		return new Graduate();
	}

	void ReleaseLeifeng(LeiFeng* lf)
	{
		if (lf)
		{
			delete lf;
		}
	}
};


class VolunteerFactory : public IFactory
{
public:
	LeiFeng* CreateLeifeng()
	{
		return new Volunteer();
	}

	void ReleaseLeifeng(LeiFeng* lf)
	{
		if (lf)
		{
			delete lf;
		}
	}
};


#endif
#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <cstdio>

//	工厂方法（factory_method）: 让子类决定
//	实例化哪一个类，把内部判断逻辑转移到客
//	户端

class LeiFeng
{
public:
	void Sweep()
	{
		printf_s("sweep\n");
	}

	void Sing()
	{
		printf_s("sing\n");
	}


	void Wash()
	{
		printf_s("wash\n");
	}

	virtual ~LeiFeng(){}
};


class Volunteer : public LeiFeng
{
public:
	virtual ~Volunteer(){}
};


class Graduate : public LeiFeng
{
	virtual ~Graduate();
};


class IFactory
{
public:
	virtual LeiFeng* CreateLeifeng() = 0;
};


class GraduateFactory : public IFactory
{
public:
	LeiFeng* CreateLeifeng()
	{
		return new Graduate();
	}
};


class VolunteerFactory : public IFactory
{
	LeiFeng* CreateLeifeng()
	{
		return new Volunteer();
	}
};


#endif
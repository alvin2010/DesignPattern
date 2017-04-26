#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <cstdio>

//	����������factory_method��: ���������
//	ʵ������һ���࣬���ڲ��ж��߼�ת�Ƶ���
//	����

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
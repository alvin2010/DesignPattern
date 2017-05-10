#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <cstdio>

//	����������factory_method��: �ÿͻ���
//	������ʵ����һ���࣬�Ѽ򵥹������ڲ�
//	�ж��߼�ת�Ƶ��ͻ���

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
		printf_s("Volunteer sweep\n");
	}

	virtual void Sing()
	{
		printf_s("Volunteer sing\n");
	}


	virtual void Wash()
	{
		printf_s("Volunteer wash\n");
	}
};


class Graduate : public LeiFeng
{
public:
	virtual ~Graduate() {}

	virtual void Sweep()
	{
		printf_s("Sweep sweep\n");
	}

	virtual void Sing()
	{
		printf_s("Sweep sing\n");
	}


	virtual void Wash()
	{
		printf_s("Sweep wash\n");
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
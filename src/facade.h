#ifndef FACADE_H_
#define FACADE_H_
#include <cstdio>

//	外观模式（facade）：通过外观
//	不知道内部实现细节
//

class MethodA 
{
public:
	void Method(){ printf("Method A\n"); }
};

class MethodB
{
public:
	void Method(){ printf("Method B\n"); }
};


class MethodC
{
public:
	void Method(){ printf("Method C\n"); }
};


class MethodD
{
public:
	void Method(){ printf("Method D\n"); }
};


class Method
{
private:
	MethodA a_;
	MethodB b_;
	MethodC c_;
	MethodD d_;
public:
	void Method1(){
		a_.Method();
		b_.Method();
		c_.Method();
	}

	void Method2()
	{
		b_.Method();
		c_.Method();
		d_.Method();
	}

	void Method3()
	{
		a_.Method();
		d_.Method();
	}
};

#endif
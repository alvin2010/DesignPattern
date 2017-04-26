#ifndef TEMPLATE_METHOD_H_
#define TEMPLATE_METHOD_H_
#include <cstring>
using namespace std;

//	模板方法（Template_factory）：子类可以不改变
//	算法的结构即可重定义某些特定的步骤
//

class TestPaper
{
public:
	TestPaper(){}
	virtual ~TestPaper(){}



	void Question1()
	{
		printf_s("Question1's answer is: %s\n", Answer1().c_str());
	}

	void Question2()
	{
		printf_s("Question2's answer is: %s\n", Answer2().c_str());
	}

	void Question3()
	{
		printf_s("Question3's answer is: %s\n", Answer3().c_str());
	}

	virtual string Answer1()
	{
		return "";
	}

	virtual string Answer2()
	{
		return "";
	}

	virtual string Answer3()
	{
		return "";
	}
};

class StudentAPaper : public TestPaper
{
public:
	virtual ~StudentAPaper(){}
	virtual string Answer1()
	{
		return "a";
	}

	virtual string Answer2()
	{
		return "b";
	}

	virtual string Answer3()
	{
		return "c";
	}
};

class StudentBPaper : public TestPaper
{
public:
	virtual ~StudentBPaper(){}
	virtual string Answer1()
	{
		return "c";
	}

	virtual string Answer2()
	{
		return "b";
	}

	virtual string Answer3()
	{
		return "a";
	}

};




#endif
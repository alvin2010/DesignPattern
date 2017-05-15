#ifndef TEMPLATE_METHOD_H_
#define TEMPLATE_METHOD_H_
#include <cstring>
using namespace std;

//	ģ�巽����Template_factory�����������Բ��ı�
//	�㷨�Ľṹ�����ض���ĳЩ�ض��Ĳ���
//

class TestPaper
{
public:
	virtual ~TestPaper(){}

	void Question1()
	{
		printf("Question1's answer is: %s\n", Answer1().c_str());
	}

	void Question2()
	{
		printf("Question2's answer is: %s\n", Answer2().c_str());
	}

	void Question3()
	{
		printf("Question3's answer is: %s\n", Answer3().c_str());
	}

	virtual string Answer1() = 0;
	
	virtual string Answer2() = 0;

	virtual string Answer3() = 0;
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
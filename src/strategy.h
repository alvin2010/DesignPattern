#pragma once

//	����ģʽ��strategy���������㷨���壬
//	ÿһ�ֲ��Զ�Ӧһ���㷨
//
//
//

class CashSuper
{
public:
	virtual void AcceptCash(){}
};


class CashNormal : public CashSuper
{
public:
	void AcceptCash()
	{
		printf_s("Normal Cash \n");
	}
};

//�ؿ���
class CashRebate : public CashSuper
{
public:
	void AcceptCash()
	{
		printf_s("Rebate Cash \n");
	}
};


class CashReturn : public CashSuper
{
public:
	void AcceptCash()
	{
		printf_s("Return Cash \n");
	}
};


class Context
{
private:
	CashSuper* super_;
public:
	Context(CashSuper cash){
		super_ = &cash;
	}

	void GetResult()
	{
		super_->AcceptCash();
	}

};
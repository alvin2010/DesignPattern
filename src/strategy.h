#pragma once

//	策略模式（strategy）：定义算法家族，
//	每一种策略对应一种算法
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

//回扣类
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
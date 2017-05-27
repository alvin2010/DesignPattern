#pragma once


//	策略模式（strategy）：算法家族，算法之间
//	可以相互替换而不影响客户端。
//	需要执行环境(context)

class CashSuper
{
public:
	virtual void AcceptCash() = 0;
};


class CashNormal : public CashSuper
{
public:
	void AcceptCash()
	{
		printf("Normal Cash \n");
	}
};


class CashRebate : public CashSuper
{
public:
	void AcceptCash()
	{
		printf("Rebate Cash \n");
	}
};


class CashReturn : public CashSuper
{
public:
	void AcceptCash()
	{
		printf("Return Cash \n");
	}
};


class Context
{
private:
	CashSuper* super_;
public:
	Context(){
		super_ = NULL;
	}

	void SetCash(CashSuper* cash)
	{
		super_ = cash;
	}

	void GetResult()
	{
		super_->AcceptCash();
	}

};
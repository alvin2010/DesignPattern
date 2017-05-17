#pragma once



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
#pragma once


//	桥接模式（bridge）： 抽象部分和实现部分相分离
//	使他们都可以独立变化
// 



class HandSoft
{
public:
	virtual void Run() {};
};

class Game : public HandSoft
{
public:
	void Run()
	{
		printf_s("Game Run \n");
	}
};

class AddressList : public HandSoft
{
public:
	void Run()
	{
		printf_s("AddressList Run \n");
	}
};


class HandBrand
{
public:
	virtual void Run() = 0;
};


class HandBrandM : public HandBrand
{
private:
	HandSoft* soft_;
public:
	void Run()
	{
		soft_->Run();
	}

	void SetSoft(HandSoft soft)
	{
		soft_ = &soft;
	}
};


class HandBrandN : public HandBrand
{
private:
	HandSoft* soft_;
public:
	void Run()
	{
		soft_->Run();
	}

	void SetSoft(HandSoft soft)
	{
		soft_ = &soft;
	}
};




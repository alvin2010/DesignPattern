#pragma once


//	桥接模式（bridge）：实现的方式有多种
//	将这些实现独立出来，使他们各自变化而
//	不影响其他功能


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
		printf("Game Run \n");
	}
};

class AddressList : public HandSoft
{
public:
	void Run()
	{
		printf("AddressList Run \n");
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

	void SetSoft(HandSoft* soft)
	{
		soft_ = soft;
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

	void SetSoft(HandSoft* soft)
	{
		soft_ = soft;
	}
};




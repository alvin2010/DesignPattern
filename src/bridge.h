#pragma once


//	�Ž�ģʽ��bridge���� ���󲿷ֺ�ʵ�ֲ���������
//	ʹ���Ƕ����Զ����仯
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




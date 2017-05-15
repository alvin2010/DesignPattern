#ifndef COMMAND_H_
#define COMMAND_H_
#include <cstdio>
#include <list>
using namespace std;

//  ����ģʽ��command������������װ��һ������
//	�������Ŷӻ���¼��־���Լ�֧�ֿɳ���
//

class Barbecuer
{
public:
	void BarbecueMatton()
	{
		printf("������\n");
	}

	void BarbecueChick()
	{
		printf("������\n");
	}
};

class Command
{
protected:
	Barbecuer* barbecuer_;
public:
	virtual	void ExcuteCommand() = 0;
};

class Waiter
{
private:
	list<Command*> lc;

	void AddCommand(Command* command)
	{
		lc.push_back(command);
	}

	void Notify()
	{
		list<Command*>::iterator it = lc.begin();
		for (; it != lc.end(); it++)
		{
			(*it)->ExcuteCommand();
		}

		lc.clear();
	}


};


class BarbecueMattonCommand : public Command
{
public:
	BarbecueMattonCommand(Barbecuer& bar)
	{
		barbecuer_ = &bar;
	}

	void ExcuteCommand()
	{
		barbecuer_->BarbecueMatton();
	}
};


class BarbecueChickCommand : public Command
{
public:
	BarbecueChickCommand(Barbecuer& bar)
	{
		barbecuer_ = &bar;
	}

	void ExcuteCommand()
	{
		barbecuer_->BarbecueChick();
	}
};


#endif
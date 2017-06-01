#ifndef COMMAND_H_
#define COMMAND_H_
#include <cstdio>
#include <list>
using namespace std;

//	命令模式（command）：将请求封装成接口，根据客户不同的
//	参数实例化不同的请求对象，并对请求排队。
//

class Barbecuer
{
public:
	void BarbecueMatton()
	{
		printf("barbecue matton\n");
	}

	void BarbecueChick()
	{
		printf("barbecue chick\n");
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

public:
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
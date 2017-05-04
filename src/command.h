#ifndef COMMAND_H_
#define COMMAND_H_
#include <cstdio>
#include <list>
using namespace std;

//  命令模式（command）：将请求封装成一个对象
//	对请求排队或记录日志，以及支持可撤销
//

class Barbecuer
{
public:
	void BarbecueMatton()
	{
		printf_s("烤羊肉\n");
	}

	void BarbecueChick()
	{
		printf_s("烤鸡翅\n");
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
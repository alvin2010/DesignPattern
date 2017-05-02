#ifndef STATE_H_
#define STATE_H_
#include <cstdio>
//	状态模式（state）：一个对象的内在状态改变时
//	改变了其行为，这个对象看起来像是改变了其类
//
class State;

class Work
{
private:
	State* state_;
	int hour_;
public:
	Work();

	void SetHour(int hour);
	int GetHour();

	void SetState(State* state);
	State* GetState();

	void WriteProgram();
};


class State
{
public:
	virtual void WriteProgram(Work* work) {};
};


class ForenoonState : public State
{
public:
	void WriteProgram(Work* work);
};


class NoonState : public State
{
public:
	void WriteProgram(Work* work);
};


class AfternoonState : public State
{
public:
	void WriteProgram(Work* work);
};


class EveningState : public State
{
public:
	void WriteProgram(Work* work);
};


class SleepingState : public State
{
public:
	void WriteProgram(Work* work);
};


class RestState :public State
{
public:
	void WriteProgram(Work* work)
	{
		printf_s("Rest state\n");
	}
};

#endif
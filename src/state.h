#ifndef STATE_H_
#define STATE_H_
#include <cstdio>

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
		printf("Rest state\n");
	}
};

#endif
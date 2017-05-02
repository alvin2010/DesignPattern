#include "state.h"


Work::Work()
{
	state_ = new ForenoonState();
}

void Work::SetHour(int hour)
{
	hour_ = hour;
}

int Work::GetHour() { return hour_; }

void Work::SetState(State* state)
{
	state_ = state;
}

State* Work::GetState() { return state_; }


void Work::WriteProgram()
{
	state_->WriteProgram(this);
}


void ForenoonState::WriteProgram(Work* work)
{
	if (work->GetHour() < 12)
	{
		printf_s("forenoon work state\n");
	}
	else
	{
		State* sta = work->GetState();
		delete sta;
		work->SetState(new NoonState());
		work->WriteProgram();
	}
}


void NoonState::WriteProgram(Work* work)
{
	if (work->GetHour() < 13)
	{
		printf_s("noon work state\n");
	}
	else
	{
		State* sta = work->GetState();
		delete sta;
		work->SetState(new AfternoonState());
		work->WriteProgram();
	}
}


void AfternoonState::WriteProgram(Work* work)
{
	if (work->GetHour() < 17)
	{
		printf_s("AfternoonState work state\n");
	}
	else
	{
		State* sta = work->GetState();
		delete sta;
		work->SetState(new EveningState());
		work->WriteProgram();
	}
}


void EveningState::WriteProgram(Work* work)
{
	if (work->GetHour() < 21)
	{
		printf_s("EveningState work state\n");
	}
	else
	{
		State* sta = work->GetState();
		delete sta;
		work->SetState(new SleepingState);
		work->WriteProgram();
	}
}


void SleepingState::WriteProgram(Work* work)
{
	if (work->GetHour() < 22)
	{
		printf_s("Sleeping state\n");
	}
	else
	{
		State* sta = work->GetState();
		delete sta;
		work->SetState(new RestState());
		work->WriteProgram();
	}
}
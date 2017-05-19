#include "state.h"


Work::Work()
{
	state_ = new ForenoonState();
}

Work::~Work()
{
	if (state_ != NULL)
	{
		delete state_;
	}
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
		printf("forenoon work state\n");
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
		printf("noon work state\n");
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
		printf("AfternoonState work state\n");
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
		printf("EveningState work state\n");
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
		printf("Sleeping state\n");
	}
	else
	{
		State* sta = work->GetState();
		delete sta;
		work->SetState(new RestState());
		work->WriteProgram();
	}
}
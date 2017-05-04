#include "iterator.h"



ConcreteIterator::ConcreteIterator(ConcreteAggregate *aggregate)
{
	this->aggregate_ = aggregate;
	current_ = 0;
}


int ConcreteIterator::First()
{
	return aggregate_->Get(0);
}


int ConcreteIterator::Next()
{
	current_ += 1;
	if (current_ < aggregate_->GetCount())
	{
		return aggregate_->Get(current_);
	}
	else
	{
		throw "out of boundary";
	}
}


int ConcreteIterator::Current()
{
	return aggregate_->Get(current_);
}


bool ConcreteIterator::IsDone()
{
	return current_ >= aggregate_->GetCount() ? true : false;
}
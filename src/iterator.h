#ifndef ITERATOR_H_
#define	ITERATOR_H_

#include <cstdio>
#include <string>
#include <vector>
using namespace std;
//	������ģʽ��iterator�����ṩһ�ַ���˳�����
//	�ۺ϶����ÿһ��Ԫ�أ��Ҳ���¶������ڲ��ṹ
//

class Iterator
{
public:
	virtual int First() = 0;
	virtual int Next() = 0;
	virtual int Current() = 0;
	virtual bool IsDone() = 0;
};

class Aggregate
{
public:
	virtual Iterator* CreateIterator() = 0;
};


class ConcreteAggregate;
class ConcreteIterator
{
private:
	ConcreteAggregate* aggregate_;
	int current_;
public:
	ConcreteIterator(ConcreteAggregate *aggregate);
	int First();
	int Next();
	int Current();
	bool IsDone();
};


class ConcreteAggregate : public Aggregate
{
private:
	vector<int> vi;
public:
	Iterator* CreateIterator()
	{
		new ConcreteIterator(this);
	}

	void Insert(int i)
	{
		vi.push_back(i);
	}

	int Get(int index)
	{
		return vi.at(index);
	}

	int GetCount()
	{
		return vi.size();
	}
};



#endif
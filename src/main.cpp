#include "simple_factory.h"
#include "proxy.h"
#include "single_instance.h"
#include "strategy.h"
#include "bridge.h"
#include "prototype.h"
#include "decorator.h"
#include "factory_method.h"
#include "template_method.h"
#include "facade.h"
#include "builder.h"
#include "observer.h"
#include "abstract_factory.h"
#include "state.h"
#include "adapter.h"
#include "memento.h"
#include "composite.h"
#include "iterator.h"
#include "command.h"
#include "chain_of_responsibility.h"
#include "mediator.h"
#include "flyweight.h"
#include "interpreter.h"
#include "visitor.h"

void TestSimpleFactory()
{
	// +
	SimpleFactory factory;
	Operation* oper = factory.CreateOperation("+");
	oper->Set(1, 2);
	printf_s("%lf\n",oper->GetResult());
	factory.DeleteOperation();

	// /
	try {
		factory.CreateOperation("/");
		oper->Set(1, 2);
		printf_s("%lf\n", oper->GetResult());
		
		oper->Set(1, 0);
		printf_s("%lf\n", oper->GetResult());

	}
	//type must be match with throw
	catch (char* e) 
	{
		printf_s("%s\n", e);
		factory.DeleteOperation();
	}
}

int main(int argc, char* argv[])
{

	TestSimpleFactory();


	Person p;
	Trouser t;
	t.Decorator(&p);
	Shoes s;
	s.Decorator(&t);
	s.Show();


	return 0;
}






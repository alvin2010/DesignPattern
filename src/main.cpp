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
	printf("%lf\n",oper->GetResult());
	factory.DeleteOperation();

	// /
	try {
		factory.CreateOperation("/");
		oper->Set(1, 2);
		printf("%lf\n", oper->GetResult());
		
		oper->Set(1, 0);
		printf("%lf\n", oper->GetResult());

	}
	//type must be match with throw
	catch (char* e) 
	{
		printf("%s\n", e);
		factory.DeleteOperation();
	}
}

void TestStrategy()
{
	Context cont;
	CashNormal normal;
	cont.SetCash(&normal);
	cont.GetResult();

	CashRebate rebate;
	cont.SetCash(&rebate);
	cont.GetResult();

	CashReturn ret;
	cont.SetCash(&ret);
	cont.GetResult();
}

void TestDecrator()
{
	Person xa(110);
	
	TShirt shirt;
	Shoes  shoes;
	Trouser trouser;
	shirt.Decorator(&xa);
	shoes.Decorator(&shirt);
	trouser.Decorator(&shoes);
	trouser.Show();
}

void TestProxy()
{
	Proxy proxy;
	Persuer persuer;
	proxy.SetPersuer(&persuer);

	proxy.SendFlower();
	proxy.SendFood();
	proxy.TellJoker();
}

void TestFactoryMethod()
{
	GraduateFactory factory;
	LeiFeng* lf = factory.CreateLeifeng();
	lf->Sing();
	lf->Sweep();
	lf->Wash();
	factory.ReleaseLeifeng(lf);


	VolunteerFactory factory1;
	LeiFeng* lf1 = factory1.CreateLeifeng();
	lf1->Sing();
	lf1->Sweep();
	lf1->Wash();
	factory1.ReleaseLeifeng(lf1);

}

void TestPrototype()
{
	Resume res;
	res.SetPersonalInfo("meimei", "18", "Ů");
	res.SetExperience("tencent game!");
	res.Display();


	Resume* res1 = static_cast<Resume*>(res.Clone());
	res1->Display();
	delete res1;
}

void TestTemplatemethod()
{
	TestPaper* p1 = new StudentAPaper;
	p1->Question1();
	p1->Question2();
	p1->Question3();
	delete p1;

	TestPaper* p2 = new StudentBPaper;
	p2->Question1();
	p2->Question2();
	p2->Question3();
	delete p2;
}

int main(int argc, char* argv[])
{

	//TestSimpleFactory();

	//TestStrategy();

	//TestDecrator();

	TestProxy();

	TestFactoryMethod();
	
	TestPrototype();

	TestTemplatemethod();

	return 0;
}






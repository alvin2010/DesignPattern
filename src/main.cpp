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
	res.SetPersonalInfo("meimei", "18", "女");
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

void TestFacade()
{
	Method m;
	m.Method1();
	m.Method2();
	m.Method3();
}

void TestBuilder()
{
	PersonFat fat;
	PersonThin thin;
	PersonDirctor director(&fat);
	director.CreatePerson();

	PersonDirctor director1(&thin);
	director1.CreatePerson();

}

void TestObserver()
{
	ConcreteSub sub;
	ConcreteObserver ob1("observer 1");
	ConcreteObserver ob2("observer 2");
	ConcreteObserver ob3("observer 3");
	sub.Attach(&ob1);
	sub.Attach(&ob2);
	sub.Attach(&ob3);
	ob1.SetSub(&sub);
	ob2.SetSub(&sub);
	ob3.SetSub(&sub);
	sub.SetState("boss is coming!\n");
	sub.Notify();

}

void TestAbstractFactory()
{
	AccessFactory fac;
	Department* dep = fac.CreateDepartment();
	dep->GetDepartment();
	dep->SetDepartment();
	fac.ReleaseDepartment(dep);


	User* user = fac.CreateUser();
	user->GetUser();
	user->SetUser();
	fac.ReleaseUser(user);


	SqlFactory fac1;
	Department* dep1 = fac1.CreateDepartment();
	dep1->GetDepartment();
	dep1->SetDepartment();
	fac1.ReleaseDepartment(dep1);


	User* user1 = fac1.CreateUser();
	user1->GetUser();
	user1->SetUser();
	fac1.ReleaseUser(user1);
}

void TestState()
{
	Work work;
	work.WriteProgram();

	work.SetHour(12);
	work.WriteProgram();

	work.SetHour(19);
	work.WriteProgram();

	work.SetHour(22);
	work.WriteProgram();
}

void TestAdapter()
{
	Forward f;
	f.Attack();
	f.Defense();

	Center c;
	c.Attack();
	c.Defense();

	Guard g;
	g.Attack();
	g.Defense();

	Translator t;
	t.Attack();
	t.Defense();
}

void TestMemento()
{
	GameRole role;
	role.SetInitState();
	role.ShowState();

	RoleStateManager manager;
	manager.SetMemento(role.SaveState());

	// fight
	role.Fight();
	role.ShowState();
	
	role.SetState(manager.GetMemento());
	role.ShowState();

	manager.Clear();
}

void TestComposite()
{
	ConcreteCompany com("腾讯总公司");
	FinanceDepartment f("总公司财务部门");
	HRDepartment h("总公司Hr部门");
	com.Add(&f);
	com.Add(&h);


	ConcreteCompany com1("北京分公司");
	FinanceDepartment f1("北京分公司财务部门");
	HRDepartment h1("北京分公司Hr部门");
	com1.Add(&f1);
	com1.Add(&h1);
	com.Add(&com1);

	com.Display();
}

void Testiterator()
{
	ConcreteAggregate con;
	
	for (int i = 0; i < 10; i++)
	{
		con.Insert(i);
	}
	
	ConcreteIterator *it = con.CreateIterator();
	printf("%d\n", it->First());
	printf("%d\n", it->Next());
	printf("%d\n", it->Current());
	con.DeleteIterator(it);
}

void TestSingleton()
{
	Singleton* sin = Singleton::GetInstance();
}

void TestBridge()
{
	Game game;
	AddressList add;

	HandBrandM m;
	m.SetSoft(&game);
	m.Run();
	m.SetSoft(&add);
	m.Run();

	HandBrandN n;
	n.SetSoft(&game);
	n.Run();
	n.SetSoft(&add);
	n.Run();
}

void TestCommand()
{
	Barbecuer bar;
	BarbecueChickCommand  chick(bar);
	BarbecueMattonCommand matton(bar);
	BarbecueMattonCommand matton1(bar);
	BarbecueChickCommand chick1(bar);
	Waiter w;
	w.AddCommand(&chick);
	w.AddCommand(&matton);
	w.AddCommand(&matton1);
	w.AddCommand(&chick1);
	w.Notify();
}

void TestChainofresponsibility()
{
	CommonManager cm;
	MajorManager mm;
	GeneralManager gm;
	
	cm.SetSuper(&mm);
	mm.SetSuper(&gm);

	Request req;
	req.SetType(1);
	req.SetNum(3);

	cm.Handle(req);


}

void TestMediator()
{
	UNSecurityCouncil un;
	US us(&un);
	Iraq iraq(&un);

	us.SetName("美国");
	iraq.SetName("伊拉克");

	us.Declare("我要干你了！");
	iraq.Declare("干就干，谁怕谁！");
}

int main(int argc, char* argv[])
{

	TestSimpleFactory();

	TestStrategy();

	TestDecrator();

	TestProxy();

	TestFactoryMethod();
	
	TestPrototype();

	TestTemplatemethod();

	TestFacade();

	TestBuilder();

	TestObserver();

	TestAbstractFactory();

	TestState();

	TestAdapter();

	TestMemento();

	TestComposite();

	Testiterator();

	TestSingleton();

	TestBridge();

	TestCommand();

	TestChainofresponsibility();

	TestMediator();

	system("pause");

	return 0;
}






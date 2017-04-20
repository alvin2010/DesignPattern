#include "simple_factory.h"
#include "proxy.h"
#include "single_instance.h"
#include "strategy.h"
#include "bridge.h"

int main(int argc, char* argv[])
{
	SimpleFactory factory;
	Operation* oper = factory.CreateOperation("+");
	oper->Set(1, 2);
	oper->GetResult();
	return 0;
}






#include "simple_factory.h"



int main(int argc, char* argv[])
{
	SimpleFactory factory;
	Operation* oper = factory.CreateOperation("+");
	oper->Set(1, 2);
	oper->GetResult();
	return 0;
}






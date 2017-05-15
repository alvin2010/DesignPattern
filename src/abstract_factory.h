#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_
#include <cstdio>

//	���󹤳���abstract_factory�����ṩһϵ��
//  ���ػ��໥���������Ľӿ�,���ڽ�����Ʒϵ��
//

class User
{
public:
	virtual void GetUser() = 0;
	virtual void SetUser() = 0;
};


class Department
{
public:
	virtual void SetDepartment() = 0;
	virtual void GetDepartment() = 0;
};


class SqlUser : public User
{
public:
	void GetUser()
	{
		printf("Sql Get User!\n");
	}
	void SetUser()
	{
		printf("Sql Set User!\n");
	}
};


class AccessUser : public User
{
public:
	void GetUser()
	{
		printf("Access Get User!\n");
	}
	void SetUser()
	{
		printf("Sql Set User!\n");
	}

};

class SqlDepartment : public Department
{
public:
	void SetDepartment()
	{
		printf("Sql Set Department!\n");
	}
	void GetDepartment()
	{
		printf("Sql Get Department!\n");
	}
};


class AccessDepartment : public Department
{
public:
	void SetDepartment()
	{
		printf("Access Set Department!\n");
	}
	void GetDepartment()
	{
		printf("Access Get Department!\n");
	}
};

class Factory
{
public:
	virtual Department* CreateDepartment() = 0;
	virtual User* CreateUser() = 0;
};


class AccessFactory : public Factory
{
public:
	Department* CreateDepartment()
	{
		return new AccessDepartment();
	}

	User* CreateUser()
	{
		return new AccessUser();
	}
};


class SqlFactory : public Factory
{
	Department* CreateDepartment()
	{
		return new SqlDepartment();
	}

	User* CreateUser()
	{
		return new SqlUser();
	}
};


#endif
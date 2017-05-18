#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_
#include <cstdio>

//	抽象工厂（abstract_factory）：定义一个创建一系列
//  相关联类实例的接口，而无需指定他们具体类
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
	virtual ~Department(){}
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

	virtual ~SqlUser() {}
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

	virtual ~AccessUser(){}
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

	virtual ~SqlDepartment(){}
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

	virtual ~AccessDepartment(){}
};

class Factory
{
public:
	virtual Department* CreateDepartment() = 0;
	virtual User* CreateUser() = 0;
	virtual void ReleaseDepartment(Department* dep) = 0;
	virtual void ReleaseUser(User* user) = 0;
};


class AccessFactory : public Factory
{
public:
	Department* CreateDepartment()
	{
		return new AccessDepartment();
	}

	void ReleaseDepartment(Department* dep)
	{
		delete dep;
	}

	User* CreateUser()
	{
		return new AccessUser();
	}

	void ReleaseUser(User* user)
	{
		delete user;
	}
};


class SqlFactory : public Factory
{
public:
	Department* CreateDepartment()
	{
		return new SqlDepartment();
	}

	void ReleaseDepartment(Department* dep)
	{
		delete dep;
	}

	User* CreateUser()
	{
		return new SqlUser();
	}

	void ReleaseUser(User* user)
	{
		delete user;
	}
};

#endif
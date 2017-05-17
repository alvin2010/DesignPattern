#pragma once





class ProtoType
{
public:
	ProtoType(){}
	virtual ~ProtoType() {}

	virtual ProtoType* Clone() = 0;
};


class ConcreteType : public ProtoType
{
public:
	ConcreteType()  {}
	virtual ~ConcreteType() {}

	virtual ProtoType* Clone()
	{
		return new ConcreteType(*this);
	}

	void	SetId(int id) { id_ = id; }
private:
	ConcreteType(const ConcreteType& rhs)
	{
		id_ = rhs.id_;
	}

	int id_;
};


//	attention: the cloned object must be released
//	by operator delete

class IClone
{
public:
	virtual IClone* Clone() = 0;
	virtual ~IClone(){}
};

class Resume : public IClone
{
private:
	string name_;
	string age_;
	string sex_;
	string exp_;
public:
	void SetPersonalInfo(const char* name, const char* age, const char* sex)
	{
		name_ = name;
		age_ = age;
		sex_ = sex;
	}


	void SetExperience(const char* exp)
	{
		exp_ = exp;
	}

	void Display()
	{
		printf("name:%s\nsex:%s\nage:%s\n",name_.c_str(), sex_.c_str(), age_.c_str());
		printf("experience:%s\n", exp_.c_str());
	}

	IClone* Clone()
	{
		Resume* res = new Resume();
		res->SetExperience(exp_.c_str());
		res->SetPersonalInfo(name_.c_str(), age_.c_str(), sex_.c_str());
		return res;
	}
};


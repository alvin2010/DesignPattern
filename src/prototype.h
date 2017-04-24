#pragma once


//	原型模式（bridge）： 从一个对象
//  再创建另外一个可定制对象
//	注意：深浅复制


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



#pragma once


//	ԭ��ģʽ��bridge���� ��һ������
//  �ٴ�������һ���ɶ��ƶ���
//	ע�⣺��ǳ����


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



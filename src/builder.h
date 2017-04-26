#ifndef BUILDER_H_
#define BUILDER_H_

//	建造者模式（builder）：同样的建造
//	过程可以创建不同的对象
//

class PersonBuilder
{
public:
	virtual void Head() = 0;
	virtual void Body() = 0;
	virtual void LeftArm() = 0;
	virtual void RightArm() = 0;
	virtual void LeftLeg() = 0;
	virtual void RightLeg() = 0;

};

class PersonThin : public PersonBuilder
{
public:
	virtual void Head(){ printf("Thin Head\n"); }
	virtual void Body() { printf("Thin Body\n"); }
	virtual void LeftArm() { printf("Thin LeftArm\n"); }
	virtual void RightArm() { printf("Thin RightArm\n"); }
	virtual void LeftLeg() { printf("Thin LeftLeg\n"); }
	virtual void RightLeg() { printf("Thin rightLeg\n"); }
};

class PersonFat : public PersonBuilder
{
public:
	virtual void Head(){ printf("Fat Head\n"); }
	virtual void Body() { printf("Fat Body\n"); }
	virtual void LeftArm() { printf("Fat LeftArm\n"); }
	virtual void RightArm() { printf("Fat RightArm\n"); }
	virtual void LeftLeg() { printf("Fat LeftLeg\n"); }
	virtual void RightLeg() { printf("Fat rightLeg\n"); }
};


class PersonDirctor
{
private:
	PersonBuilder* builder_;
public:
	PersonDirctor(PersonBuilder* builder) : builder_(builder){}

	void CreatePerson()
	{
		builder_->Head();
		builder_->Body();
		builder_->LeftArm();
		builder_->RightArm();
		builder_->LeftLeg();
		builder_->RightLeg();
	}
};



#endif
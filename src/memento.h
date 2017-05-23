#ifndef MEMENTO_H_
#define MEMENTO_H_
#include <cstdio>

//	备忘录模式（memento）：不破坏封装的前提下捕获
//	对象的内部状态，并在该对象之外保存这些状态，以
//	便以后恢复这些状态

class Memento
{
private:
	int attack_;
	int defense_;
	int life_;
public:
	void SetLife(int life)
	{
		life_ = life;
	}

	int GetLife()
	{
		return life_;
	}

	void SetDefense(int defense)
	{
		defense_ = defense;
	}

	int GetDefense()
	{
		return defense_;
	}

	void SetAttack(int attack)
	{
		attack_ = attack;
	}

	int GetAttack()
	{
		return attack_;
	}


};

class GameRole
{
private:
	int attack_;
	int defense_;
	int life_;

public:
	void ShowState()
	{
		printf("life: %d, attack: %d, defense: %d\n",life_, attack_, defense_);
	}


	void SetInitState()
	{
		attack_ = 100;
		defense_ = 100;
		life_ = 100;
	}

	void Fight()
	{
		attack_ = 0;
		defense_ = 0;
		life_ = 0;
	}

	Memento* SaveState()
	{
		Memento* mem = new Memento();
		mem->SetLife(life_);
		mem->SetAttack(attack_);
		mem->SetDefense(defense_);
		return mem;
	}

	void SetState(Memento* mem)
	{
		this->life_ = mem->GetLife();
		this->attack_ = mem->GetAttack();
		this->defense_ = mem->GetDefense();
	}

};


class RoleStateManager
{
private:
	Memento* memento_;

public:
	void SetMemento(Memento* mem)
	{
		memento_ = mem;
	}

	Memento* GetMemento()
	{
		return memento_;
	}

	void Clear()
	{
		if (memento_)
		{
			delete memento_;
			memento_ = NULL;
		}
	}
};




#endif
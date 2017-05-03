#ifndef MEMENTO_H_
#define MEMENTO_H_
#include <cstdio>

//	备忘录模式（memento）：在不破坏封装的情况下
//	将一个对象的状态保存，这样就可以恢复原来状态
//

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
		printf_s("life: %d, attack: %d, defense: %d",life_, attack_, defense_);
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
};




#endif
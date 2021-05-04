#pragma once
#include <string>
#include "Dice.h"
#include <iostream>

class MemeFighter
{
public:
	std::string GetName() const
	{
		return name;
	}
	bool IsAlive() const
	{
		return hp >= 0;
	}
	int GetInitiative() const
	{
		return speed + Roll(2);
	}
	void Punch(MemeFighter& other) const
	{
		if (IsAlive() && other.IsAlive())
		{
			std::cout << name << " punch bitch " << other.GetName();
		}
		ApDamage(other, power + Roll(2));
	}
	void Tick()
	{
		if (IsAlive())
		{
			const int reco = d.Roll(1);
			std::cout << name << " recovers " << reco << " HP." << std::endl;
			hp += reco;
		}
	}

protected:
	MemeFighter(std::string name, int hp, int power, int speed)
		:
		name(name),
		hp(hp),
		power(power),
		speed(speed)
	{}
	void ApDamage(MemeFighter& target, int dmg) const
	{
		target.hp -= dmg;
		std::cout << target.name << " takes " << dmg << " damage." << std::endl;

		if (target.IsAlive())
		{
			std::cout << target.GetName() << " Still kicking " << std::endl;
		}
	}
	int Roll(int nDice = 1) const
	{
		return d.Roll(nDice);
	}
protected:
	int hp;
	int speed;
	int power;
	std::string name;
	
private:
	mutable Dice d;
	
};
#pragma once
#include "MemeFighter.h"

class MemeFrog : public MemeFighter
{
public:
	MemeFrog(const std::string& name)
		:
		MemeFighter(name, 69, 14, 7)
	{}
	void SpecialMove(MemeFighter& other)
	{
		if (IsAlive() && other.IsAlive())
		{
			if (Roll() > 4)
			{
				std::cout << GetName() << " attacks " << other.GetName() << " with a Huge milk beam!" << std::endl;
				ApDamage(other, 20 + Roll(3));
			}
		}
	}
};
#pragma once
#include "MemeFighter.h"

class MemeStoner : public MemeFighter
{
public:
	MemeStoner(const std::string& name)
		:
		MemeFighter(name, 80, 10 ,4)
	{}
	void SpecialMove()
	{
		if (IsAlive())
		{
			if (Roll() > 3)
			{
				std::cout << GetName() << " smokes the dank sticky icky, becoming " << "Super " << GetName() << std::endl;
				name = "SuperFucker " + name;
				speed += 3;
				power = (power * 69) / 42;
			}
			else
			{
				std::cout << GetName() << " spaces out." << std::endl;
			}
		}
	}


};
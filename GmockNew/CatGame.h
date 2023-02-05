#pragma once

#include "Cat.h"

// Example from Erin Byerly and Emma Bradford

class CatGame
{
	Cat* kitty;
	int happyLevel;
public:

	CatGame(Cat* k);
	void Cuddle();
	void Pet();
	bool IsHappy();
};

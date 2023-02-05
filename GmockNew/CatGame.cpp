#include "CatGame.h"
#include <iostream>
// Example from Erin Byerly and Emma Bradford
CatGame::CatGame(Cat* k)
{
	kitty = k;
	happyLevel = 0;
}

void CatGame::Cuddle() {
	kitty->IncreaseHappinessByAlot(5);
	happyLevel = kitty->GetHappiness();
}

void CatGame::Pet()
{
	kitty->IncreaseHappiness(1);
	happyLevel = kitty->GetHappiness();
}

bool CatGame::IsHappy()
{ 
	if (happyLevel > 25)
		return true;
	else
		return false;

}
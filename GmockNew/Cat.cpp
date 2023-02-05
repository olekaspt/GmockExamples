#include "Cat.h"

// Example from Erin Byerly and Emma Bradford
Cat::Cat() {
	name = "Kitty";
	color = "black";
	happiness = 0;
}
Cat::Cat(std::string n, std::string c) {
	name = n;
	color = c;
	happiness = 0;
}

std::string Cat::GetName() { return name; }
void Cat::SetName(std::string n) { name = n; }

std::string Cat::GetColor() { return color; }
void Cat::SetColor(std::string c) { color = c; }

int Cat::GetHappiness() { return happiness; }
void Cat::SetHappiness(int h) { happiness = h; }
void Cat::IncreaseHappiness(int i)
{

	happiness += i;
}


void Cat::IncreaseHappinessByAlot(int i)
{
	happiness = (i+1)*(happiness+1);
}

#pragma once

#include <string>
// Example from Erin Byerly and Emma Bradford
class Cat
{
	std::string name;
	std::string color;
	int happiness;
	
public:

	Cat();
	Cat(std::string n, std::string c);

	virtual std::string GetName();
	virtual void SetName(std::string n);

	virtual std::string GetColor();
	virtual void SetColor(std::string c);

	virtual int GetHappiness();
	virtual void SetHappiness(int h);
	// Note not virtual
	void IncreaseHappinessByAlot(int i);
	virtual void IncreaseHappiness(int i);

};


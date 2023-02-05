#pragma once

#pragma once

using namespace std;

#include <string>
#include "Cat.h"
#include "gmock/gmock.h"
// Example from Erin Byerly and Emma Bradford
class MockCat : public Cat
{
public:
	MOCK_METHOD(std::string,GetName,  ());
	MOCK_METHOD(std::string,GetColor,  ());
	MOCK_METHOD(void,SetName,  (string n));
	MOCK_METHOD(void,SetColor,  (string c));
	MOCK_METHOD(int,GetHappiness,  ());
	MOCK_METHOD(void,SetHappiness,  (int h));
	MOCK_METHOD(void, IncreaseHappiness, (int i));
	MOCK_METHOD(void, IncreaseHappinessByAlot, (int i));

};


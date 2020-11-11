#pragma once
#include "objectFactory.h"

class simpleObjectFactory: public objectFactory{
public:
	Point* createPoint();
	Poison* createPoison();
	Health* createHealth();
};

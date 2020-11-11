#pragma once
#include "Point.h"
#include "Poison.h"
#include "Health.h"


class objectFactory{
public:
	objectFactory() = default;
	virtual Point* createPoint() = 0;
	virtual Poison* createPoison() = 0;
	virtual Health* createHealth() = 0;
	~objectFactory() = default;
};

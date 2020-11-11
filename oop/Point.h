#pragma once
#include "Object.h"
#include <iostream>
#include "PointIStrategy.h"


class Point: public Object{
private:
	char icon;
    InteractionStrategy* strat;
public:
	Point();
	char getIcon();
	void interaction(Player& player);
	friend std::ostream& operator<<(std::ostream &out, const Point &point);
	~Point();
};

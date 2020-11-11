#pragma once
#include "Object.h"
#include <iostream>
#include "HealthIStrategy.h"

class Health: public Object{
private:
    char icon;
    InteractionStrategy* strat;
public:
    Health();
	char getIcon();
    void interaction(Player& player);
    friend std::ostream& operator<<(std::ostream &out, const Health &health);
	~Health();
};


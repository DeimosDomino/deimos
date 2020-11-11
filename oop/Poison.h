#pragma once
#include "Object.h"
#include <iostream>
#include "PoisonIStrategy.h"

class Poison: public Object{
private:
    char icon;
    InteractionStrategy* strat;
public:
   	Poison();
	char getIcon();
    void interaction(Player& player);
	friend std::ostream& operator<<(std::ostream &out, const Poison &poison);
    ~Poison();
};

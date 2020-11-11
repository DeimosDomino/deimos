#pragma once
#include "InteractionStrategy.h"

class Player;

class Object{
public:
	virtual char getIcon() = 0;
	virtual void interaction(Player& player) = 0;
};

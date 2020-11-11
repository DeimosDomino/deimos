#pragma once
#include "InteractionStrategy.h"
#include "Player.h"

class PoisonIStrategy: public InteractionStrategy{
public:
	void interaction(Player& player);
};

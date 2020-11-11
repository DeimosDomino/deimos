#pragma once
#include "InteractionStrategy.h"
#include "Player.h"

class HealthIStrategy: public InteractionStrategy{
public:
	void interaction(Player& player);	
};

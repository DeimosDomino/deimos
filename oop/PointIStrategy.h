#pragma once
#include "InteractionStrategy.h"
#include "Player.h"

class PointIStrategy: public InteractionStrategy{
public:
    void interaction(Player& player);
};

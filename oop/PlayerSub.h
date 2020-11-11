#pragma once
#include "Sub.h"
#include <string>
#include "PlayerLogger.h"

class Player;

class PlayerSub: public Sub{
private:
	Logger* logger;
public:
	PlayerSub(Player* player);
	void update();
	~PlayerSub();

};

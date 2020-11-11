#pragma once
#include "Logger.h"
#include <fstream>
#include <iostream>
#include "Player.h"

class PlayerLogger: public Logger{
private:
	std::ofstream file;
	Player* player;
public:
	PlayerLogger(Player* player);
	void log();
	~PlayerLogger();
	
};

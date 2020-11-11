#pragma once
#include <iostream>
#include "Publisher.h"
#include "Object.h"
#include "Field.h"
#include "PlayerSub.h"

class Player{
public:
	int x;
	int y;
	char icon;
	char oldIcon;
	int health = 100;
	int points = 0;
	Publisher* publisher;
public:
	Player();
	friend std::ostream& operator<<(std::ostream &out, const Player &player);
	void up();
	void down();
	void right();
	void left();
	int getX();
	int getY();
	char getOldIcon();
	void printStat();
	void operator+=(Object& obj);
	int getPoints();
	~Player();
};

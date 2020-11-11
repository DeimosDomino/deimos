#pragma once


class Player;

class InteractionStrategy{
public:
	InteractionStrategy(){};
	friend class Player;
	virtual void interaction(Player& player)=0;
	~InteractionStrategy(){};

};

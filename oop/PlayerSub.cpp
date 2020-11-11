#include "PlayerSub.h"

PlayerSub::PlayerSub(Player* player){
	this->logger = new PlayerLogger(player);
}

void PlayerSub::update(){
	this->logger->log();
}

PlayerSub::~PlayerSub(){
	delete this->logger;
	
}



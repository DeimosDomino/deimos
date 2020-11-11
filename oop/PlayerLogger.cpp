#include "PlayerLogger.h"


PlayerLogger::PlayerLogger(Player* player){
	this->file.open("log.txt");
	this->player = player;

}

void PlayerLogger::log(){
	this->file << *(this->player) << std::endl;
}

PlayerLogger::~PlayerLogger(){
	if(this->file.is_open()){
		this->file.close();
	}
}

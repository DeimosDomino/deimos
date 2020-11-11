#include "Player.h"
#include "PlayerLogger.h"

Player::Player(){
	this->icon = '*';
	for(FieldIter it(Field::getInstance());it.isDone();it++){
        if((*it).isEntrance()){
    		this->oldIcon = (*it).getIcon();
			(*it).setIcon(this->icon);
			this->x = it.getX();
			this->y = it.getY();
			break;
		}
	}
	this->publisher = new Publisher();
	this->publisher->subscribe(new PlayerSub(this));
	
}



void Player::up(){
	PlayerLogger logger(this);
	if(y > 0 && Field::getInstance()->getField()[this->y-1][this->x].getIcon() != '0'){
		Field::getInstance()->getField()[this->y][this->x].setIcon(this->oldIcon);
		this->y--;
		this->oldIcon = Field::getInstance()->getField()[this->y][this->x].getIcon();
		Field::getInstance()->getField()[this->y][this->x].setIcon(this->icon);
		if(Field::getInstance()->getField()[this->y][this->x].getObject() != nullptr){
            *this += *Field::getInstance()->getField()[this->y][this->x].getObject();
			delete Field::getInstance()->getField()[this->y][this->x].getObject();
			Field::getInstance()->getField()[this->y][this->x].setObject(nullptr);
        }
	}
}

void Player::down(){
	if(y < Field::getInstance()->getY()-1 && Field::getInstance()->getField()[this->y+1][this->x].getIcon() != '0'){
		Field::getInstance()->getField()[this->y][this->x].setIcon(this->oldIcon);
    	this->y++;
	    this->oldIcon = Field::getInstance()->getField()[this->y][this->x].getIcon();
    	Field::getInstance()->getField()[this->y][this->x].setIcon(this->icon);
		if(Field::getInstance()->getField()[this->y][this->x].getObject() != nullptr){
            *this += *Field::getInstance()->getField()[this->y][this->x].getObject();
        	delete Field::getInstance()->getField()[this->y][this->x].getObject();
			Field::getInstance()->getField()[this->y][this->x].setObject(nullptr);
		}
	}
}

void Player::right(){
	if(x < Field::getInstance()->getX()-1 && Field::getInstance()->getField()[this->y][this->x+1].getIcon() != '0'){	
		if(Field::getInstance()->getField()[this->y][this->x+1].getObject() != nullptr){
        	*this += *Field::getInstance()->getField()[this->y][this->x+1].getObject();
    	}
		Field::getInstance()->getField()[this->y][this->x].setIcon(this->oldIcon);
	    this->x++;
    	this->oldIcon = Field::getInstance()->getField()[this->y][this->x].getIcon();
   	 	Field::getInstance()->getField()[this->y][this->x].setIcon(this->icon);
		if(Field::getInstance()->getField()[this->y][this->x].getObject() != nullptr){
            *this += *Field::getInstance()->getField()[this->y][this->x].getObject();
        	delete Field::getInstance()->getField()[this->y][this->x].getObject();
			Field::getInstance()->getField()[this->y][this->x].setObject(nullptr);
		}
	}
}

void Player::left(){
	if(x > 0 && Field::getInstance()->getField()[this->y][this->x-1].getIcon() != '0'){
		Field::getInstance()->getField()[this->y][this->x].setIcon(this->oldIcon);
    	this->x--;
	    this->oldIcon = Field::getInstance()->getField()[this->y][this->x].getIcon();
    	Field::getInstance()->getField()[this->y][this->x].setIcon(this->icon);
		if(Field::getInstance()->getField()[this->y][this->x].getObject() != nullptr){
            *this += *Field::getInstance()->getField()[this->y][this->x].getObject();
        	delete Field::getInstance()->getField()[this->y][this->x].getObject();
			Field::getInstance()->getField()[this->y][this->x].setObject(nullptr);
		}
	}
}

int Player::getX(){
	return this->x;
}

int Player::getY(){
    return this->y;
}

int Player::getPoints(){
	return this->points;
}

void Player::printStat(){
	std::cout << "Score:" << this->points <<  "   Health:" << this->health << '\n';
}

void Player::operator+=(Object& obj){
	obj.interaction(*this);
}

std::ostream& operator<<(std::ostream &out, const Player &player){
	out << "The Player is located at x:" << player.x << " y:" << player.y << ", has " << player.health << " hp and " << player.points << " points\n";
	return out;
}

Player::~Player(){
	this->publisher->notify();
	delete this->publisher;	
}
	

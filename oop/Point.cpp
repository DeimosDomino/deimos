#include "Point.h"

Point::Point(){
	this->icon = 'O';
	this->strat = new PointIStrategy;
}

void Point::interaction(Player& player){
	this->strat->interaction(player);
}

char Point::getIcon(){
	return this->icon;
}

Point::~Point(){
	delete this->strat;	
}

std::ostream& operator<<(std::ostream &out, const Point &point){
	out << "The point is exists\n";
	return out;
}

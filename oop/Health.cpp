#include "Health.h"

Health::Health(){
    this->icon = '+';
	this->strat = new HealthIStrategy;
}

char Health::getIcon(){
	return this->icon;
}

void Health::interaction(Player& player){
	this->strat->interaction(player);
}

Health::~Health(){
	delete this->strat;	
}


std::ostream& operator<<(std::ostream &out, const Health &health){
    out << "The health is exists\n";
    return out;
}

#include "Poison.h"

Poison::Poison(){
    this->icon = '-';
	this->strat = new PoisonIStrategy;
}

char Poison::getIcon(){
	return this->icon;
}

void Poison::interaction(Player& player){
	this->strat->interaction(player);
}

Poison::~Poison(){
	delete strat;	
}

std::ostream& operator<<(std::ostream &out, const Poison &poison){
    out << "The poison is exists\n";
    return out;
}

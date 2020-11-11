#include "PoisonIStrategy.h"

void PoisonIStrategy::interaction(Player& player){
	player.health -= 10;
}

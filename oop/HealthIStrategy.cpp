#include "HealthIStrategy.h"

void HealthIStrategy::interaction(Player& player){
	if(player.health <= 90)
        player.health += 10;
    if(player.health > 90 && player.health < 100)
        player.health = 100;
}

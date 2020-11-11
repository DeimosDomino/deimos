#include <iostream>
#include "Player.h"
#include "Field.h"
#include "FieldIter.h"
#include "simpleObjectFactory.h"
#include "Publisher.h"

void makeObjects(objectFactory* factory, Field& fld){
    fld.spawnObject(factory->createPoint());
    
	fld.spawnObject(factory->createPoison());
    
	fld.spawnObject(factory->createHealth());
}



int main(){
    Field::getInstance(20,20);
	Player player;
	simpleObjectFactory factory;
	makeObjects(&factory,*Field::getInstance());
	Field::getInstance() -> printField();
	player.printStat();
	char c = std::cin.get();
	while(c != 'q'){
		switch(c){
			case 'w':
				player.up();
				break;
			case 's':
				player.down();
				break;
			case 'd':
				player.right();
				break;
			case 'a':
				player.left();
				break;
			default:
				break;
		}
		system("clear");
		if(Field::getInstance()->getField()[player.getY()][player.getX()].isExit() || player.getPoints() == 10){
			std::cout << "You won\n";
			break;
		}
		Field::getInstance()->printField();
		player.printStat();
		c = std::cin.get();
		
	}
	return 0;
}

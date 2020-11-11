#include "simpleObjectFactory.h"

Point* simpleObjectFactory::createPoint(){
	return new Point;
}

Poison* simpleObjectFactory::createPoison(){
	return new Poison;
}

Health* simpleObjectFactory::createHealth(){
	return new Health;
}

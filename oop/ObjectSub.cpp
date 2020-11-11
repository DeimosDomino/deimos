#include "ObjectSub.h"


ObjectSub::ObjectSub(Object* obj){
	this->logger = new ObjectLogger(obj);
}

void ObjectSub::update(){
	this->logger->log();
}

ObjectSub::~ObjectSub(){
	delete this->logger;
}



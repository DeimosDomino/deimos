#include "ObjectLogger.h"

ObjectLogger::ObjectLogger(Object* obj){
	this->file.open("log.txt");
	this->obj = obj;
}

void ObjectLogger::log(){
	this->file << this->obj;
}

ObjectLogger::~ObjectLogger(){
	if(this->file.is_open())
		this->file.close();
}

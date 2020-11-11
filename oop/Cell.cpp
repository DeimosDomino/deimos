#include "Cell.h"

Cell::Cell(){
	this->icon = ' ';
    this->pass = true;
}
void Cell::setIcon(char icon){
	this->icon = icon;	
}

Cell& Cell::operator=(const Cell &cell){
	icon = cell.icon;
    pass = cell.pass;
    return *this;
}
char Cell::getIcon(){
	return this->icon;
}

void Cell::setExit(){
	this->icon = '#';
	this->Exit = true;
}

void Cell::setEntrance(){
	this->icon = '%';
	this->Entrance = true;
}

void Cell::setBar(){
	this->icon = '0';
	this->pass = false;
}

bool Cell::isEntrance(){
	return this->Entrance;
}

bool Cell::isExit(){
	return this->Exit;
}

void Cell::setObject(Object* object){
	this->obj = object;
}

Object* Cell::getObject(){
	return this->obj;
}

Cell::~Cell(){
	if(this->obj != nullptr)
		delete this->obj;
}




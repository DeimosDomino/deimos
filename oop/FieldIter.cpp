#include "FieldIter.h"

FieldIter::FieldIter(Field* fld):fld(fld)
{
	this->indexX = 0;
	this->indexY = 0;
}

FieldIter::FieldIter(const FieldIter &it):fld(it.fld), indexY(it.indexY), indexX(it.indexX){}

Cell& FieldIter::operator*() const{
	return this->fld->myField[indexY][indexX];
}

FieldIter& FieldIter::operator++(){
	next();
}

FieldIter& FieldIter::operator++(int none){
	next();
}
void FieldIter::next(){
	if(this->indexX == this->fld->x - 1){
		this->indexY++;
		this->indexX = 0;
	}else{
		this->indexX++;
	}
}

bool FieldIter::isDone(){
	if((this->indexX == 0)  && (this->indexY == this->fld->y)){
		return false;
	}else{
		return true;
	}
}

int FieldIter::getX(){
	return this->indexX;
}
int FieldIter::getY(){
	return this->indexY;
}

FieldIter::~FieldIter(){}


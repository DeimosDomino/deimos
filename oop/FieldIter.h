#pragma once
#include "Field.h"

class Cell;
class Field;

class FieldIter{

	friend class Field;	
private:
	int indexY, indexX;
	Field* fld;	
public:
	FieldIter(Field* fld);
	FieldIter(const FieldIter &it);
	void next();
	bool isDone();
	Cell& operator*() const;
	FieldIter& operator++();
	FieldIter& operator++(int none);
	int getX();
	int getY();
	~FieldIter();
};




#pragma once
#include <iostream>
#include <cstdlib>
#include "Cell.h"
#include "FieldIter.h"

class Object;

class Field{
	friend class FieldIter;    
	friend class Object;
    private:
    
	Cell** myField;
    	
	int x,y;	

	Field(int x, int y);
    	
	Field(const Field &fld);
    
	Field(Field &&fld);
	public:
	
	static Field* getInstance(int x = 0, int y = 0);
	
	
	Field& operator= (const Field &fld);
	Field& operator= (Field &&fld);

	int getX() const;
	int getY() const;
	
	void printField();	
 	
	void spawnObject(Object* obj);

	Cell**& getField();
	
	~Field();
};



#pragma once
#include <string>
#include <iostream>
#include "Object.h"


class Cell{
	
protected:
	
	bool Entrance = false;

	bool Exit = false;

    char icon;
    
    bool pass;

	Object* obj = nullptr;

public:

	
	Cell();
    
    void setIcon(char icon);
    
    Cell& operator=(const Cell &cell);
    
    char getIcon();	

	void setExit();
		
	void setEntrance();
	
	void setBar();

	bool isEntrance();

	bool isExit();
	
	Object* getObject();

	void setObject(Object* obj);

	~Cell();
};


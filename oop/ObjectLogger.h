#pragma once
#include "Logger.h"
#include <fstream>

class Object;

class ObjectLogger: public Logger{
private:
	std::ofstream file;
	Object* obj;
public:
	ObjectLogger(Object* obj);
	void log();
	~ObjectLogger();	
};

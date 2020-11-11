#pragma once
#include <vector>
#include <iterator>
#include "Sub.h"


class Publisher{
private:
	std::vector<Sub*> subs;
public:
	friend class Sub;
	Publisher();
	void notify();
	void subscribe(Sub* sub);
	void unsubscribe(Sub* sub);
	~Publisher();
};

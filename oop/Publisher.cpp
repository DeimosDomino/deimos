#include "Publisher.h"
#include <iostream>

Publisher::Publisher(){
}

void Publisher::subscribe(Sub* sub){
	this->subs.push_back(sub);
}


void Publisher::unsubscribe(Sub* sub){
	for(int i = 0;i<this->subs.size();i++){
		if(subs[i] == sub){
			for(int j = i;j<this->subs.size()-1;j++){
				subs[j] = subs[j+1];
			}
			subs.pop_back();
			break;
		}
			
	}
}


void Publisher::notify(){
	for(int i = 0;i<this->subs.size();i++){
			subs[i]->update();
	}
}


Publisher::~Publisher(){
	for(int i=0;i<this->subs.size();i++){
		delete subs[i];
	}
}

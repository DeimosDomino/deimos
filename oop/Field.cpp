#include "Field.h"

Field::Field(int x, int y){
	this->x = x;
	this->y = y;
    myField = new Cell*[y];
	for(int i = 0;i < y;i++){
		myField[i] = new Cell[x];
	}
	
	myField[0][0].setBar();
	myField[0][1].setBar();
	myField[0][x-1].setBar();
	myField[0][x-2].setBar();
	myField[1][0].setBar();
	myField[1][x-1].setBar();
	myField[y-2][0].setBar();
	myField[y-2][x-1].setBar();
	myField[y-1][x-2].setBar();
	myField[y-1][x-1].setBar();
	myField[y-1][0].setBar();
	myField[y-1][1].setBar();
	this->myField[0][this->x/2].setExit();
    this->myField[this->y-1][this->x/2].setEntrance();
}
    
Field* Field::getInstance(int x, int y){
    static Field instance(x,y);
    return &instance;
}

Field::Field(const Field &fld){
	this->myField = new Cell*[fld.getY()];
	for(int i = 0;i < fld.getY();i++){
		this->myField[i] = new Cell[fld.getX()];
		for(int j = 0;j < fld.getX();j++){
			this->myField[i][j] = fld.myField[i][j];
		}
	}
}

Field::Field(Field&& fld){
	this->myField = fld.myField;
	this->x = fld.x;
	this->y = fld.y;
	fld.myField = nullptr;
	fld.x = 0;
	fld.y = 0;
}

Field& Field::operator= (const Field &fld){
	
	for(int i = 0;i < fld.getY();i++){
		delete[] this->myField[i];
	}
	delete[] this->myField;

	this->myField = new Cell*[fld.getY()];
	for(int i = 0;i < fld.getY();i++){
        this->myField[i] = new Cell[fld.getX()];
        for(int j = 0;j < fld.getX();j++){
            this->myField[i][j] = fld.myField[i][j];
        }
    }
	return *this;
}

Field& Field::operator= (Field &&fld){
	for(int i = 0;i < fld.getY();i++){
        delete[] this->myField[i];
    }
    delete[] this->myField;
   	for(FieldIter it(&fld);it.isDone();it++){
		this->myField[it.indexY][it.indexX] = *it;
    }
	fld.myField = nullptr;
	fld.x = 0;
	fld.y = 0;
	return *this;
}
void Field::printField(){
    int oldY = 0;
	int n = 50;
	for(int i=0;i<5;i++)
		std::cout << '\n';
	for(int i=0;i<n;i++)
    	std::cout << ' ';
	for(FieldIter it(this);it.isDone();it++){
		if(it.indexY > oldY){
			std::cout << '\n';
			for(int i=0;i<n;i++)
				std::cout << ' ';
		}
		oldY = it.indexY;
		if((*it).getObject() == nullptr){
			std::cout << (*it).getIcon();
		}else{
			std::cout << (*it).getObject()->getIcon();
		}
		std::cout << ' ';
	}
	std::cout << '\n';
	for(int i=0;i<n;i++)
        std::cout << ' ';
}
    
int Field::getX() const{
	return this->x;
}
	
int Field::getY() const{
	return this->y;
}

Cell**& Field::getField(){
	return this->myField;
}

void Field::spawnObject(Object* obj){
	srand(time(NULL));
	int x1 = rand() % this->x;
	int y1 = rand() % this->y;
	while(this->myField[y1][x1].getIcon() == '0' || this->myField[y1][x1].getObject() != nullptr){
		x1 = rand()%this->x;
		y1 = rand()%this->y;
	}
	this->myField[y1][x1].setObject(obj);
}
 	
Field::~Field(){
	for(int i = 0;i < this->x;i++){
		delete[] myField[i];
	}
	delete[] myField;	
}
 


all: lab

lab: main.o Cell.o Field.o FieldIter.o Player.o Point.o Poison.o Health.o simpleObjectFactory.o HealthIStrategy.o PointIStrategy.o PoisonIStrategy.o Publisher.o PlayerLogger.o PlayerSub.o ObjectLogger.o ObjectSub.o 
	g++ main.o Cell.o Field.o FieldIter.o Player.o Point.o Poison.o Health.o simpleObjectFactory.o HealthIStrategy.o PointIStrategy.o PoisonIStrategy.o Publisher.o PlayerLogger.o PlayerSub.o ObjectLogger.o ObjectSub.o -o lab

main.o: main.cpp 
	g++ -c main.cpp
    
Cell.o: Cell.cpp
	g++ -c Cell.cpp
    
Field.o: Field.cpp
	g++ -c Field.cpp

FieldIter.o: FieldIter.cpp
	g++ -c FieldIter.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Point.o: Point.cpp
	g++ -c Point.cpp

Poison.o: Poison.cpp
	g++ -c Poison.cpp

Health.o: Health.cpp
	g++ -c Health.cpp

simpleObjectFactory.o: simpleObjectFactory.cpp
	g++ -c simpleObjectFactory.cpp

HealthIStrategy.o: HealthIStrategy.cpp
	g++ -c HealthIStrategy.cpp

PointIStrategy.o: PointIStrategy.cpp
	g++ -c PointIStrategy.cpp

PoisonIStrategy.o: PoisonIStrategy.cpp
	g++ -c PoisonIStrategy.cpp

Publisher.o: Publisher.cpp
	g++ -c Publisher.cpp

PlayerLogger.o: PlayerLogger.cpp
	g++ -c PlayerLogger.cpp

ObjectLogger.o: ObjectLogger.cpp
	g++ -c ObjectLogger.cpp

PlayerSub.o: PlayerSub.cpp
	g++ -c PlayerSub.cpp

ObjectSub.o: ObjectSub.cpp
	g++ -c ObjectSub.cpp

clean:
	rm -rf *.o lab 

#include "Sub.h"
#include <string>
#include "ObjectLogger.h"

class ObjectSub: public Sub{
private:
	Logger* logger;
public:
	ObjectSub(Object* obj);
	void update();
	~ObjectSub();
};

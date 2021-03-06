#ifndef COMPONENT_H
#define COMPONENT_H

#include "Definitions.h"
#include "Initializers.h"

class Object;
class Component
{
public:
	//Todo::Josh::add move constructor, copy constructor, and = move constructor to this and its children!
	Component(Object* owner);
	Component() = delete;
	~Component();

	Object* getOwner() const;

	virtual Object* update()=0;
	
protected:
	Object * owner{ nullptr };
	
};


#endif
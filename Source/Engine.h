#ifndef ENGINE_H
#define ENGINE_H

#include "Definitions.h"
#include "Object.h"
#include "ResourceManager.h"

class Engine{
public:	
	~Engine();
	bool initialize();
	void reset();
	bool run();

private:	
	std::unique_ptr<ResourceManager> engineDevices{ nullptr };
	std::unique_ptr<ResourceManager> gameDevices{ nullptr };	
};


#endif
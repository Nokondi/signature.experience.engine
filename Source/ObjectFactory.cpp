#include <memory>
#include "ObjectFactory.h"
#include "Component.h"
//#include "ComponentsList.h"
#include "View.h"
//#include "ResourceManager.h"
#include "Texture.h"
#include "Object.h"
//#include "AssetLibrary.h"

//************************************************
//ALL ITEMS IN "presets" need to be set.
//based on the object type, it grabs components.
// and adds them to a newly created object.
//it initializes the object which also initializes all the components
Object* ObjectFactory::Create(ObjectFactory::ObjectFactoryPresets& presets)
//**************************************
{

	//Create pointer to new objects
	Object* newObject = new Object();
	//get list of components for the new object
	//std::vector<Component*> componentList = presets.devices -> getAssetLibrary() ->getComponents(presets.objectType, newObject);
	//Add each to the object
	//for (auto comp : componentList)
	//{
	//	newObject -> AddComponent(comp);
	//}

	//the object can be walked over if this is not empty.
	//if(!presets.gDirection.empty())
	//{
	//	//add the ghost component
	//	GhostComponent* ghost = new GhostComponent(newObject);
	//	newObject -> AddComponent(ghost);
	//}
		
	//initialize the new object (this will also initialize components)
	if (newObject -> initialize(presets))
	{
		//return the created and initialized object.
		return newObject;
	}
	else
	{
		delete newObject;
		std::cout << "Object did not initialize!" << std::endl;
		return nullptr;
	}
}

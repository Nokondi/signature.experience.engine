#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <map>
#include <memory>
#include <variant>


#include "InputDevice.h"

class Listner;
class IEventTrigger;
class EventHandler
{
public:
	
	EventHandler();
	~EventHandler();
	enum class Event{
		CreateObject, 
		Notification, 
		SoundEffect, 
		UserInput,
		AdjustView,
		NumEvents};
	//Hack:: int is just to have a null version..
	using EventData = std::variant<int, Vector2D, EventHandler::Event, IEventTrigger*, const InputDevice::UserInputs*>;
	void notify(Event event, EventData data);
	Listner* getListner(Event event);
private:
	void addListner(Event event);
	void removeListner(Event event);
	
	std::map<Event, std::unique_ptr<Listner>> listners;

};
#endif // !EVENTHANDLER_H

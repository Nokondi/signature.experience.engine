#include "SpriteComponent.h"
#include "BodyComponent.h"
#include "Texture.h"
#include "AssetLibrary.h"
#include "View.h"
#include "ResourceManager.h"
#include "PhysicsDevice.h"
#include "GraphicsDevice.h"
#include "Object.h"
#include "Initializers.h"

SpriteComponent::SpriteComponent(Object* owner, const SpritePresets& presets):Component(owner)
{
	this->devices = presets.Devices;
	this->texture = presets.spriteTexture;
	//initialized = (devices && texture);
}

SpriteComponent::SpriteComponent(Object * owner, ResourceManager * devices, tinyxml2::XMLElement * componentElement):Component(owner), devices(devices)
{
	bool isSprite{ false };
	componentElement->QueryBoolAttribute("sprite", &isSprite);
	if (isSprite)
	{
		texture = devices->assetLibrary->getArtAsset(componentElement->Attribute("asset"));
	}
	else
	{
		texture = new Texture(devices->gDevice.get(), componentElement->Attribute("text"), false);
	}
}

SpriteComponent::~SpriteComponent()
{
	if (sprite)
	{
		sprite->~SpriteComponent();
	}
}

//**************************************
// updates the position based on the view and draws the sprite
void SpriteComponent::draw()
//**************************************
{
	Vector2D updatedPosition;	

	//adjust position.
	updatedPosition = getViewAdjustedPosition();

	auto angle = devices -> pDevice -> getAngle(owner->getComponent<BodyComponent>());

	//draw sprite.
	draw(updatedPosition, angle);
	if (sprite)
	{
		sprite->draw();
	}
}

void SpriteComponent::draw(Vector2D position, eFloat angle)
{
	texture ->draw(devices -> gDevice -> getRenderer(), position, angle, NULL);
}



Object* SpriteComponent::update(){return nullptr;}

//**************************************
//adjusts the position based on the view.
Vector2D SpriteComponent::getViewAdjustedPosition()
//**************************************
{	
	//adjust position.
	return (devices->pDevice->getPosition(spriteBody) 
		+ devices->gDevice->getView()->position);
}


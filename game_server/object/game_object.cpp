#include "object/game_object.h"

#include "unit/unit.h"

#include "map/map.h"

namespace game_server {

using namespace common;

GameObject::GameObject(uint64 id, uint8 object_type_id)
	: ObjectBase(id, object_type_id)
{
	this->setObjectTypeMask(this->getObjectTypeMask() | ObjectTypeMask_GameObject);
}

GameObject::~GameObject()
{
}

void GameObject::setX(int32 x)
{
	this->position_.setX(x);
}

int32 GameObject::getX() const
{
	return this->position_.getX();
}

void GameObject::setY(int32 y)
{
	this->position_.setY(y);
}

int32 GameObject::getY() const
{
	return this->position_.getY();
}

void GameObject::setPosition(int32 x, int32 y)
{
	this->position_.setPosition(x, y);
}

void GameObject::getPosition(int32 &x, int32 &y)
{
	this->position_.getPosition(x, y);
}

void GameObject::setOwner(UnitPtr owner)
{
	this->owner_ = owner;
}

UnitPtr GameObject::getOwner()
{
	return this->owner_;
}

const UnitPtr GameObject::getOwner() const
{
	return (const_cast<GameObject *>(static_cast<const GameObject *>(this)))->getOwner();
}

void GameObject::GameObject::setMap(MapBasePtr map)
{
	this->map_ = map;
}

MapBasePtr GameObject::getMap()
{
	return this->map_;
}

const MapBasePtr GameObject::getMap() const
{
	return (const_cast<GameObject *>(static_cast<const GameObject *>(this)))->getMap();
}

} // namespace game_server
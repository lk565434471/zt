#pragma once

#include "entity/object_base.h"

#include "util/vector2d.h"

namespace game_server {

using common::ObjectBase;

using util::Vector2D;

class Unit;
using UnitPtr = std::shared_ptr<Unit>;

class MapBase;
using MapBasePtr = std::shared_ptr<MapBase>;

class GameObject
	: public std::enable_shared_from_this<GameObject>
	, public ObjectBase
{
public:

	GameObject(uint64 id, uint8 object_type_id = common::ObjectTypeId_GameObject);

	virtual ~GameObject();

public:

	void setX(int32 x);
	int32 getX() const;
	void setY(int32 y);
	int32 getY() const;
	void setPosition(int32 x, int32 y);
	void getPosition(int32 &x, int32 &y);

	void setOwner(UnitPtr owner);
	UnitPtr getOwner();
	const UnitPtr getOwner() const;

	void setMap(MapBasePtr map);
	MapBasePtr getMap();
	const MapBasePtr getMap() const;

private:

	UnitPtr owner_;

	MapBasePtr map_;

	Vector2D position_;

};

using GameObjectPtr = std::shared_ptr<GameObject>;

} // namespace game_server
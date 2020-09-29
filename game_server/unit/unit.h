#pragma once

#include "entity/object_base.h"

namespace game_server {

using common::ObjectBase;

class MapBase;
using MapBasePtr = std::shared_ptr<MapBase>;

class Unit
	: public std::enable_shared_from_this<Unit>
	, public ObjectBase
{
public:

	Unit(uint64 id, uint8 object_type_id = common::ObjectTypeId_Unit);

	virtual ~Unit();

private:

	MapBasePtr map_;
};

using UnitPtr = std::shared_ptr<Unit>;

} // namespace game_server
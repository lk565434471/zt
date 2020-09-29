#include "unit/unit.h"

namespace game_server {

using namespace common;

Unit::Unit(uint64 id, uint8 object_type_id)
	: ObjectBase(id, object_type_id)
{
	this->setObjectTypeMask(this->getObjectTypeMask() | ObjectTypeMask_Unit);
}

Unit::~Unit()
{
}

} // namespace game_server
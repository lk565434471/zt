#include "player/player.h"

#include "entity/object_guid.h"

namespace game_server {

using namespace common;

Player::Player(uint64 id)
	: Unit(id, ObjectTypeId_Player)
{
	this->setObjectTypeMask(this->getObjectTypeMask() | ObjectTypeMask_Player);
}

Player::~Player()
{
}

} // namespace game_server
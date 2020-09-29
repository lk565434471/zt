#pragma once

#include "unit/unit.h"

namespace game_server {

using common::ObjectBase;

class Player
	: public std::enable_shared_from_this<Player>
	, public Unit
{
public:

	Player(uint64 id);

	virtual ~Player();
};

using PlayerPtr = std::shared_ptr<Player>;

} // namespace game_server
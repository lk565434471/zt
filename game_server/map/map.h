#pragma once

#include "common.h"

namespace game_server {

class MapBase
	: public std::enable_shared_from_this<MapBase>
{
public:

	MapBase();

	virtual ~MapBase();
};

using MapBasePtr = std::shared_ptr<MapBase>;

} // namespace game_server
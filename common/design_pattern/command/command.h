#pragma once

#include "common.h"

namespace common {
namespace design_pattern {

template <typename RET = void>
class Command
{
public:

private:

	std::function<RET ()> func_;
};

} // namespace common
} // namespace design_pattern
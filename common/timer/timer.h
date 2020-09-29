#pragma once

#include "common.h"

#include "noncopyable/noncopyable.h"

#include <boost/asio/io_service.hpp>

namespace common {
namespace timer {

using boost::asio::io_service;
using boost::timer;

class Timer
	: public Noncopyable
{
public:

private:

	io_service *io_service_;
};

} // namespace timer
} // namespace common
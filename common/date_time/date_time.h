#pragma once

#include "common.h"

#include "noncopyable/noncopyable.h"

#include <boost/date_time/gregorian/gregorian.hpp>

namespace common {
namespace date_time {

using namespace boost::posix_time;

class DateTime
	: public Noncopyable
{
public:

public:

	bool isLeapYear();

	static bool isLeapYear(int16 year);

private:

	date date_;
};

} // namespace common
} // date_time
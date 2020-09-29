#pragma once

#include "common.h"

#include "noncopyable/noncopyable.h"

#include <boost/asio.hpp>

namespace common {
namespace network {

using namespace boost::asio;

class NetService
	: public NonCopyable
{
public:

	using acceptor_type = 

	~NetService();

public:

	void listen(uint8 server_type, const std::string &ip, uint16 port);

	void connect();

private:

	io_service io_service_;
};

} // namespace common
} // namespace network
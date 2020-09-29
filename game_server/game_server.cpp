#include "game_server.h"

#include "common.h"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/random_device.hpp>
#include <boost/any.hpp>

#include <iostream>

namespace game_server {

GameServer::GameServer()
{
}

GameServer::~GameServer()
{
}

} // namespace game_server


int main(int argc, char *argv[])
{
	boost::any a1 = 10;
	boost::any a2 = "hello";
	boost::any a3 = std::string("world");

	const char *s1 = boost::any_cast<const char *>(a2);

	std::cout << s1 << std::endl;

	return 0;
}
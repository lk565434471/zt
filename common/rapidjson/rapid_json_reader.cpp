#include "rapidjson/rapid_json_reader.h"

#include "rapidjson-1.1.0/include/rapidjson/pointer.h"

namespace common {
namespace json {

RapidJsonReader::RapidJsonReader()
	: RapidJsonValue("", &this->document_)
{
}

RapidJsonReader::~RapidJsonReader()
{
}

bool RapidJsonReader::load(const std::string &path)
{
	return true;
}

bool RapidJsonReader::parse(const std::string &data)
{
	this->document_.Parse(data.c_str());

	if (this->document_.HasParseError())
	{
		return false;
	}

	return true;
}

} // namespace json
} // namespace common
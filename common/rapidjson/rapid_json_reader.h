#pragma once

#include "common.h"

#include "rapidjson/rapid_json_value.h"

#include "rapidjson-1.1.0/include/rapidjson/document.h"
#include "rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#include "rapidjson-1.1.0/include/rapidjson/allocators.h"
#include "rapidjson-1.1.0/include/rapidjson/prettywriter.h"
#include "rapidjson-1.1.0/include/rapidjson/stringbuffer.h"
#include "rapidjson-1.1.0/include/rapidjson/reader.h"
#include "rapidjson-1.1.0/include/rapidjson/filewritestream.h"

namespace common {
namespace json {

class RapidJsonReader
	: public RapidJsonValue
{
public:

	RapidJsonReader();

	~RapidJsonReader();

public:

	bool load(const std::string &path);
	bool parse(const std::string &data);

private:

	rapidjson::Document document_;
};

} // namespace json
} // namespace common
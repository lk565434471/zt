#pragma once

#include "common.h"

#include "rapidjson/rapid_json_node.h"

#include "rapidjson-1.1.0/include/rapidjson/document.h"
#include "rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#include "rapidjson-1.1.0/include/rapidjson/allocators.h"
#include "rapidjson-1.1.0/include/rapidjson/document.h"
#include "rapidjson-1.1.0/include/rapidjson/prettywriter.h"
#include "rapidjson-1.1.0/include/rapidjson/stringbuffer.h"
#include "rapidjson-1.1.0/include/rapidjson/reader.h"
#include "rapidjson-1.1.0/include/rapidjson/filewritestream.h"

namespace common {
namespace json {

class RapidJsonWriter
	: public RapidJsonNode
{
public:

	RapidJsonWriter(rapidjson::Type type = rapidjson::kObjectType);

	~RapidJsonWriter();

public:

	template <typename T>
	RapidJsonWriter &write(const rapidjson::Value::Ch *key, const T &value = T());

	const std::string stringify();

private:

	rapidjson::Document::AllocatorType allocator_;
};

template <typename T>
RapidJsonWriter &RapidJsonWriter::write(const rapidjson::Value::Ch *key, const T &value/* = T()*/)
{
	if (RapidJsonNode::currNode_->isObject())
	{
		RapidJsonNode::currNode_->addMember(key, value);
	}
	else if (RapidJsonNode::currNode_->isArray())
	{
		RapidJsonNode::currNode_->pushBack(value);
	}

	return *this;
}

} // namespace json
} // namespace common
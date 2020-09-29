#include "rapidjson/rapid_json_writer.h"

#include "rapidjson-1.1.0/include/rapidjson/pointer.h"

namespace common {
namespace json {

RapidJsonWriter::RapidJsonWriter(rapidjson::Type type)
	: RapidJsonNode("", this->allocator_, type)
{
	RapidJsonNode::currNode_ = this;
	RapidJsonNode::rootNode_ = this;
}

RapidJsonWriter::~RapidJsonWriter()
{
}

const std::string RapidJsonWriter::stringify()
{
	rapidjson::StringBuffer sb;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
	RapidJsonNode::rootNode_->accept(writer);

	return sb.GetString();
}

} // namespace json
} // namespace common
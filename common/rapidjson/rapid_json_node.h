#pragma once

#include "common.h"

#include "rapidjson-1.1.0/include/rapidjson/document.h"
#include "rapidjson-1.1.0/include/rapidjson/prettywriter.h"
#include "rapidjson-1.1.0/include/rapidjson/stringbuffer.h"

namespace common {
namespace json {

using RapidJsonValueSharedPtr = std::shared_ptr<rapidjson::Value>;

class RapidJsonNode
{
public:

	RapidJsonNode(const std::string &key, rapidjson::Document::AllocatorType &alloc, rapidjson::Type type = rapidjson::kObjectType);
	RapidJsonNode(const RapidJsonNode &rhs);
	RapidJsonNode(const RapidJsonNode &&rhs);

	~RapidJsonNode();

public:

	bool isArray();
	bool isObject();

	template <typename T>
	void addMember(const rapidjson::Value::Ch *key, const T &value = T());
	void addMember(const rapidjson::Value::Ch *key, rapidjson::Value *value);
	void addMember(rapidjson::Value *key, rapidjson::Value *value);

	template <typename T>
	void pushBack(const T &value = T());
	void pushBack(rapidjson::Value *value);

	void beginArrayNode(const std::string &key);
	void beginObjectNode(const std::string &key);
	void endNode();

	void accept(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer);

protected:

	rapidjson::Value *getkey();
	rapidjson::Value *getValue();

private:

	void init(rapidjson::Type type);

protected:

	rapidjson::Document::AllocatorType &allocator_;
	RapidJsonValueSharedPtr key_;
	RapidJsonValueSharedPtr value_;
	static RapidJsonNode *rootNode_;
	static RapidJsonNode *currNode_;
	std::deque<RapidJsonNode *> nodes_;
};

template <typename T>
void RapidJsonNode::addMember(const rapidjson::Value::Ch *key, const T &value)
{
	this->value_->AddMember(rapidjson::Value(key, this->allocator_), value, this->allocator_);
}

template <typename T>
void RapidJsonNode::pushBack(const T &value)
{
	this->value_->PushBack(rapidjson::Value(value), this->allocator_);
}

} // namespace json
} // namespace common
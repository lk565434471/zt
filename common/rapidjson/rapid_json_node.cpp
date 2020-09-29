#include "rapidjson/rapid_json_node.h"

namespace common {
namespace json {

RapidJsonNode *RapidJsonNode::rootNode_ = nullptr;
RapidJsonNode *RapidJsonNode::currNode_ = nullptr;

RapidJsonNode::RapidJsonNode(const std::string &key, rapidjson::Document::AllocatorType &alloc
	, rapidjson::Type type)
	: allocator_(alloc), key_(new rapidjson::Value(key.c_str(), this->allocator_))
{
	this->init(type);
}

RapidJsonNode::RapidJsonNode(const RapidJsonNode &rhs)
	: allocator_(rhs.allocator_), key_(rhs.key_), value_(rhs.value_)
{
}

RapidJsonNode::RapidJsonNode(const RapidJsonNode &&rhs)
	: allocator_(rhs.allocator_), key_(rhs.key_), value_(rhs.value_)
{
}

RapidJsonNode::~RapidJsonNode()
{
}

bool RapidJsonNode::isArray()
{
	return this->value_->IsArray();
}

bool RapidJsonNode::isObject()
{
	return this->value_->IsObject();
}

void RapidJsonNode::addMember(const rapidjson::Value::Ch *key, rapidjson::Value *value)
{
	this->value_->AddMember(rapidjson::Value(key, this->allocator_), *value, this->allocator_);
}

void RapidJsonNode::addMember(rapidjson::Value *key, rapidjson::Value *value)
{
	this->value_->AddMember(key->Move(), value->Move(), this->allocator_);
}

void RapidJsonNode::pushBack(rapidjson::Value *value)
{
	this->value_->PushBack(*value, this->allocator_);
}

void RapidJsonNode::beginArrayNode(const std::string &key)
{
	RapidJsonNode *oldNode = RapidJsonNode::currNode_;
	RapidJsonNode::currNode_ = new RapidJsonNode(key, this->allocator_, rapidjson::Type::kArrayType);
	this->nodes_.push_back(oldNode);
}

void RapidJsonNode::beginObjectNode(const std::string &key)
{
	RapidJsonNode *oldNode = RapidJsonNode::currNode_;
	RapidJsonNode::currNode_ = new RapidJsonNode(key, this->allocator_, rapidjson::Type::kObjectType);
	this->nodes_.push_back(oldNode);
}

void RapidJsonNode::endNode()
{
	if (this->nodes_.empty())
	{
		return;
	}

	RapidJsonNode *oldNode = RapidJsonNode::currNode_;
	RapidJsonNode::currNode_ = this->nodes_.back();
	this->nodes_.pop_back();

	if (RapidJsonNode::currNode_->isArray())
	{
		RapidJsonNode::currNode_->pushBack(oldNode->getValue());
	}
	else if (RapidJsonNode::currNode_->isObject())
	{
		RapidJsonNode::currNode_->addMember(oldNode->getkey(), oldNode->getValue());
	}
}

void RapidJsonNode::accept(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
	this->value_.get()->Accept(writer);
}

rapidjson::Value *RapidJsonNode::getkey()
{
	return this->key_.get();
}

rapidjson::Value *RapidJsonNode::getValue()
{
	return this->value_.get();
}

void RapidJsonNode::init(rapidjson::Type type)
{
	this->value_.reset(new rapidjson::Value());

	if (type == rapidjson::kObjectType)
	{
		this->value_->SetObject();
		return;
	}
	else if (type == rapidjson::kArrayType)
	{
		this->value_->SetArray();
		return;
	}
}

} // namespace json
} // namespace common
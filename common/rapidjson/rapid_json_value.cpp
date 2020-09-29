#include "rapidjson/rapid_json_value.h"

#include "rapidjson-1.1.0/include/rapidjson/pointer.h"

namespace common {
namespace json {

RapidJsonValue::RapidJsonValue(const std::string &key, rapidjson::Value *value /*= nullptr*/)
	: value_(value), count_(0), key_(key)
{
	this->parseValue();
}

RapidJsonValue::~RapidJsonValue()
{
}

bool RapidJsonValue::isValid() const
{
	return this->value_ != nullptr;
}

bool RapidJsonValue::isNull() const
{
	return this->isValid() && this->value_->IsNull();
}

bool RapidJsonValue::isFalse() const
{
	return this->isValid() && this->value_->IsFalse();
}

bool RapidJsonValue::isTrue() const
{
	return this->isValid() && this->value_->IsTrue();
}

bool RapidJsonValue::isBoolean() const
{
	return this->isValid() && this->value_->IsBool();
}

bool RapidJsonValue::isObject() const
{
	return this->isValid() && this->value_->IsObject();
}

bool RapidJsonValue::isArray() const
{
	return this->isValid() && this->value_->IsArray();
}

bool RapidJsonValue::isNumber() const
{
	return this->isValid() && this->value_->IsNumber();
}

bool RapidJsonValue::isInt32() const
{
	return this->isValid() && this->value_->IsInt();
}

bool RapidJsonValue::isUInt32() const
{
	return this->isValid() && this->value_->IsUint();
}

bool RapidJsonValue::isInt64() const
{
	return this->isValid() && this->value_->IsInt64();
}

bool RapidJsonValue::isUInt64() const
{
	return this->isValid() && this->value_->IsUint64();
}

bool RapidJsonValue::isDouble() const
{
	return this->isValid() && this->value_->IsDouble();
}

bool RapidJsonValue::isString() const
{
	return this->isValid() && this->value_->IsString();
}

const std::string RapidJsonValue::getKey() const
{
	return this->key_;
}

uint32 RapidJsonValue::getCount() const
{
	return this->count_;
}

int8 RapidJsonValue::getInt8() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return static_cast<int8>(this->value_->GetInt());
}

uint8 RapidJsonValue::getUInt8() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return static_cast<uint8>(this->value_->GetUint());
}

int16 RapidJsonValue::getInt16() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return static_cast<int16>(this->value_->GetInt());
}

uint16 RapidJsonValue::getUInt16() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return static_cast<uint16>(this->value_->GetUint());
}

int32 RapidJsonValue::getInt32() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return this->value_->GetInt();
}

uint32 RapidJsonValue::getUInt32() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return this->value_->GetUint();
}

int64 RapidJsonValue::getInt64() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return this->value_->GetInt64();
}

uint64 RapidJsonValue::getUInt64() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return this->value_->GetUint64();
}

float RapidJsonValue::getFloat() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return static_cast<float>(this->value_->GetFloat());
}

double RapidJsonValue::getDouble() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return this->value_->GetDouble();
}

std::string RapidJsonValue::getString() const
{
	if (!this->isValid())
	{
		return 0;
	}

	return this->value_->GetString();
}

bool RapidJsonValue::getBoolean() const
{
	if (this->isBoolean()) {
		return this->value_->GetBool();
	}

	if (this->isNumber()) {
		return this->getInt64() != 0;
	}

	return false;
}

RapidJsonValue RapidJsonValue::operator[](const std::string &source)
{
	static RapidJsonValue defaultValue("");

	if (!this->isValid() || !this->value_->IsObject() || source.empty())
	{
		return defaultValue;
	}

	if (source[0] == '/')
	{
		return RapidJsonValue(source, rapidjson::Pointer(source.c_str()).Get(*this->value_));
	}

	rapidjson::Document::MemberIterator it = this->value_->FindMember(source.c_str());

	if (it == this->value_->MemberEnd())
	{
		return defaultValue;
	}

	return RapidJsonValue(source, &it->value);
}

RapidJsonValue RapidJsonValue::operator[](const uint32 index)
{
	static RapidJsonValue defaultValue("");

	if (index >= this->getCount() || (!this->isArray() && !this->isObject()))
	{
		return defaultValue;
	}

	if (this->isArray())
	{
		return RapidJsonValue("", &(*this->value_)[index]);
	}

	rapidjson::Document::MemberIterator it = this->value_->MemberBegin();
	it += index;

	return RapidJsonValue(it->name.GetString(), &it->value);
}

void RapidJsonValue::parseValue()
{
	if (!this->isValid())
	{
		return;
	}

	if (this->isObject())
	{
		this->count_ = this->value_->MemberCount();
	}
	else if (this->isArray())
	{
		this->count_ = this->value_->Size();
	}
}

} // namespace json
} // namespace common
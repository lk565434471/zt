#pragma once

#include "common.h"

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

class RapidJsonValue
{
public:

	RapidJsonValue(const std::string &key, rapidjson::Value *value = nullptr);

	~RapidJsonValue();

public:

	bool isValid() const;
	bool isNull() const;
	bool isFalse() const;
	bool isTrue() const;
	bool isBoolean() const;
	bool isObject() const;
	bool isArray() const;
	bool isNumber() const;
	bool isInt32() const;
	bool isUInt32() const;
	bool isInt64() const;
	bool isUInt64() const;
	bool isDouble() const;
	bool isString() const;

public:

	const std::string getKey() const;
	uint32 getCount() const;
	int8 getInt8() const;
	uint8 getUInt8() const;
	int16 getInt16() const;
	uint16 getUInt16() const;
	int32 getInt32() const;
	uint32 getUInt32() const;
	int64 getInt64() const;
	uint64 getUInt64() const;
	float getFloat() const;
	double getDouble() const;
	std::string getString() const;
	bool getBoolean() const;

public:

	RapidJsonValue operator[](const std::string &source);
	RapidJsonValue operator[](const uint32 index);

private:

	void parseValue();

private:

	rapidjson::Value *value_;
	uint32 count_;
	std::string key_;
};

} // namespace json
} // namespace common
#pragma once

#include "common.h"

#include "entity/object_guid.h"

#include <boost/any.hpp>

namespace common {

using ObjectPropertyMap = std::map<uint16, boost::any>;

class ObjectBase
	: public std::enable_shared_from_this<ObjectBase>
{
public:

	ObjectBase(uint64 id, uint8 object_type_id = common::ObjectTypeId_Object);

	virtual ~ObjectBase();

public:

	uint8 getObjectTypeId() const;
	void setObjectTypeMask(uint16 object_type_mask);
	uint16 getObjectTypeMask() const;
	bool isObject(uint16 object_type_mask) const;
	void setObjectProperty(uint16 property_id, const boost::any &value);
	int32 getObjectPropertyByInt32(uint16 property_id) const;
	uint32 getObjectPropertyByUInt32(uint16 property_id) const;
	int64 getObjectPropertyByInt64(uint16 property_id) const;
	uint64 getObjectPropertyByUInt64(uint16 property_id) const;
	double getObjectPropertyByDouble(uint16 property_id) const;
	bool getObjectPropertyByBoolean(uint16 property_id) const;
	const std::string &getObjectPropertyByString(uint16 property_id) const;
	bool existsObjectProperty(uint16 property_id) const;

private:

	uint64 id_;
	uint8 object_type_id_;
	uint16 object_type_mask_;

	ObjectPropertyMap object_properties_;
};

using ObjectBasePtr = std::shared_ptr<ObjectBase>;

} // namespace common
#include "entity/object_base.h"

namespace common {

ObjectBase::ObjectBase(uint64 id, uint8 object_type_id)
	: id_(id), object_type_id_(object_type_id)
	, object_type_mask_(ObjectTypeMask_Object)
{
}

ObjectBase::~ObjectBase()
{
}

uint8 ObjectBase::getObjectTypeId() const
{
	return this->object_type_id_;
}

void ObjectBase::setObjectTypeMask(uint16 object_type_mask)
{
	this->object_type_mask_ = object_type_mask;
}

uint16 ObjectBase::getObjectTypeMask() const
{
	return this->object_type_mask_;
}

bool ObjectBase::isObject(uint16 object_type_mask) const
{
	return (this->getObjectTypeMask() & object_type_mask) != 0;
}

void ObjectBase::setObjectProperty(uint16 property_id, const boost::any &value)
{
	this->object_properties_[property_id] = value;
}

int32 ObjectBase::getObjectPropertyByInt32(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return 0;
	}

	return boost::any_cast<int32>(it->second);
}

uint32 ObjectBase::getObjectPropertyByUInt32(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return 0;
	}

	return boost::any_cast<uint32>(it->second);	
}

int64 ObjectBase::getObjectPropertyByInt64(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return 0;
	}

	return boost::any_cast<int64>(it->second);
}

uint64 ObjectBase::getObjectPropertyByUInt64(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return 0;
	}

	return boost::any_cast<uint64>(it->second);
}

double ObjectBase::getObjectPropertyByDouble(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return 0;
	}

	return boost::any_cast<double>(it->second);
}

bool ObjectBase::getObjectPropertyByBoolean(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return false;
	}

	return boost::any_cast<bool>(it->second);
}

const std::string &ObjectBase::getObjectPropertyByString(uint16 property_id) const
{
	const static std::string str;

	auto it = this->object_properties_.find(property_id);

	if (it == this->object_properties_.end()) {
		return str;
	}

	return boost::any_cast<const std::string &>(it->second);	
}

bool ObjectBase::existsObjectProperty(uint16 property_id) const
{
	auto it = this->object_properties_.find(property_id);

	return it != this->object_properties_.end();
}

} // namespace common
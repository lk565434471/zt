#pragma once

namespace common {

enum ObjectTypeId
{
	ObjectTypeId_None								= 0,
	ObjectTypeId_Object,
	ObjectTypeId_Item,
	ObjectTypeId_Container,
	ObjectTypeId_Unit,
	ObjectTypeId_GameObject,
	ObjectTypeId_DynamicObject,
	ObjectTypeId_Player,
	ObjectTypeId_Corpse,
	ObjectTypeId_Max,
};

enum ObjectTypeMask
{
	ObjectTypeMask_None								= 0x0000,
	ObjectTypeMask_Object							= 0x0001,
	ObjectTypeMask_Item								= 0x0002,
	ObjectTypeMask_Container						= 0x0004,
	ObjectTypeMask_Unit								= 0x0008,
	ObjectTypeMask_GameObject						= 0x0010,
	ObjectTypeMask_DynamicObject					= 0x0020,
	ObjectTypeMask_Player							= 0x0040,
	ObjectTypeMask_Corpse							= 0x0080,
};

} // namespace common
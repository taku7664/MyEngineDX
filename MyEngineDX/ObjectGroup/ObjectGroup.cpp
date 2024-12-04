#include "pch.h"
#include "ObjectGroup.h"

ObjectGroup::ObjectGroup()
{
}

ObjectGroup::ObjectGroup(std::wstring_view _name, std::wstring_view _tag)
	: Entity(_name, _tag)
{
}

ObjectGroup::~ObjectGroup()
{
}

#include "pch.h"
#include "ObjectGroup.h"


ObjectGroup::ObjectGroup() 
	: mOwnerWorld(nullptr)
{
}

ObjectGroup::ObjectGroup(std::wstring_view _name, std::wstring_view _tag)
	: Entity(_name, _tag), mOwnerWorld(nullptr)
{
}

ObjectGroup::~ObjectGroup()
{
}

void ObjectGroup::FixedUpdate()
{
}

void ObjectGroup::PreUpdate()
{
}

void ObjectGroup::Update()
{
}

void ObjectGroup::PostUpdate()
{
}

void ObjectGroup::PreRender()
{
}

void ObjectGroup::Render()
{
}

void ObjectGroup::PostRender()
{
}

void ObjectGroup::SetListSize(UINT _size)
{
	if (mObjects.size() > _size)
		return;
	mObjects.resize(_size);
}

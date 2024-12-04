#include "pch.h"
#include "World.h"

DXWorld::DXWorld() 
	: mWorldTransform(new Transform3D())
{

}

DXWorld::~DXWorld()
{
	SAFE_DELETE(mWorldTransform)
}

void DXWorld::FixedUpdate()
{
	for (auto& [first, second] : mObjectGroups)
	{
		if(second->GetState() == EntityState::Active)
			second->FixedUpdate();
	}
}

void DXWorld::PreUpdate()
{
	for (auto& [first, second] : mObjectGroups)
	{
		if (second->GetState() == EntityState::Active)
			second->PreUpdate();
	}
}

void DXWorld::Update()
{
	for (auto& [first, second] : mObjectGroups)
	{
		if (second->GetState() == EntityState::Active)
			second->Update();
	}
}

void DXWorld::PostUpdate()
{
	for (auto& [first, second] : mObjectGroups)
	{
		if (second->GetState() == EntityState::Active)
			second->PostUpdate();
	}
}

void DXWorld::PreRender()
{
	for (auto& [first, second] : mObjectGroups)
	{
		if (second->GetState() == EntityState::Active)
			second->PreRender();
	}
}

void DXWorld::Render()
{
	mWorldTransform->CalculateMatrix();
	for (auto& [first, second] : mObjectGroups)
	{
		if (second->GetState() == EntityState::Active)
			second->Render();
	}
}

void DXWorld::PostRender()
{
	for (auto itr = mObjectGroups.begin();
		itr != mObjectGroups.end(); )
	{
		ObjectGroup* group = (*itr).second;
		if (group->GetState() == EntityState::Active)
		{
			group->PostRender();
			++itr;
			continue;
		}
		else if (group->GetState() == EntityState::Destroy)
		{
			mDestroyQueue.push(group);
			itr = mObjectGroups.erase(itr);
			continue;
		}
	}
	DestroyUpdate();

	{ // 생성 주기
		ObjectGroup* pGroup = GetCreation();
		while (pGroup != nullptr)
		{
			mObjectGroups[pGroup->GetName()] = pGroup;
		}
	}
	
}

BOOL DXWorld::CreateObjectGroup(std::wstring_view _name, std::wstring_view _tag)
{
	auto itr = mObjectGroups.find(_name.data());
	if (itr != mObjectGroups.end()) 
		return FALSE;
	CreateAndPushWaitQueue(_name, _tag);
	return TRUE;
}

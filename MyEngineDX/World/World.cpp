#include "pch.h"
#include "World.h"

std::unordered_map<std::wstring, ObjectGroup*> DXWorld::mPersistanceObjectGroups {};

DXWorld::DXWorld(WorldManager* _wrdMng, std::wstring_view _name, std::wstring_view _tag)
	: Entity(_name, _tag), mWorldTransform(new Transform3D()), mWorldManager(_wrdMng)
{
}

DXWorld::~DXWorld()
{
	for (auto itr : mObjectGroups)
	{
		delete itr.second;
	}
	mObjectGroups.clear();
	SAFE_DELETE(mWorldTransform)
}

void DXWorld::FixedUpdate()
{
	FOR_LOOP_ENTITY(mObjectGroups, FixedUpdate());
}

void DXWorld::PreUpdate()
{
	FOR_LOOP_ENTITY(mObjectGroups, PreUpdate());
}

void DXWorld::Update()
{
	FOR_LOOP_ENTITY(mObjectGroups, Update());
}

void DXWorld::PostUpdate()
{
	FOR_LOOP_ENTITY(mObjectGroups, PostUpdate());
}

void DXWorld::PreRender()
{
	FOR_LOOP_ENTITY(mObjectGroups, PreRender());
}

void DXWorld::Render()
{
	mWorldTransform->CalculateMatrix();
	FOR_LOOP_ENTITY(mObjectGroups, Render());
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

	{ // 积己 林扁
		while (!mCreateQueue.empty())
		{
			mObjectGroups[mCreateQueue.front()->GetName()] = mCreateQueue.front();
			mCreateQueue.pop();
		}
	}

	{ // 昏力 林扁
		while (!mDestroyQueue.empty())
		{
			SAFE_DELETE(mDestroyQueue.front())
			mDestroyQueue.pop();
		}
	}
}

BOOL DXWorld::CreateObjectGroup(std::wstring_view _name, std::wstring_view _tag)
{
	auto itr = mObjectGroups.find(_name.data());
	if (itr != mObjectGroups.end()) 
		return FALSE;
	ObjectGroup* instance = new ObjectGroup(_name, _tag);
	mCreateQueue.push(instance);
	return TRUE;
}

ObjectGroup* DXWorld::GetObjectGroup(std::wstring_view _name)
{
	auto itr = mObjectGroups.find(_name.data());
	if (itr != mObjectGroups.end())
		return itr->second;

	itr = mPersistanceObjectGroups.find(_name.data());
	if (itr != mPersistanceObjectGroups.end())
		return itr->second;

	return nullptr;
}

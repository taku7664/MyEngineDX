#pragma once
#include "ObjectGroup/ObjectGroup.h"

class DXWorld 
	: public Engine::IEngineCycle
	, public Engine::Entity
	, public Engine::EntityFactory<ObjectGroup>
{
public:
	DXWorld();
	virtual ~DXWorld();
public:
	virtual void FixedUpdate() override;
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
public:
	BOOL CreateObjectGroup(std::wstring_view _name, std::wstring_view _tag);
private:
	Transform3D* mWorldTransform;
	std::unordered_map<std::wstring, ObjectGroup*> mObjectGroups;
};
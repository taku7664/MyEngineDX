#pragma once
#include "Object/Object.h"

class DXWorld;

class ObjectGroup
	: public Engine::IEngineCycle
	, public Engine::Entity
{
public:
	ObjectGroup();
	ObjectGroup(std::wstring_view _name, std::wstring_view _tag);
	~ObjectGroup();
public:
	virtual void FixedUpdate() override;
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
public:
	void SetListSize(UINT _size);
public:
	void SetOwner(DXWorld* _ownerWorld);
	const DXWorld* GetOwner() { return mOwnerWorld; }
	std::vector<GameObject*>& GetObjects() { return mObjects; }
private:
	DXWorld* mOwnerWorld;
	std::vector<GameObject*> mObjects;
};


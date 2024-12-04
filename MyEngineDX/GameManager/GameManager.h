#pragma once
#include "World/WorldManager.h"

class GameManager
	: public Engine::IEngineCycle
{
public:
	GameManager();
	~GameManager() = default;
public:
	BOOL Initialize();
	void Run();
	void Finalization();
public:
	virtual void FixedUpdate() override;
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
public:

public:
	auto* GetWorldManager() { return mWorldManager; }
private:
	WorldManager* mWorldManager;

	float mFixedUpdateTick;
};

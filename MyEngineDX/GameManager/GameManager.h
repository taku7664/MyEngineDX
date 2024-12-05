#pragma once
#include "World/WorldManager.h"

namespace Engine
{
	class Application;
}

class GameManager
	: public Engine::IEngineCycle
{
public:
	GameManager(Engine::Application* _pApp);
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
	auto* GetApplication()	{ return mApplication; }
	auto* GetWorldManager() { return mWorldManager; }
private:
	Engine::Application*  mApplication;
	WorldManager* mWorldManager;

	float mFixedUpdateTick;
};

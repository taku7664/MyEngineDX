#include "pch.h"
#include "GameManager.h"

GameManager::GameManager()
	: mWorldManager(nullptr)
	, mFixedUpdateTick(0.02f)
{
}

BOOL GameManager::Initialize()
{
	mWorldManager = new WorldManager(this);

	return TRUE;
}

void GameManager::Run()
{
	MSG msg;
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		//Input::InputMessegeProcess(msg);
	}
	else
	{
		//Time::Update();
		//Input::Update();
		FixedUpdate();
		PreUpdate();
		Update();
		PostUpdate();
		PreRender();
		//Render(m_renderer);
		PostRender();
		//Input::Reset();
	}
}

void GameManager::Finalization()
{
	SAFE_DELETE(mWorldManager)
}

void GameManager::FixedUpdate()
{
	static float counter = 0.0f;
	counter += Time::GetUnScaledDeltaTime();
	while (counter >= mFixedUpdateTick)
	{
		counter -= mFixedUpdateTick;
		mWorldManager->FixedUpdate();
	}
}

void GameManager::PreUpdate()
{
}

void GameManager::Update()
{
}

void GameManager::PostUpdate()
{
}

void GameManager::PreRender()
{
}

void GameManager::Render()
{
}

void GameManager::PostRender()
{
}

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
		if (mWorldManager)
		{
			mWorldManager->FixedUpdate();
		}
	}
}

void GameManager::PreUpdate()
{
	if(mWorldManager)
		mWorldManager->PreUpdate();
}

void GameManager::Update()
{
	if (mWorldManager)
		mWorldManager->Update();
}

void GameManager::PostUpdate()
{
	if (mWorldManager)
		mWorldManager->PostUpdate();
}

void GameManager::PreRender()
{
	if (mWorldManager)
		mWorldManager->PreRender();
}

void GameManager::Render()
{
	if (mWorldManager)
		mWorldManager->Render();
}

void GameManager::PostRender()
{
	if (mWorldManager)
		mWorldManager->PostRender();
}

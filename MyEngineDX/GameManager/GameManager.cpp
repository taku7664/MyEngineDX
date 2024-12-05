#include "pch.h"
#include "GameManager.h"
#include "Application/Application.h"

GameManager::GameManager(Engine::Application* _pApp)
	: mApplication(_pApp)
	, mWorldManager(nullptr)
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
		Time::Update();
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
	if (mApplication)
		mApplication->OnPreUpdate();
	if(mWorldManager)
		mWorldManager->PreUpdate();
}

void GameManager::Update()
{
	if (mApplication)
		mApplication->OnUpdate();
	if (mWorldManager)
		mWorldManager->Update();
}

void GameManager::PostUpdate()
{
	if (mApplication)
		mApplication->OnPostUpdate();
	if (mWorldManager)
		mWorldManager->PostUpdate();
}

void GameManager::PreRender()
{
	if (mApplication)
		mApplication->OnPreRender();
	if (mWorldManager)
		mWorldManager->PreRender();
}

void GameManager::Render()
{
	if (mApplication)
		mApplication->OnRender();
	if (mWorldManager)
		mWorldManager->Render();
}

void GameManager::PostRender()
{
	if (mApplication)
		mApplication->OnPostRender();
	if (mWorldManager)
		mWorldManager->PostRender();
}

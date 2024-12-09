#include "pch.h"
#include "GameManager.h"
#include "Application/Application.h"

GameManager::GameManager(Engine::Application* _pApp)
	: mApplication(_pApp)
	, mWorldManager(new WorldManager(this))
	, mGraphicsManager(new GraphicsManager())
	, mFixedUpdateTick(0.02f)
{
}

BOOL GameManager::Initialize()
{
	if (!mGraphicsManager->Initialize()) return FALSE;

	if (S_OK != Display::CreateIDisplayDevice(mApplication->mHInstance, &mDisplayDevice)) return FALSE;

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
		Render(mGraphicsManager->GetRenderer());
		PostRender();
		//Input::Reset();
	}
}

void GameManager::Finalization()
{
	SAFE_DELETE(mWorldManager)
	SAFE_DELETE(mGraphicsManager)
}

void GameManager::FixedUpdate()
{
	static float counter = 0.0f;
	
	counter += Time::GetUnScaledDeltaTime();
	while (counter >= mFixedUpdateTick)
	{
		counter -= mFixedUpdateTick;
		if (mApplication)
			mApplication->OnFixedUpdate();
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

void GameManager::Render(GraphicsManager* _graphicsManager)
{
	//_renderer->SetRenderTarget()
	_graphicsManager->BeginRender();

	if (mApplication)
		mApplication->OnRender();
	if (mWorldManager)
		mWorldManager->Render(_graphicsManager);

	_graphicsManager->EndRender();
}

void GameManager::PostRender()
{
	if (mApplication)
		mApplication->OnPostRender();
	if (mWorldManager)
		mWorldManager->PostRender();
}

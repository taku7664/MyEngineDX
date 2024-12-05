#include "pch.h"
#include "Application.h"
#include "GameManager/GameManager.h"

namespace Engine
{
	Application::Application(HINSTANCE _hInstance)
		: mHInstance(_hInstance), IsShutdown(false)
		, mGameManager(new GameManager(this)), mDisplayDevice(nullptr)
	{
	}
	Application::~Application()
	{
		if(mGameManager)
			delete mGameManager;
	}
	BOOL Application::Initialize()
	{
		if (FALSE == OnPreInitialize()) return FALSE;

		if (FALSE == mGameManager->Initialize()) return FALSE;

		if (S_OK != Display::CreateIDisplayDevice(mHInstance, &mDisplayDevice)) return FALSE;

		if (FALSE == OnPostInitialize()) return FALSE;

		return TRUE;
	}
	void Application::Run()
	{
		while (!IsShutdown)
		{
			mGameManager->Run();
		}
	}
	void Application::Finalization()
	{
		OnPreFinalization();

		mGameManager->Finalization();

		OnPostFinalization();
	}
}
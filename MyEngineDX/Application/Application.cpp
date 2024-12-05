#include "pch.h"
#include "Application.h"
#include "GameManager/GameManager.h"

namespace Engine
{
	Application::Application(HINSTANCE _hInstance, const WCHAR* _title, int _width, int _height, DWORD _style, int _posX, int _posY)
		: mHInstance(_hInstance), mGameManager(new GameManager()), IsShutdown(false)
	{
	}
	BOOL Application::Initialize()
	{
		if (FALSE == OnPreInitialize()) return FALSE;

		if (FALSE == mGameManager->Initialize()) return FALSE;

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

		SAFE_DELETE(mGameManager)
	}
	void Application::ShutDown()
	{
		IsShutdown = true;
	}
}
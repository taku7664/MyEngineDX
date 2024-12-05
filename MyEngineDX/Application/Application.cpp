#include "pch.h"
#include "Application.h"
#include "GameManager/GameManager.h"

namespace Engine
{
	Application::Application(HINSTANCE _hInstance, const WCHAR* _title, int _width, int _height, DWORD _style, int _posX, int _posY)
		: mHInstance(_hInstance), IsShutdown(false)
		, mGameManager(new GameManager()), mDisplayDevice(nullptr)
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
	void Application::ShutDown()
	{
		IsShutdown = true;
	}
}
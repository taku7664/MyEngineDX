#include "pch.h"
#include "Application.h"

namespace Engine
{
	Application::Application(HINSTANCE _hInstance, const WCHAR* _title, int _width, int _height, DWORD _style, int _posX, int _posY)
		: mHInstance(_hInstance)
	{
	}
	void Application::Initialize()
	{
		OnPreInitialize();
		OnPostInitialize();
	}
	void Application::Run()
	{
	}
	void Application::Finalization()
	{
		OnPreFinalization();
		OnPostFinalization();
	}
}
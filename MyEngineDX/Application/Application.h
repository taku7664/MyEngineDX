#pragma once
#include "pch.h"
#include "GameManager/GameManager.h"

namespace Engine
{
	class Application
	{
	public:
		explicit Application(HINSTANCE _hInstance, const WCHAR* _title, int _width, int _height, DWORD _style = WS_OVERLAPPEDWINDOW, int _posX = 0, int _posY = 0);
		~Application() = default;

		Application(Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) noexcept = default;
		Application& operator=(Application&&) noexcept = default;
	public:
		virtual BOOL Initialize() final;
		virtual void Run() final;
		virtual void Finalization() final;
	protected:
		// 사용자 정의
		virtual BOOL OnPreInitialize() { return FALSE; };
		virtual BOOL OnPostInitialize() { return FALSE; };
		virtual void OnPreFinalization() {};
		virtual void OnPostFinalization() {};

		virtual void OnTick() {};
		virtual void OnUpdate() {};
		virtual void OnFixedUpdate() {};
		virtual void OnPreRender() {};
		virtual void OnPostRender() {};
	public:
		BOOL IsShutdown;
		void ShutDown();

		auto* GetGameManager() { return mGameManager; }
	private:
		HINSTANCE mHInstance;
		GameManager* mGameManager;
	};
}
#pragma once
#include "pch.h"
#include "GameManager/GameManager.h"
#include "../Window/IDisplay.h"

namespace Engine
{
	class Application
	{
	public:
		explicit Application(HINSTANCE _hInstance);
		virtual ~Application();
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
		virtual BOOL OnPreInitialize()  { return FALSE; };
		virtual BOOL OnPostInitialize() { return FALSE; };
		virtual void OnPreFinalization() {};
		virtual void OnPostFinalization() {};

		virtual void OnFixedUpdate() {};
		virtual void OnPreUpdate() {};
		virtual void OnUpdate() {};
		virtual void OnPostUpdate() {};
		virtual void OnPreRender() {};
		virtual void OnRender() {};
		virtual void OnPostRender() {};
	public:
		void  ShutDown() { IsShutdown = true; }
		auto* GetGameManager() { return mGameManager; }
		auto* GetDisplayDevice() { return mDisplayDevice; }
	protected:
		HINSTANCE mHInstance;
		BOOL IsShutdown;
		GameManager* const mGameManager;
		Display::IDisplayDevice* mDisplayDevice;
		friend class GameManager;
	};
}
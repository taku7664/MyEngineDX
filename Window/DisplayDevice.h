#pragma once
#include "IDisplay.h"
#include "Window.h"

namespace Display
{
	class DisplayDevice : public IDisplayDevice
	{
	public:
		DisplayDevice(HINSTANCE _hInstance);
		virtual ~DisplayDevice();
		DisplayDevice(const DisplayDevice& _other) = default;
		DisplayDevice(DisplayDevice&& _other) noexcept = default;
		DisplayDevice& operator=(const DisplayDevice& _other) = default;
		DisplayDevice& operator=(DisplayDevice&& _other) noexcept = default;
	public:
		virtual	void Release() override;
	public:
		virtual HRESULT CreateWindowDisplay(WindowDesc* _pWindDesc, IWindow** _ppIWindow) override;
		virtual HRESULT CreateConsoleDisplay(ConsoleDesc* _pConsoleDesc, IConsole** _ppIConsole) override { return E_FAIL; };
	private:
		HINSTANCE mHInstance;
		// Display를 관리할 배열만들기
	};
}
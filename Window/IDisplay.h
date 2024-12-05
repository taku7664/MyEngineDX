#pragma once

namespace Display
{
	class IDisplay;
	class IWindow;
	class IConsole;

	class IDisplayDevice
	{
	public:
		IDisplayDevice() = default;
		virtual ~IDisplayDevice() = default;
		IDisplayDevice(const IDisplayDevice& _other) = default;
		IDisplayDevice(IDisplayDevice&& _other) noexcept = default;
		IDisplayDevice& operator=(const IDisplayDevice& _other) = default;
		IDisplayDevice& operator=(IDisplayDevice&& _other) noexcept = default;
	public:
		virtual HRESULT CreateWindowDisplay(IWindow** _ppIWindow) = 0;
		virtual HRESULT CreateWindowDisplay(IConsole** _ppIConsole) = 0;
	};

	class IDisplay
	{
	public:
		virtual HWND			GetHandle() = 0;
		virtual const WCHAR*	GetTitle() = 0;
		virtual RECT			GetRect() = 0;
		virtual POINT			GetPosition() = 0;
		virtual POINT			GetSize() = 0;

		virtual void			SetPosition() = 0;
		virtual void			SetSize() = 0;
	};

	class IWindow : public IDisplay
	{
	public:
		virtual void SetFocus() = 0;
		virtual bool IsFocusing() = 0;
	};
	class IConsole : public IDisplay
	{
	public:
		template<typename... Args>
		void Log(Args&&... args) = 0;
	};
}



#pragma once
#include "IDisplay.h"

namespace Display
{
	class Window : public IWindow
	{
	public:
		Window(HWND _Hwnd, WindowDesc* _pWndDesc);
		~Window();
		Window(const Window& _other) = default;
		Window(Window&& _other) noexcept = default;
		Window& operator=(const Window& _other) = default;
		Window& operator=(Window&& _other) noexcept = default;
	public:
		virtual HWND			GetHandle() override;
		virtual const WCHAR*	GetTitle() override;
		virtual RECT			GetRect() override;
		virtual POINT			GetPosition() override;
		virtual POINT			GetSize() override;

		virtual BOOL			SetPosition(POINT) override;
		virtual BOOL			SetSize(POINT) override;
	public:
		virtual HWND			GetParentHandle() override;
		virtual void			SetFocus() override;
		virtual bool			IsFocusing() override;
	private:
		HWND  mHwnd;
		HWND  mHParent;
		const WCHAR* mTitle;
		POINT mPosition;
		POINT mSize;
	};
}
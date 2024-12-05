#pragma once
#include "IDisplay.h"

namespace Display
{
	class Window : public IWindow
	{
	public:

	public:
		virtual HWND			GetHandle() override;
		virtual const WCHAR*	GetTitle() override;
		virtual RECT			GetRect() override;
		virtual POINT			GetPosition() override;
		virtual POINT			GetSize() override;

		virtual void			SetPosition() override;
		virtual void			SetSize() override;
	public:
		virtual void			SetFocus() override;
		virtual bool			IsFocusing() override;
	private:
		HWND  mHwnd;
		const WCHAR* mTitle;
		POINT mPosition;
		POINT mSize;
	};
}
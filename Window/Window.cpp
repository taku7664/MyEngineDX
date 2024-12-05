#include "pch.h"
#include "Window.h"

namespace Display
{
	Window::Window(HWND _Hwnd, WindowDesc* _pWndDesc)
		: mHwnd(_Hwnd)
		, mHParent((*_pWndDesc).WndParent->GetHandle())
		, mTitle((*_pWndDesc).Title)
		, mPosition((*_pWndDesc).Position)
		, mSize((*_pWndDesc).Size)
	{
	}

	Window::~Window()
	{
	}

	inline HWND Window::GetHandle()
	{
		return mHwnd;
	}

	inline const WCHAR* Window::GetTitle()
	{
		return mTitle;
	}

	inline RECT Window::GetRect()
	{
		return RECT();
	}

	inline POINT Window::GetPosition()
	{
		return mPosition;
	}

	inline POINT Window::GetSize()
	{
		return mSize;
	}

	inline HWND Window::GetParentHandle()
	{
		return mHParent;
	}

	inline BOOL Window::SetPosition(POINT _xy)
	{
		BOOL res;
		res = MoveWindow(mHwnd
			, static_cast<int>(_xy.x)
			, static_cast<int>(_xy.y)
			, static_cast<int>(mSize.x + _xy.x)
			, static_cast<int>(mSize.y + _xy.y)
			, TRUE);
		if (res)
		{
			mPosition = _xy;
		}
		return res;
	}

	inline BOOL Window::SetSize(POINT _wh)
	{
		BOOL res;
		res = SetWindowPos(mHwnd
			, HWND_TOP
			, static_cast<int>(mPosition.x)
			, static_cast<int>(mPosition.y)
			, static_cast<int>(_wh.x)
			, static_cast<int>(_wh.y)
			, SWP_NOMOVE);
		if (res)
		{
			mSize = _wh;
		}
		return res;
	}

	inline void Window::SetFocus()
	{
		::SetFocus(mHwnd);
	}

	bool Window::IsFocusing()
	{
		return false;
	}
}
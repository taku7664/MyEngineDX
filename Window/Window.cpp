#include "pch.h"
#include "Window.h"

HWND Display::Window::GetHandle()
{
	return HWND();
}

const WCHAR* Display::Window::GetTitle()
{
	return nullptr;
}

RECT Display::Window::GetRect()
{
	return RECT();
}

POINT Display::Window::GetPosition()
{
	return POINT();
}

POINT Display::Window::GetSize()
{
	return POINT();
}

void Display::Window::SetPosition()
{
}

void Display::Window::SetSize()
{
}

void Display::Window::SetFocus()
{
}

bool Display::Window::IsFocusing()
{
	return false;
}

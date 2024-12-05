#include "pch.h"
#include "DisplayDevice.h"

namespace Display
{
    DisplayDevice::DisplayDevice(HINSTANCE _hInstance)
        : mHInstance(_hInstance)
    {
    }
    DisplayDevice::~DisplayDevice()
    {
    }
    void DisplayDevice::Release()
    {
        delete this;
    }
    HRESULT DisplayDevice::CreateWindowDisplay(WindowDesc* _pWndDesc, IWindow** _ppIWindow)
    {
        if (!_pWndDesc || (*_ppIWindow))
        {
            return E_INVALIDARG;
        }
        if (!(*_pWndDesc).WndClass.lpfnWndProc)
        {
            return E_INVALIDARG;
        }

        (*_pWndDesc).WndClass.hInstance = mHInstance;
        (*_pWndDesc).WndClass.hIcon = LoadIcon(mHInstance, IDI_APPLICATION);

        if (!RegisterClass(&(*_pWndDesc).WndClass))
        {
            throw std::runtime_error("Failed to register window class.");
        }

        RECT rect = { 0, 0
            , static_cast<LONG>((*_pWndDesc).Size.x)
            , static_cast<LONG>((*_pWndDesc).Size.y) };
        AdjustWindowRect(&rect, (*_pWndDesc).WndStyle, FALSE);
        const LONG width = rect.right - rect.left;
        const LONG height = rect.bottom - rect.top;
        HWND hParent = (*_pWndDesc).WndParent == nullptr ? nullptr : (*_pWndDesc).WndParent->GetHandle();

        HWND hwnd = CreateWindow(
            (*_pWndDesc).Title, (*_pWndDesc).Title, (*_pWndDesc).WndStyle,
            rect.left, rect.top, width, height,
            hParent, NULL, mHInstance, NULL);

        if (!hwnd)
        {
            return E_FAIL;
        }
        (*_ppIWindow) = new Window(hwnd, _pWndDesc);
        if (!(*_ppIWindow))
        {
            return E_INVALIDARG;
        }
        ShowWindow(hwnd, SW_SHOWNORMAL);
        UpdateWindow(hwnd);

        return E_NOTIMPL;
    }
}
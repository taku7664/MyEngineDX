#include "pch.h"
#include "GraphicsManager.h"
#include "../Window/IDisplay.h"

GraphicsManager::GraphicsManager()
{
}

GraphicsManager::~GraphicsManager()
{
}

BOOL GraphicsManager::Initialize()
{
    Graphics::CreateGraphicsDeviceAndRenderer(&mGraphicsDevice, &mRenderer);
    return TRUE;
}

void GraphicsManager::Finalization()
{
    SAFE_RELEASE(mRenderer)
    SAFE_RELEASE(mGraphicsDevice)
}

BOOL GraphicsManager::SetUpDisplay(Display::IWindow** _ppWindow)
{
    if (mRenderer)
    {
        Graphics::RenderTarget* pRenderTarget;
        HRESULT hr = mGraphicsDevice->CreateRenderTarget((*_ppWindow)->GetHandle(), &pRenderTarget);
        if (hr == S_OK)
        {
            mRenderTargetTable.insert(std::make_pair((*_ppWindow)->GetParentHandle(), pRenderTarget));
            return TRUE;
        }
    }
    return FALSE;
}

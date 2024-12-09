#include "pch.h"
#include "D3DGraphicsDevice.h"
#include "D3DRenderTarget.h"
#include "D3DRenderer.h"

namespace Graphics
{
	D3DGraphicsDevice::D3DGraphicsDevice(ID3D11Device* _pDevice, IDXGIFactory* _pFactory, IDXGIAdapter3* _pAdapter)
	{
		if (!_pDevice)
		{
			std::runtime_error("Failed to create d3d11device.");
		}
		else
		{
			if (_pDevice)
			mDevice = _pDevice;
			if(_pFactory)
			mFactory = _pFactory;
			if(_pAdapter)
			mDXGIAdapter = _pAdapter;
		}
	}

	D3DGraphicsDevice::~D3DGraphicsDevice()
	{

	}
	void D3DGraphicsDevice::Release()
	{
		if (mDevice)
			mDevice->Release();
		if (mFactory)
			mFactory->Release();
		if (mDXGIAdapter)
			mDXGIAdapter->Release();
	}
	HRESULT D3DGraphicsDevice::CreateRenderer(IRenderer** _ppRenderer)
	{
		return E_NOTIMPL;
	}
	HRESULT D3DGraphicsDevice::CreateRenderTarget(HWND _hwnd, IRenderTarget** _ppRenderTarget)
	{
		if (!_hwnd)
		{
			return E_INVALIDARG;
		}
		(*_ppRenderTarget) = new D3DRenderTarget(this, _hwnd);
		return S_OK;
	}

	/*void D3DGraphicsDevice::AddRenderer(IRenderer* _pRenderer)
	{
		auto itr = mRenderers.find(_pRenderer);
		if (itr != mRenderers.end())
		{
			mRenderers.insert(_pRenderer);
		}
	}

	void D3DGraphicsDevice::AddRenderTarget(IRenderTarget* _pRenderTarget)
	{
		auto itr = mRendererTargets.find(_pRenderTarget);
		if (itr != mRendererTargets.end())
		{
			mRendererTargets.insert(_pRenderTarget);
		}
	}*/

	HRESULT D3DGraphicsDevice::CreateSwapChain(DXGI_SWAP_CHAIN_DESC* _pSwapChainDesc, IDXGISwapChain** _ppSwapChain)
	{
		return mFactory->CreateSwapChain(mDevice, _pSwapChainDesc, _ppSwapChain);
	}
	HRESULT D3DGraphicsDevice::CreateRenderTargetView(ID3D11Resource* _pBuffer, const D3D11_RENDER_TARGET_VIEW_DESC* _pRtvDesc, ID3D11RenderTargetView** _ppRenderTargetView)
	{
		return mDevice->CreateRenderTargetView(_pBuffer, _pRtvDesc, _ppRenderTargetView);
	}
	HRESULT D3DGraphicsDevice::CreateDepthStencilView(ID3D11Resource* _pBuffer, const D3D11_DEPTH_STENCIL_VIEW_DESC* _pDsvDesc, ID3D11DepthStencilView** _ppDepthStencilView)
	{
		return mDevice->CreateDepthStencilView(_pBuffer, _pDsvDesc, _ppDepthStencilView);
	}
	HRESULT D3DGraphicsDevice::CreateTexture2D(D3D11_TEXTURE2D_DESC* _pTexDesc, const D3D11_SUBRESOURCE_DATA* _pInitialData, ID3D11Texture2D** _ppTexture2D)
	{
		return mDevice->CreateTexture2D(_pTexDesc, _pInitialData, _ppTexture2D);
	}
}
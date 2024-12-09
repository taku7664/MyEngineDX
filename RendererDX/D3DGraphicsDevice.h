#pragma once
#include "IGraphics.h"
#include "D3DRenderer.h"

namespace Graphics
{
	class D3DGraphicsDevice
		: public IGraphicsDevice
	{
	public:
		explicit D3DGraphicsDevice(ID3D11Device* _pDevice, IDXGIFactory* _pFactory, IDXGIAdapter3* _pAdapter);
		virtual ~D3DGraphicsDevice();
	public:
		virtual void	Release() override;
		virtual HRESULT CreateRenderer(IRenderer** _ppRenderer) override;
		virtual HRESULT CreateRenderTarget(HWND _hwnd, IRenderTarget** _ppRenderTarget) override;
	public:
		HRESULT CreateSwapChain(DXGI_SWAP_CHAIN_DESC* _pSwapChainDesc, IDXGISwapChain** _ppSwapChain);
		HRESULT CreateRenderTargetView(ID3D11Resource* _pBuffer, const D3D11_RENDER_TARGET_VIEW_DESC* _pRtvDesc, ID3D11RenderTargetView** _ppRenderTargetView);
		HRESULT CreateDepthStencilView(ID3D11Resource* _pBuffer, const D3D11_DEPTH_STENCIL_VIEW_DESC* _pDsvDesc, ID3D11DepthStencilView** _ppDepthStencilView);
		HRESULT CreateTexture2D(D3D11_TEXTURE2D_DESC* _pTexDesc, const D3D11_SUBRESOURCE_DATA* _pInitialData, ID3D11Texture2D** _ppTexture2D);
	private:
		ID3D11Device*		 mDevice;
		IDXGIFactory*		 mFactory;
		IDXGIAdapter3*		 mDXGIAdapter;
	public:
	};
}
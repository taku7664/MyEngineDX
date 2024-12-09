#pragma once
#include "IGraphics.h"

namespace Graphics
{
	class D3DGraphicsDevice;
	class D3DRenderTarget : public IRenderTarget
	{
	public:
		explicit D3DRenderTarget(D3DGraphicsDevice* _pDevice, HWND _hWnd);
		virtual ~D3DRenderTarget();
	public:
		virtual void Release() override;
		virtual void Clear() override;
	public:
		void ClearRenderTarget(ID3D11DeviceContext* _pContext, const FLOAT* _rgba);
		void ClearRenderTarget(ID3D11DeviceContext* _pContext);
		void ClearDepthStencil(ID3D11DeviceContext* _pContext, FLOAT _depth = 1.0f, UINT8 _stencil = 0);
	public:
		const FLOAT*			GetClearColor() const { return mClearColor; }
		ID3D11RenderTargetView* GetRenderTargetView() const { return mRenderTargetView; }
		ID3D11DepthStencilView* GetDepthStencilView() const { return mDepthStencilView; }
		const D3D11_VIEWPORT&	GetViewport() const { return mViewPort; }
		IDXGISwapChain*			GetSwapChain() const { return mSwapChain; }
	private:
		FLOAT mClearColor[4];
		HWND mHwnd;
		ID3D11RenderTargetView* mRenderTargetView;
		ID3D11DepthStencilView* mDepthStencilView;
		D3D11_VIEWPORT          mViewPort;
		IDXGISwapChain*			mSwapChain;

		D3DGraphicsDevice*		mGraphicsDevice;
	};
}

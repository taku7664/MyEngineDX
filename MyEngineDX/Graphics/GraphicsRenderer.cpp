#include "pch.h"
#include "GraphicsRenderer.h"
#include "GraphicsRenderTarget.h"

namespace Graphics
{
	Renderer::Renderer(GraphicsDevice* _pDevice, ID3D11DeviceContext* _pContext)
		: mGraphicsDevice(_pDevice)
		, mContext(_pContext)
		, mCurRenderTarget(nullptr)
	{
	}
	Renderer::~Renderer()
	{
	}
	void Renderer::Release()
	{
		if (mContext)
			mContext->Release();
	}
	BOOL Renderer::BeginRender()
	{
		if (mCurRenderTarget)
		{
			ID3D11RenderTargetView* renderTargetView = mCurRenderTarget->GetRenderTargetView();
			ID3D11DepthStencilView* depthStencilView = mCurRenderTarget->GetDepthStencilView();
			if (renderTargetView)
			{
				const FLOAT* clearColor = mCurRenderTarget->GetClearColor();
				mContext->ClearRenderTargetView(renderTargetView, clearColor);
			}
			if (depthStencilView)
			{
				mContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
			}
			return TRUE;
		}
		return FALSE;
	}
	BOOL Renderer::EndRender()
	{
		IDXGISwapChain* swapChain = mCurRenderTarget->GetSwapChain();
		swapChain->Present(0, 0);
		return TRUE;
	}
	BOOL Renderer::DrawCall(UINT _numIndex, UINT _startIndex, INT _baseVertex)
	{
		mContext->DrawIndexed(_numIndex, _startIndex, _baseVertex);
		return TRUE;
	}
	BOOL Renderer::SetRenderTarget(RenderTarget* _pRenderTarget)
	{
		if (_pRenderTarget)
		{
			// 이미 현재 렌더타겟과 같으면 바꿀 필요가 없다.
			if (mCurRenderTarget == _pRenderTarget)
				return TRUE;
			ID3D11RenderTargetView* rtv = _pRenderTarget->GetRenderTargetView();
			ID3D11DepthStencilView* dsv = _pRenderTarget->GetDepthStencilView();
			const D3D11_VIEWPORT& vp = _pRenderTarget->GetViewport();
			if (rtv && dsv)
			{
				mContext->OMSetRenderTargets(1, &rtv, dsv);
				mContext->RSSetViewports(1, &vp);
				mCurRenderTarget = _pRenderTarget;
				return TRUE;
			}
		}
		return TRUE;
	}
}
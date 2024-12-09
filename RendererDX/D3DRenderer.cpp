#include "pch.h"
#include "D3DRenderer.h"
#include "D3DGraphicsDevice.h"
#include "D3DRenderTarget.h"

namespace Graphics
{
	D3DRenderer::D3DRenderer(D3DGraphicsDevice* _pDevice, ID3D11DeviceContext* _pContext)
		: mGraphicsDevice(_pDevice)
		, mContext(_pContext)
		, isRendering(FALSE)
	{
	}
	D3DRenderer::~D3DRenderer()
	{
		if (mContext)
		{
			mContext->Release();
		}
	}
	void D3DRenderer::Release()
	{
		if (mContext)
			mContext->Release();
	}
	BOOL D3DRenderer::BeginRender()
	{
		if (!isRendering)
		{
			if (mCurRenderTarget)
			{
				ID3D11RenderTargetView* renderTargetView = mCurRenderTarget->GetRenderTargetView();
				ID3D11DepthStencilView* depthStencilView = mCurRenderTarget->GetDepthStencilView();
				if (renderTargetView)
				{
					mCurRenderTarget->ClearRenderTarget(mContext);
				}
				if (depthStencilView)
				{
					mCurRenderTarget->ClearDepthStencil(mContext);
				}
				isRendering = TRUE;
				return TRUE;
			}
		}
		return FALSE;
	}
	BOOL D3DRenderer::EndRender()
	{
		if (isRendering)
		{
			if (mCurRenderTarget)
			{
				mCurRenderTarget->GetSwapChain()->Present(0, 0);
				isRendering = FALSE;
			}
		}
		return TRUE;
	}
	BOOL D3DRenderer::DrawCall(UINT _numIndex, UINT _startIndex, INT _baseVertex)
	{
		if (isRendering)
		{
			mContext->DrawIndexed(_numIndex, _startIndex, _baseVertex);
			return TRUE;
		}
		return FALSE;
	}
	BOOL D3DRenderer::SetRenderTarget(IRenderTarget* _pRenderTarget)
	{
		if (FALSE == isRendering)
		{
			// 이미 현재 렌더타겟과 같으면 바꿀 필요가 없다.
			if (mCurRenderTarget == _pRenderTarget)
				return TRUE;
			D3DRenderTarget* pRenderTarget = dynamic_cast<D3DRenderTarget*>(_pRenderTarget);
			if (pRenderTarget)
			{
				ID3D11RenderTargetView* rtv = pRenderTarget->GetRenderTargetView();
				ID3D11DepthStencilView* dsv = pRenderTarget->GetDepthStencilView();
				const D3D11_VIEWPORT& vp = pRenderTarget->GetViewport();
				if (rtv && dsv)
				{
					mContext->OMSetRenderTargets(1, &rtv, dsv);
					mContext->RSSetViewports(1, &vp);
					mCurRenderTarget = pRenderTarget;
					return TRUE;
				}
			}
		}
		return FALSE;
	}
}
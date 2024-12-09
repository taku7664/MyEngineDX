#pragma once
#include "IGraphics.h"

namespace Graphics
{
	class D3DGraphicsDevice;
	class D3DRenderTarget;

	class D3DRenderer
		: public IRenderer
	{
	public:
		explicit D3DRenderer(D3DGraphicsDevice* _pDevice, ID3D11DeviceContext* _pContext);
		virtual ~D3DRenderer();
	public:
		virtual void Release() override;
		virtual BOOL BeginRender() override;
		virtual BOOL EndRender() override;
		virtual BOOL DrawCall(UINT _numIndex, UINT _startIndex, INT _baseVertex) override;

		virtual BOOL SetRenderTarget(IRenderTarget* _pRenderTarget) override;
	private:
		BOOL isRendering;

		ID3D11DeviceContext* mContext;
		D3DGraphicsDevice*	 mGraphicsDevice;
		D3DRenderTarget*	 mCurRenderTarget;
	public:
		const auto& GetContext() { return mContext; }
	};
}



#pragma once

namespace Graphics
{
	class GraphicsDevice;
	class RenderTarget;

	class Renderer
	{
	public:
		explicit Renderer(GraphicsDevice* _pDevice, ID3D11DeviceContext* _pContext);
		virtual ~Renderer();
		Renderer(Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer(Renderer&&) noexcept = default;
		Renderer& operator=(Renderer&&) noexcept = default;
	public:
		void Release();
	public:
		BOOL BeginRender();
		BOOL EndRender();
		BOOL DrawCall(UINT _numIndex, UINT _startIndex, INT _baseVertex);

		BOOL SetRenderTarget(RenderTarget* _pRenderTarget);
	private:
		ID3D11DeviceContext* mContext;
		RenderTarget* mCurRenderTarget;
		GraphicsDevice* mGraphicsDevice;
	public:
		RenderTarget* GetRenderTarget() { return mCurRenderTarget; }
	};
}

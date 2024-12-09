#pragma once

namespace Graphics
{
	// D3D는 래핑할게 너무 많아서 일단 포기
	class IGraphicsDevice;
	class IRenderer;
	class IRenderTarget;

	HRESULT CreateID3D11GraphicsDeviceAndRenderer(IGraphicsDevice** _ppDevice, IRenderer** _ppRenderer);

	class IGraphicsDevice
	{
	public:
		explicit IGraphicsDevice() = default;
		virtual ~IGraphicsDevice() = default;
		IGraphicsDevice(IGraphicsDevice&) = delete;
		IGraphicsDevice& operator=(const IGraphicsDevice&) = delete;
		IGraphicsDevice(IGraphicsDevice&&) noexcept = default;
		IGraphicsDevice& operator=(IGraphicsDevice&&) noexcept = default;
	public:
		virtual void Release() = 0;
		virtual HRESULT CreateRenderer(IRenderer** _ppRenderer) = 0;
		virtual HRESULT CreateRenderTarget(HWND _hwnd, IRenderTarget** _ppRenderTarget) = 0;
	};

	class IRenderer
	{
	public:
		explicit IRenderer() = default;
		virtual ~IRenderer() = default;
		IRenderer(IRenderer&) = delete;
		IRenderer& operator=(const IRenderer&) = delete;
		IRenderer(IRenderer&&) noexcept = default;
		IRenderer& operator=(IRenderer&&) noexcept = default;
	public:
		virtual void Release() = 0;
		virtual BOOL BeginRender() = 0;
		virtual BOOL EndRender() = 0;
		virtual BOOL DrawCall(UINT _numIndex, UINT _startIndex, INT _baseVertex) = 0;
		virtual BOOL SetRenderTarget(IRenderTarget* _pRenderTarget) = 0;

		virtual void BindVertexBuffer() = 0;
		virtual void BindIndexBuffer() = 0;

	};

	class IRenderTarget
	{
	public:
		explicit IRenderTarget() = default;
		virtual ~IRenderTarget() = default;
		IRenderTarget(IRenderTarget&) = delete;
		IRenderTarget& operator=(const IRenderTarget&) = delete;
		IRenderTarget(IRenderTarget&&) noexcept = default;
		IRenderTarget& operator=(IRenderTarget&&) noexcept = default;
	public:
		virtual void Release() = 0;
		virtual void Clear() = 0;
	};

	class IBuffer
	{
	public:
		explicit IBuffer() = default;
		virtual ~IBuffer() = default;
		IBuffer(IBuffer&) = delete;
		IBuffer& operator=(const IBuffer&) = delete;
		IBuffer(IBuffer&&) noexcept = default;
		IBuffer& operator=(IBuffer&&) noexcept = default;
	public:
		virtual void Release() = 0;
	};

	class IShader
	{
	public:
		explicit IShader() = default;
		virtual ~IShader() = default;
		IShader(IShader&) = delete;
		IShader& operator=(const IShader&) = delete;
		IShader(IShader&&) noexcept = default;
		IShader& operator=(IShader&&) noexcept = default;
	public:
		virtual void Release() = 0;
	};

	class ITexture2D
	{
	public:
		explicit ITexture2D() = default;
		virtual ~ITexture2D() = default;
		ITexture2D(ITexture2D&) = delete;
		ITexture2D& operator=(const ITexture2D&) = delete;
		ITexture2D(ITexture2D&&) noexcept = default;
		ITexture2D& operator=(ITexture2D&&) noexcept = default;
	public:
		virtual void Release() = 0;
	};
}

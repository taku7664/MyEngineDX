#pragma once

namespace Graphics
{
	class GraphicsDevice;

	class Shader
	{
	public:
		explicit Shader(GraphicsDevice* _pDevice, const WCHAR* _path, LPCSTR _entryPoint, LPCSTR _shaderModel);
		virtual ~Shader();
	public:
		LPVOID __stdcall GetBufferPointer() { return pBlob->GetBufferPointer(); }
		SIZE_T __stdcall GetBufferSize() { return pBlob->GetBufferSize(); }
	protected:
		const WCHAR* mPath;
		ID3D10Blob* pBlob;
	};
	class VertexShader : public Shader
	{
	public:
		explicit VertexShader(GraphicsDevice* _pDevice, const WCHAR* _path, LPCSTR _entryPoint, LPCSTR _shaderModel);
		virtual ~VertexShader();
	private:
		ID3D11VertexShader* mVertexShader;
	};
	class PixelShader : public Shader
	{
	public:
		explicit PixelShader(GraphicsDevice* _pDevice, const WCHAR* _path, LPCSTR _entryPoint, LPCSTR _shaderModel);
		virtual ~PixelShader();
	public:
		ID3D11PixelShader* mPixelShader;
	};
}


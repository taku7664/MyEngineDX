#include "pch.h"
#include "IGraphics.h"
#include "D3DGraphicsDevice.h"

namespace Graphics
{

	HRESULT CreateID3D11GraphicsDeviceAndRenderer(IGraphicsDevice** _ppDevice, IRenderer** _ppRenderer)
	{
		ID3D11Device* pDevice;
		IDXGIFactory* pFactory;
		IDXGIAdapter3* pDXGIAdapter;
		ID3D11DeviceContext* pContext;

		{
			UINT creationFlags = 0;
			HRESULT hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, creationFlags, nullptr,
				0, D3D11_SDK_VERSION, &pDevice, nullptr, &pContext);
			if (hr != S_OK)
				return hr;
		}
		
		{
			HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);
			if (hr != S_OK)
				return hr;
		}

		{
			HRESULT hr = pFactory->EnumAdapters(0, reinterpret_cast<IDXGIAdapter**>(&pDXGIAdapter));
			if (hr != S_OK)
				return hr;
		}
		D3DGraphicsDevice* device = new D3DGraphicsDevice(pDevice, pFactory, pDXGIAdapter);
		D3DRenderer* renderer = new D3DRenderer(device, pContext);

		if (device)
		{
			(*_ppDevice) = device;
			if (renderer)
				(*_ppRenderer) = renderer;
			else
			{
				delete device;
				return E_OUTOFMEMORY;
			}
		}
		return S_OK;
	}
}
#include "pch.h"
#include "D3DRenderTarget.h"
#include "D3DGraphicsDevice.h"

namespace Graphics
{
	D3DRenderTarget::D3DRenderTarget(D3DGraphicsDevice* _pDevice, HWND _hWnd)
		: mGraphicsDevice(_pDevice)
	{
		RECT clientRect = {};
		LONG width = 0;
		LONG height = 0;
		if (GetClientRect(_hWnd, &clientRect)) {
			width = clientRect.right - clientRect.left;
			height = clientRect.bottom - clientRect.top;
		}
		DXGI_SWAP_CHAIN_DESC swapDesc = {};
		D3D11_TEXTURE2D_DESC depthDesc = {};

		{ // ����ü�� ����
			swapDesc.BufferCount = 1;
			swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			swapDesc.OutputWindow = mHwnd;	// ����ü�� ����� â �ڵ� ��.
			swapDesc.Windowed = true;		// â ��� ���� ����.
			swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			// �����(�ؽ�ó)�� ����/���� ũ�� ����.
			swapDesc.BufferDesc.Width = static_cast<UINT>(width);
			swapDesc.BufferDesc.Height = static_cast<UINT>(height);
			// ȭ�� �ֻ��� ����.
			swapDesc.BufferDesc.RefreshRate.Numerator = 60;
			swapDesc.BufferDesc.RefreshRate.Denominator = 1;
			// ���ø� ���� ����.
			swapDesc.SampleDesc.Count = 1;
			swapDesc.SampleDesc.Quality = 0;

			_pDevice->CreateSwapChain(&swapDesc, &mSwapChain);
		}
		
		{ // �X��&���ٽ� ���� ����
			depthDesc.Width = static_cast<UINT>(width);
			depthDesc.Height = static_cast<UINT>(height);
			depthDesc.MipLevels = 1;
			depthDesc.ArraySize = 1;
			depthDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
			depthDesc.SampleDesc.Count = 1;
			depthDesc.SampleDesc.Quality = 0;
			depthDesc.Usage = D3D11_USAGE_DEFAULT;
			depthDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
			depthDesc.CPUAccessFlags = 0;
			depthDesc.MiscFlags = 0;

			ID3D11Texture2D* depthStencilTexture = nullptr;
			_pDevice->CreateTexture2D(&depthDesc, nullptr, &depthStencilTexture);
			_pDevice->CreateDepthStencilView(depthStencilTexture, nullptr, &mDepthStencilView);
			if (depthStencilTexture) depthStencilTexture->Release();
		}
		
		{ // ����� ����
			ID3D11Texture2D* backBufferTexture = nullptr;
			mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBufferTexture);
			_pDevice->CreateRenderTargetView(backBufferTexture, nullptr, &mRenderTargetView);
			if (backBufferTexture) backBufferTexture->Release();	//�ܺ� ���� ī��Ʈ�� ���ҽ�Ų��.
		}

		{ // ����Ʈ ����.	
			mViewPort.TopLeftX = 0;
			mViewPort.TopLeftY = 0;
			mViewPort.Width = static_cast<FLOAT>(width);
			mViewPort.Height = static_cast<FLOAT>(height);
			mViewPort.MinDepth = 0.0f;
			mViewPort.MaxDepth = 1.0f;
		}
	}

	D3DRenderTarget::~D3DRenderTarget()
	{
	}

	void D3DRenderTarget::Release()
	{
		if (mRenderTargetView)
			mRenderTargetView->Release();
		if (mDepthStencilView)
			mDepthStencilView->Release();
		if(mSwapChain)
			mSwapChain->Release();
	}

	void D3DRenderTarget::Clear()
	{
		//ClearRenderTarget(mClearColor);
		//ClearDepthStencil(1.0f, 0);
	}

	void D3DRenderTarget::ClearRenderTarget(ID3D11DeviceContext* _pContext, const FLOAT* _rgba)
	{
		if (_pContext)
		{
			//context->RSSetViewports(1, &mViewPort);
			_pContext->ClearRenderTargetView(mRenderTargetView, _rgba);
		}
	}

	void D3DRenderTarget::ClearRenderTarget(ID3D11DeviceContext* _pContext)
	{
		if (_pContext)
		{
			ClearRenderTarget(_pContext, mClearColor);
		}
	}

	void D3DRenderTarget::ClearDepthStencil(ID3D11DeviceContext* _pContext, FLOAT _depth, UINT8 _stencil)
	{
		if (_pContext)
		{
			_pContext->ClearDepthStencilView(mDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, _depth, _stencil);
		}
	}

}

#include "TestApp.h"
#include "World/TestWorld.h"

TestApp* TestApp::Instance = nullptr;

BOOL TestApp::OnPreInitialize()
{
	Instance = this;
	
	return TRUE;
}

BOOL TestApp::OnPostInitialize()
{
	GameManager* gmMng = GetGameManager();
	if (nullptr == gmMng) return FALSE;
	WorldManager* wrdMng = gmMng->GetWorldManager();
	if (nullptr == wrdMng) return FALSE;
	IGraphicsManager* grpMng = gmMng->GetGraphicsManager();
	{
		Display::WindowDesc winDecs;
		winDecs.Size = { 1024, 768 };
		winDecs.WndStyle = WS_OVERLAPPEDWINDOW;
		winDecs.WndClass.lpszClassName = L"Test";
		winDecs.WndClass.lpfnWndProc = WinProc;
		if (S_OK != CreateWindowDisplay(&winDecs, &mWindow))
		{
			return FALSE;
		}
		mWindow->SetPosition({ 500, 200 });
		Graphics::RenderTarget* pRenderTarget;
		grpMng->GetDevice()->CreateRenderTarget(mWindow->GetHandle(), &pRenderTarget);
		grpMng->GetRenderer()->SetRenderTarget(pRenderTarget);
	}
	wrdMng->CreateWorld<TestWorld>(L"TestWorld", L"Deafult");
	wrdMng->SetActiveWorld(L"TestWorld");
	return TRUE;
}

void TestApp::OnPreFinalization()
{
	
}

void TestApp::OnPostFinalization()
{
}

LRESULT CALLBACK WinProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	TestApp* pApp = TestApp::Instance;
	switch (_msg)
	{
	case WM_CREATE:
		break;

	case WM_SIZE:
		break;

	case WM_MOVE:
		break;

	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
		if (_wParam == VK_MENU)
			return 0;
		break;

	case WM_SETFOCUS:
		break;

	case WM_DESTROY:
		pApp->DestroyDisplay(_hwnd);
		break;

	case WM_CLOSE:
		pApp->ShutDown();
		break;
	default:
		return DefWindowProc(_hwnd, _msg, _wParam, _lParam);
	}
	return 0;
}
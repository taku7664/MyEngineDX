#include "TestApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    TestApp App(hInstance,
        L"Test",                // 타이틀 제목
        1024, 768,              // 윈도우 크기
        WS_OVERLAPPEDWINDOW);   // 윈도우 스타일

    if (App.Initialize())
    {
        App.Run();
    }
    App.Finalization();

    return 0;
}
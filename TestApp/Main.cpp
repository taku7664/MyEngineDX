#include "TestApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    TestApp App(hInstance,
        L"Test",                // Ÿ��Ʋ ����
        1024, 768,              // ������ ũ��
        WS_OVERLAPPEDWINDOW);   // ������ ��Ÿ��

    if (App.Initialize())
    {
        App.Run();
    }
    App.Finalization();

    return 0;
}
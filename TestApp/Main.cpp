#include "TestApp.h"
#include "EditorApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    TestApp App(hInstance,
        L"Test",                // 타이틀 제목
        1024, 768,              // 윈도우 크기
        WS_OVERLAPPEDWINDOW);   // 윈도우 스타일
#ifdef _DEBUG
    EditorApp Editor(hInstance,
        L"Editor",              // 타이틀 제목
        1024, 768,              // 윈도우 크기
        WS_OVERLAPPEDWINDOW);   // 윈도우 스타일
#endif // DEBUG

    bool InitApp = App.Initialize();
#ifdef _DEBUG
    bool InitEdit = Editor.Initialize();
#endif // DEBUG

    if (InitApp && InitEdit)
    {
        App.Run();
#ifdef _DEBUG
        Editor.Run();
#endif // DEBUG
    }

    App.Finalization();

    return 0;
}
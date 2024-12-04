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

	wrdMng->CreateWorld<TestWorld>(L"TestWorld", L"Deafult");
	wrdMng->SetActiveWorld(L"TestWorld");
	return TRUE;
}

void TestApp::OnPreFinalization()
{
	
}

void TestApp::OnPostFinalization()
{
	SAFE_DELETE(Instance)
}

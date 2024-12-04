#pragma once
#include "../MyEngineDX/Application/Application.h"

class TestApp : public Engine::Application
{
public:
	static TestApp* Instance;
	using Application::Application;
protected:
	virtual BOOL OnPreInitialize() override final;
	virtual BOOL OnPostInitialize() override final;
	virtual void OnPreFinalization() override final;
	virtual void OnPostFinalization() override final;
};
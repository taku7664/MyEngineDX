#pragma once
#include "../MyEngineDX/Application/Application.h"

class TestApp : public Engine::Application
{
public:
	using Application::Application;
protected:
	virtual void OnPreInitialize() override final;
	virtual void OnPostInitialize() override final;
	virtual void OnPreFinalization() override final;
	virtual void OnPostFinalization() override final;
};
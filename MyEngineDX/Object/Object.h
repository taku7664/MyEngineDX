#pragma once

class GameObject
	: public Engine::IEngineCycle
	, public Engine::Entity
{
public:
	GameObject();
	~GameObject();
public:
	virtual void FixedUpdate() override;
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
private:
};
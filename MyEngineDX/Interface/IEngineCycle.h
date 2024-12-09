#pragma once
namespace Graphics
{
	class GraphicsDevice;
	class Renderer;
	class RenderTarget;
}
namespace Engine
{
	class IEngineCycle
	{
		virtual void FixedUpdate() = 0;
		virtual void PreUpdate() = 0;
		virtual void Update() = 0;
		virtual void PostUpdate() = 0;
		virtual void PreRender() = 0;
		virtual void Render(GraphicsManager* _graphicsManager) = 0;
		virtual void PostRender() = 0;
	};
}
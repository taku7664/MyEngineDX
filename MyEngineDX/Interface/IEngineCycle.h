#pragma once

namespace Engine
{
	class IEngineCycle _INTERFACE
	{
		virtual void FixedUpdate() = 0;
		virtual void PreUpdate() = 0;
		virtual void Update() = 0;
		virtual void PostUpdate() = 0;
		virtual void PreRender() = 0;
		virtual void Render() = 0;
		virtual void PostRender() = 0;
	};
}
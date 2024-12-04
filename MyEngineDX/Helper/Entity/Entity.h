#pragma once

namespace Engine
{
	class Entity _ABSTRACT
	{
	public:
		void SetName(std::wstring_view _name) { m_name = _name; }
		void SetTag(std::wstring_view _tag) { m_tag = _tag; }
		void SetActive(bool _isActive);
		void SetDestroy();

		const std::wstring& GetName() { return m_name; }
		const std::wstring& GetTag() { return m_name; }
		const EntityState&  GetState() { return m_state; }
	protected:
		std::wstring m_name;
		std::wstring m_tag;

		EntityState	 m_state;

		Entity() : m_name(L""), m_tag(L""), m_state(EntityState::Create) { OnCreate(); }
		Entity(std::wstring_view _name, std::wstring_view _tag)
			: m_name(_name), m_tag(_tag), m_state(EntityState::Create) {
			OnCreate();
		}
	protected:
		virtual void _CALLBACK OnEnable() {};
		virtual void _CALLBACK OnDisable() {};
		virtual void _CALLBACK OnCreate() {};
		virtual void _CALLBACK OnDestroy() {};
	};
}

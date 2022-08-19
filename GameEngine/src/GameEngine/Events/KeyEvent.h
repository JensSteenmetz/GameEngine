#pragma once

#include "Event.h"

#include <sstream>

namespace GameEngine
{

	class ENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard || EventCategoryInput);

	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode)
		{}

	private:
		int m_KeyCode;
	};


	class ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << GetKeyCode() << " (" << GetRepeatCount() << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_RepeatCount;
	};


	class ENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << GetKeyCode();
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};
}
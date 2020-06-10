#pragma once

#include "Event.h"

#include <sstream>

namespace Coffee {
	/*
		Mouse moved event
		Contains the new X and Y position of the mouse
		Available via GetX and GetY
	*/
	class COFFEE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }

		std::string ToString() {
			std::stringstream ss;
			ss << "Mouse moved to : " << m_MouseX << " : " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_MouseX, m_MouseY;
	};

	/*
		Mouse scrolled event
		Contains the scroll offset
	*/
	class COFFEE_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float offx, float offy) : m_XOffset(offx), m_YOffset(offy) {}

		inline float GetXoffset() { return m_XOffset; }
		inline float GetYOffset() { return m_YOffset; }

		std::string ToString() {
			std::stringstream ss;
			ss << "Mouse scrolled for : " << m_XOffset << " : " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_XOffset, m_YOffset;
	};

	/*
		Base class for mouse button events
		store the concerned button code
	*/
	class COFFEE_API MouseButtonEvent : public Event {
	public:
		inline int GetButton() { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}
		int m_Button;
	};

	/*
		When a mouse button is pressed
	*/
	class COFFEE_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
		
		std::string ToString() {
			std::stringstream ss;
			ss << "Mouse button pressed : " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	/*
		When a mouse button is released
	*/
	class COFFEE_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() {
			std::stringstream ss;
			ss << "Mouse button released : " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
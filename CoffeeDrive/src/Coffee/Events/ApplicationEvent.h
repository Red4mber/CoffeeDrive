#pragma once

#include "Event.h"

namespace Coffee {

	/*
	##########
		WINDOW EVENTS
	##########
	*/
	/*
		Window resize event
		contains the new width and height of the window
	*/
	class COFFEE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int w, unsigned int h) : m_Width(w), m_Height(h) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window resized to : " << m_Width << " * " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	/*
		Window moved event
		contains the new position of the window
	*/
	class COFFEE_API WindowMovedEvent : public Event {
	public:
		WindowMovedEvent(int x, int y) : m_WindowX(x), m_WindowY(y) {}

		inline unsigned int GetWidth() const { return m_WindowX; }
		inline unsigned int GetHeight() const { return m_WindowY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window moved to : " << m_WindowX << " * " << m_WindowY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowMoved)

	private:
		unsigned int m_WindowX, m_WindowY;
	};

	/*
		Window closed event
	*/
	class COFFEE_API WindowClosedEvent : public Event {
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	/*
		Window focus event
	*/
	class COFFEE_API WindowFocusEvent : public Event {
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowFocus)
	};

	/*
		Window unfocus event
	*/
	class COFFEE_API WindowLostFocusEvent : public Event {
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowLostFocus)
	};

	/*
	##########
		APPLICATION EVENTS
	##########
	*/
	/*
		App tick
		Triggered each tick
	*/
	class COFFEE_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(AppTick)
	};
	/*
	App Update
	*/
	class COFFEE_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};
	/*
	App render
	Triggered each frame
	*/
	class COFFEE_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};

}
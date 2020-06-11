#pragma once

#include "cf_pch.h"

#include "Coffee/Core.h"
#include "Coffee/Events/Event.h"

namespace Coffee {

	
	//	Structure containing window properties (title width and height
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// Default properties
		WindowProps(std::string title = "CoffeeDrive Engine",
					unsigned int width = 1280,
					unsigned int height = 720) : 
					Title(title), Width(width), Height(height) {}
	};

	// Just an interface representing a window
	// Everything is virtual, it'll be implemented per platform
	class COFFEE_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}
#pragma once

#include "Core.h"

#include "Window.h"
#include "Coffee/LayerStack.h"
#include "Coffee/Events/Event.h"
#include "Coffee/Events/ApplicationEvent.h"

namespace Coffee {
	class COFFEE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

	private:
		LayerStack m_LayerStack;

		bool OnWindowClosed(WindowClosedEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in Client
	Application* CreateApplication();
}



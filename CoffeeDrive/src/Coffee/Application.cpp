#include "cf_pch.h"
#include "Application.h"

#include "Coffee/Events/ApplicationEvent.h"
#include "Coffee/Log.h"
#include <GLFW/glfw3.h>

namespace Coffee {
	Application::Application(){
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	
	
	Application::~Application(){
	
	}

	void Application::Run() {
		while (m_Running) { // App Loop
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}

#include "cf_pch.h"
#include "Application.h"

#include "Coffee/Log.h"
#include "Coffee/Events/ApplicationEvent.h"


namespace Coffee {
	Application::Application(){

	}
	
	
	Application::~Application(){
	
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		CF_TRACE(e.ToString());

		while (true) {

		}
	}
}

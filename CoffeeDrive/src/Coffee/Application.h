#pragma once

#include "Core.h"

namespace Coffee {
	class COFFEE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}



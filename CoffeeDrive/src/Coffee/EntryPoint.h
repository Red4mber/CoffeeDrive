#pragma once

#ifdef CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv) {

	Coffee::Log::Init();
	CF_CORE_WARN("CoffeeDrive Engine started");
	CF_INFO("Client says hello");
	auto app = Coffee::CreateApplication();

	app->Run();
	
	delete app;


	return 0;
}

#endif
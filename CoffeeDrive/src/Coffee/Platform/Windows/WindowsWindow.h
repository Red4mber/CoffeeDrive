#pragma once

#include "Coffee/Window.h"
#include "GLFW/glfw3.h"

namespace Coffee {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		unsigned int GetWidth() const override { return m_Data.Width; };
		unsigned int GetHeight() const override { return m_Data.Height; };

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void OnUpdate() override;

	// Private Methods
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	// Private 
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			EventCallbackFn EventCallback;
			bool VSync;
		};

		WindowData m_Data;
	};
}
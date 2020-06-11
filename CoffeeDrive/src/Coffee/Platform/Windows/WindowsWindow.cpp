#include "cf_pch.h"
#include "WindowsWindow.h"
#include "Coffee/Log.h"

namespace Coffee {
	bool glfwinit = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		CF_CORE_INFO("Creating the window \"{0}\" - size : {1} : {2}", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!glfwinit) {
			bool status = glfwInit();
			CF_CORE_ASSERT(status, "Cannot initialize GLFW");
			glfwinit = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		// 0 if disabled = no FPS limit
		// 1 if enabled  = Framerate FPS limit
		glfwSwapInterval((int)enabled); 
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

}
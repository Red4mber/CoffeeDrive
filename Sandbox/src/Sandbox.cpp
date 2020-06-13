#include <Coffee.h>

class ExampleLayer : public Coffee::Layer
{
public:
	ExampleLayer() : Layer() {
	}

	void OnUpdate() override {
		CF_INFO("ExampleLayer::Update");
	}

	void OnEvent(Coffee::Event& event) override {
		CF_TRACE("{0}", event.ToString());
	}

};

class Sandbox : public Coffee::Application
{
public:
	Sandbox() {
		pushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}

};

Coffee::Application* Coffee::CreateApplication() {
	return new Sandbox();
}
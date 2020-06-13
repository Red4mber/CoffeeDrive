#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Coffee {
	class COFFEE_API Layer {
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};
	};
}
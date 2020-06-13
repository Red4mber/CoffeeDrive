#pragma once
#include "Coffee/Core.h"
#include "Layer.h"

#include <vector>

namespace Coffee {
	class COFFEE_API LayerStack {
	public:
		LayerStack();
		~LayerStack();
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Stack.begin(); }
		std::vector<Layer*>::iterator end() { return m_Stack.end(); }
	private:
		std::vector<Layer*> m_Stack;
		std::vector<Layer*>::iterator m_Iterator;
	};
}
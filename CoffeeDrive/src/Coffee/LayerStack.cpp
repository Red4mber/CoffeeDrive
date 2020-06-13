#include "cf_pch.h"
#include "LayerStack.h"

namespace Coffee {
	LayerStack::LayerStack() {
		m_Iterator = m_Stack.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer* l : m_Stack) {
			delete l;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		m_Iterator = m_Stack.emplace(m_Iterator, layer);
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(m_Stack.begin(), m_Stack.end(), layer);
		if (it != m_Stack.end()) {
			m_Stack.erase(it);
			m_Iterator--;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		m_Stack.emplace_back(overlay);
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(m_Stack.begin(), m_Stack.end(), overlay);
		if (it != m_Stack.end()) {
			m_Stack.erase(it);
		}
	}
}
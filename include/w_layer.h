
//   Copyright 2023 Metehan Gezer
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "w_pch.h"
#include "w_renderer.h"
#include "events/w_events.h"

namespace Wiesel {
	class Layer {
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate(float_t deltaTime) = 0;
		virtual void OnEvent(Event& event) = 0;

	private:
		uint32_t m_Id;
		friend class Application;
	};
}
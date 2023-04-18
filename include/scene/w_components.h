
//
//    Copyright 2023 Metehan Gezer
//
//     Licensed under the Apache License, Version 2.0 (the "License");
//     you may not use this file except in compliance with the License.
//     You may obtain a copy of the License at
//
//         http://www.apache.org/licenses/LICENSE-2.0
//

#pragma once

#include "w_pch.h"
#include "util/w_utils.h"
#include "util/w_uuid.h"
#include "rendering/w_texture.h"
#include "rendering/w_buffer.h"
#include "rendering/w_descriptor.h"

namespace Wiesel {
	struct IdComponent {
		IdComponent(UUID id) : Id(id) {}
		IdComponent() = default;
		IdComponent(const IdComponent&) = default;

		UUID Id;
	};

	struct TagComponent {
		TagComponent() = default;
		TagComponent(const TagComponent&) = default;

		std::string Tag;
	};

	struct TransformComponent {
		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;

		glm::vec3 GetForward();
		glm::vec3 GetBackward();
		glm::vec3 GetLeft();
		glm::vec3 GetRight();
		glm::vec3 GetUp();
		glm::vec3 GetDown();
		void UpdateMatrices();

		glm::vec3 Position = {0.0f, 0.0f, 0.0f};
		glm::vec3 Rotation = {0.0f, 0.0f, 0.0f};
		glm::vec3 Scale    = {1.0f, 1.0f, 1.0f};

		bool IsChanged = true;
		glm::mat4 TransformMatrix = {};
		glm::mat3 NormalMatrix = {};
		glm::mat4 RotationMatrix = {};
	};

#define ALL_COMPONENT_TYPES IdComponent, TagComponent, TransformComponent, ModelComponent, LightDirectComponent, LightPointComponent, CameraComponent

}
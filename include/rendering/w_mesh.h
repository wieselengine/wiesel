
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
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/cimport.h>

#include "rendering/w_buffer.h"
#include "rendering/w_texture.h"
#include "rendering/w_descriptor.h"
#include "rendering/w_material.h"
#include "scene/w_components.h"

namespace Wiesel {
	struct Mesh {
		Mesh();
		Mesh(std::vector<Vertex> vertices, std::vector<Index> indices);
		~Mesh();

		void UpdateUniformBuffer(TransformComponent& transform) const;
		void Allocate();
		void Deallocate();

		std::vector<Vertex> Vertices;
		std::vector<Index> Indices;
		std::string ModelPath;

		bool IsAllocated;
		// Render Data
		Reference<MemoryBuffer> VertexBuffer;
		Reference<MemoryBuffer> IndexBuffer;
		Reference<UniformBufferSet> UniformBufferSet;
		Reference<Material> Mat;

		Reference<DescriptorData> Descriptors;
	};

	struct Model {
		Model() = default;
		~Model() = default;

		std::vector<Reference<Mesh>> Meshes;
		std::string ModelPath;
		std::string TexturesPath;
		std::map<std::string, Reference<Texture>> Textures;
		bool ReceiveShadows = true; // todo shadows
	};

	struct ModelComponent {
		ModelComponent() = default;
		ModelComponent(const ModelComponent&) = default;

		Model Data;
	};
}
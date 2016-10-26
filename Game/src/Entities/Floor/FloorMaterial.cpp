#include "FloorMaterial.h"

#include <glm/vec4.hpp>
#include <glm/mat3x3.hpp>

using namespace sag;
using namespace sagame;


FloorMaterial::FloorMaterial()
{
	shader.attachShader(".\\src\\ShaderSource\\solidcolor.vs", sag::VERTEX);
	shader.attachShader(".\\src\\ShaderSource\\solidcolor.fs", sag::FRAGMENT);

	shader.bindAttribLocation(0, "VertexPosition");

	shader.link();
}

void FloorMaterial::apply(const glm::mat4& model, const glm::mat4& view, const glm::mat4& modelViewProjection, const std::list<sag::Light*>& lights)
{
	shader.use();
	shader.setUniform("Color", glm::vec4(0.3f, 0.5f, 0.3f, 1.0f));
	shader.setUniform("MVP", modelViewProjection);
}

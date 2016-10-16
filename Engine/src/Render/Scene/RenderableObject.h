#ifndef SAG_RENDERABLE_OBJECT_H
#define SAG_RENDERABLE_OBJECT_H

#include "MoveableObject.h"
#include "../Geometry/Geometry.h"
#include "../Material/Material.h"

#include <utility>


namespace sag
{

class RenderableObject : public MoveableObject
{
public:
	RenderableObject()
	{}

	RenderableObject(Material&& material) :
		material(std::move(material))
	{}

	RenderableObject(Material&& material, Geometry&& geometry) :
		material(std::move(material)), geometry(std::move(geometry))
	{}

	virtual void setGeometry(Geometry&& geometry) { this->geometry = geometry; };

	virtual void render(const glm::mat4& projection) = 0;

protected:

	Material material;
	Geometry geometry;

};

} // namespace sag


#endif // SAG_RENDERABLE_OBJECT_H
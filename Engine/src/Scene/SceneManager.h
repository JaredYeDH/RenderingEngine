#ifndef SAG_SCENE_MANAGER_H
#define SAG_SCENE_MANAGER_H

#include <memory>

#include "SceneNode.h"
#include "../Render/RenderableObject.h"
#include "../Render/Light/Light.h"
#include "../Render/Camera/Camera.h"


namespace sag
{

class SceneManager
{
public:
	static SceneManager& getInstance();

	void setMainCamera(const Camera& camera);
	void registerRenderableObject(RenderableObject& obj);
	void deregisterRenderableObject(RenderableObject& obj);

	std::weak_ptr<SceneNode> getRootSceneNode() const { return rootSceneNode; }
	const Camera& getMainCamera() const { return *mainCamera;  }
	const std::list<RenderableObject*>& getRenderableObjects() const;

	void registerLight(Light& obj);
	void deregisterLight(Light& obj);
	const std::list<Light*>& getLights() const;


private:
	SceneManager();
	SceneManager(const SceneManager& other) = delete;
	SceneManager(SceneManager&& other) = delete;
	SceneManager& operator=(const SceneManager& other) = delete;
	SceneManager& operator=(SceneManager&& other) = delete;
	~SceneManager();


	std::shared_ptr<SceneNode> rootSceneNode;
	const Camera* mainCamera;
	std::list<RenderableObject*> renderableObjects;
	std::list<Light*> lights;

};

} // namespace sag


#endif // SAG_SCENE_MANAGER_H

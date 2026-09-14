#pragma once

#include <string>

class Scene;
struct GameObject;

namespace Umbrella
{
	class IComponent
	{
		private:
			std::string _gameObjectId;
			std::string _componentInstanceId;
            Scene *_scene;

		public:

            IComponent(std::string gameObjectId, Scene *scene, std::string componentId)
            {
                _gameObjectId = gameObjectId;
                _scene = scene;
                _componentInstanceId = componentId;
            }

			virtual void OnStartUp() {}
			virtual void OnInit() {}
			virtual void OnEnable() {}
			virtual void OnDisable() {}
			virtual void OnDestroy() {}

			virtual void OnUpdate(float deltaTime) {}
			virtual void OnUpdateData(float dataDeltaTime) {}

			GameObject* GetGameObject()
			{
				return nullptr;
			}

			Scene* GetScene() { return _scene; }
			std::string GetInstanceId() { return _componentInstanceId; }
			
	};
}

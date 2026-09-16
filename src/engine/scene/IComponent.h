#pragma once

#include <string>

struct GameObject;

namespace Umbrella
{
    class Scene;

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

            void SetGameObejct(GameObject* gameobejct)
            {
                _gameObjectId = gameobejct->Id;
            }

            void SetScene(Scene* scene)
            {
                _scene = scene;
            }

			GameObject* GetGameObject()
			{
				return nullptr;
			}

			Scene* GetScene() { return _scene; }
			std::string GetInstanceId() { return _componentInstanceId; }
	};
}

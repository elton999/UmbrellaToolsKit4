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

            bool _isEnable = true;
            bool _isStartUp = false;
            bool _isStarted = false;

		public:
            Umbrella::IComponent(std::string gameObjectId, Scene *scene, std::string componentId)
            {
                _gameObjectId = gameObjectId;
                _scene = scene;
                _componentInstanceId = componentId;
            }

            void Inicialization();

            void InicializationFirstFrame();

			virtual void OnStartUp() {}
			virtual void OnInit() {}
			virtual void OnEnable() {}
			virtual void OnDisable() {}
			virtual void OnDestroy() {}

			virtual void OnUpdate(float deltaTime) {}
			virtual void OnUpdateData(float dataDeltaTime) {}

            void SetGameObject(GameObject* gameobejct);
            void SetScene(Scene* scene);
            GameObject* GetGameObject();
            Umbrella::Scene* GetScene();
            std::string GetInstanceId();
            void SetActive(bool status);
            bool GetActiveStatus();
	};
}

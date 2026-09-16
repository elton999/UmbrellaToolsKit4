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

            IComponent(std::string gameObjectId, Scene *scene, std::string componentId)
            {
                _gameObjectId = gameObjectId;
                _scene = scene;
                _componentInstanceId = componentId;
            }

            void Inicialization()
            {
                if (!GetActiveStatus()) return;
                if (!_isStartUp)
                    {
                    OnStartUp();
                    _isStartUp = true;
                    }
            }

            void InicializationFirstFrame()
            {
                if (!GetActiveStatus()) return;
                if (!_isStartUp)
                {
                    OnStartUp();
                    _isStartUp = true;
                }

                if (!_isStarted)
                {
                    OnInit();
                    OnEnable();
                    _isStarted = true;
                }
            }

			virtual void OnStartUp() {}
			virtual void OnInit() {}
			virtual void OnEnable() {}
			virtual void OnDisable() {}
			virtual void OnDestroy() {}

			virtual void OnUpdate(float deltaTime) {}
			virtual void OnUpdateData(float dataDeltaTime) {}

            void SetGameObject(GameObject* gameobejct)
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

            void SetActive(bool status) { _isEnable = status; }

            bool GetActiveStatus() { return _isEnable && GetGameObject()->IsEnable; }
	};
}

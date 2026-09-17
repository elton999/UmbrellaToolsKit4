#pragma once

#include <list>
#include "../core/UniqueId.h"
#include "../core/debug/Log.h"
#include "IComponent.h"
#include "GameObject.h"

struct GameObject;

namespace Umbrella
{
    class Icomponent;

	class Scene
	{
		private:
			std::list<GameObject*> _gameObjects = {};
			std::list<IComponent*> _components = {};
            bool _isEnable = true;

		public:
			void AddGameObject(GameObject * gameObject);
			GameObject * CreateGameObject();
            void RemoveGameObject(GameObject* gameObject);

			template <typename TComponent>
			TComponent* AddComponent(GameObject* gameObject)
            {
                if (!HasGameObject(gameObject))
                {
                    Log::MsgError("GameObject not found in the current scene");
                    return nullptr;
                }
                TComponent* result;
                try
                {
                    IComponent* resultComponent = dynamic_cast<IComponent*>(new TComponent(gameObject->Id, this, UniqueId::GetId()));
                    result = dynamic_cast<TComponent*>(resultComponent);
                    _components.push_back(result);
                    result->Inicialization();
                }
                catch (std::exception e)
                {
                    result = nullptr;
                }

                return result;
            }

            void AddComponent(GameObject* gameObejct, IComponent* componet);
			void RemoveComponent(IComponent* component);
            bool HasComponent(IComponent* component);

            void DestroyGameObject(GameObject* gameObjec);
            void SetActive(GameObject* gameObject, bool status);

            bool HasGameObject(GameObject* gameObject);
			void Update(float deltaTime);
			void UpdateData(float deltaTime);

            void SetActiveScene(bool status);
            void UnloadScene();

            GameObject* GetGameObject(std::string gameObjectId);
	};
}

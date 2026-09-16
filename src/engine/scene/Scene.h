#pragma once

#include <list>
#include "GameObject.h"
#include "IComponent.h"
#include "../core/UniqueId.h"
#include "../core/debug/Log.h"

namespace Umbrella
{
	class Scene
	{
		private:
			std::list<GameObject*> _gameObjects = {};
			std::list<IComponent*> _components = {};

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
                    result = dynamic_cast<TComponent*>(result);
                    _components.push_back(result);
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

            bool HasGameObject(GameObject* gameObject);
			void Update(float deltaTime);
			void UpdateData(float deltaTime);
	};
}

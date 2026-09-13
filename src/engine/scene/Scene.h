#pragma once

#include <list>
#include "GameObject.h"
#include "IComponent.h"

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
			TComponent* AddComponent(GameObject* gameObject);
            void AddComponent(GameObject* gameObejct, IComponent* componet);
			void RemoveComponent(GameObject* gameObject, IComponent* component);
            bool HasComponent(GameObject* gameObject, IComponent* component);

            bool HasGameObject(GameObject* gameObject);
			void Update(float deltaTime);
			void UpdateData(float deltaTime);
	};
}

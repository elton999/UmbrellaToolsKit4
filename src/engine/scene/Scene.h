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
			void AddGameObject(GameObject * gameObject) {}
			GameObject * CreateGameObject() { return nullptr; }

			template <typename TComponent>
			TComponent* AddComponent(GameObject* gameObject){ return nullptr }
			void RemoveComponent(IComponent* component) {}

			void Update(float deltaTime) {};
			void UpdateData(float deltaTime) {};
	};
}

#pragma once

#include <string>
#include "Scene.h"
#include "GameObject.h"

namespace Umbrella
{
	class IComponent
	{
		private:
			std::string _gameObjectId;
			std::string _componentInstanceId;
			Scene* _scene;

		public:
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

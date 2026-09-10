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
			Scene* _scene;

		public:
			virtual void OnStartUp() {}
			virtual void OnInit() {}
			virtual void OnEnable() {}
			virtual void OnDisable() {}
			virtual void OnDestroy() {}

			virtual void OnUpdate(float deltaTime) {}
			virtual void OnFixedUpdate(float dataDeltaTime) {}

			GameObject* GetGameObject() { return nullptr; }
			Scene* GetScene() {return _scene; }
			
	};
}

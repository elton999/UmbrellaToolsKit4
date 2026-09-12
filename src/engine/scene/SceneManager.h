#pragma once
#include "Scene.h"

namespace Umbrella
{
    class SceneManager
    {
        public:
            void StartUp();
            void Run();
            void ShutDown();

            Scene* CreateScene();
            void LoadScene(Scene* scene);
            void UnloadScene(Scene* scene);
            bool IsSceneLoaded(Scene* scene);
    };
}

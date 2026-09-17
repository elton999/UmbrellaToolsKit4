#pragma once

#include <list>

namespace Umbrella
{
    class UmbrellaRoot;
    class Scene;
    class Timer;

    class SceneManager
    {
        private:
            std::list<Scene*> _scenes;
            UmbrellaRoot* _umbrellaRoot;
            Timer* _timer;
            float _dataDeltaTimerCoolDown;
            float _maxDataDeltaTimer;

        public:
            SceneManager(UmbrellaRoot* root);

            void StartUp();
            void Run();
            void ShutDown();

            Scene* CreateScene();
            void LoadScene(Scene* scene);
            void UnloadScene(Scene* scene);
            bool IsSceneLoaded(Scene* scene);

            UmbrellaRoot* GetUmbrellaRoot();
    };
}

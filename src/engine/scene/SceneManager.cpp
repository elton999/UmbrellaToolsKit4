#include "SceneManager.h"
#include "../UmbrellaRoot.h"
#include "Scene.h"
#include "core/Timer.h"

Umbrella::SceneManager::SceneManager(UmbrellaRoot* root)
{
    _umbrellaRoot = root;
    _timer = _umbrellaRoot->Timer;
    _maxDataDeltaTimer = 1.0f / 30.0f;
}

void Umbrella::SceneManager::StartUp()
{
    _scenes = {};
}

void Umbrella::SceneManager::Run()
{
    _dataDeltaTimerCoolDown += _timer->GetDelta();
    for (auto scene : _scenes)
    {
        scene->Update(_timer->GetDelta());
        if (_dataDeltaTimerCoolDown >= _maxDataDeltaTimer)
        {
            scene->UpdateData(_dataDeltaTimerCoolDown);
        }
    }
    _dataDeltaTimerCoolDown = 0.0;
}

void Umbrella::SceneManager::ShutDown()
{
    std::list<Scene*> cloneList = _scenes;
    for (auto scene : cloneList)
    {
        UnloadScene(scene);
    }

    cloneList.clear();
    _scenes.clear();
}

Umbrella::Scene* Umbrella::SceneManager::CreateScene()
{
    Umbrella::Scene* scene = new Umbrella::Scene();
    scene->SetSceneManager(this);
    return scene;
}

void Umbrella::SceneManager::LoadScene(Scene* scene)
{
    if (IsSceneLoaded(scene))
    {
        return;
    }
    _scenes.push_back(scene);
}

void Umbrella::SceneManager::UnloadScene(Scene* scene)
{
    scene->UnloadScene();
    _scenes.remove(scene);
}

bool Umbrella::SceneManager::IsSceneLoaded(Scene* scene)
{
    for (Umbrella::Scene* sceneItem : _scenes)
    {
        if (scene == sceneItem)
        {
            return true;
        }
    }

    return false;
}

Umbrella::UmbrellaRoot* Umbrella::SceneManager::GetUmbrellaRoot()
{
    return _umbrellaRoot;
}

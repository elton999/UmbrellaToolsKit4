#pragma once
#include <glm/glm.hpp>
#include "../scene/IComponent.h"
#include "../scene/Scene.h"
#include "../scene/SceneManager.h"
#include "../UmbrellaRoot.h"

namespace Umbrella
{
    class IRenderComponent : public IComponent
    {
        private:
            glm::vec3 _position;

        public:
            IRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : IComponent(gameObjectId, scene, componentId)
            {
                if (scene->GetSceneManager() != nullptr)
                    scene->GetSceneManager()->GetUmbrellaRoot()->RenderManager->AddRenderComponent(this);
            }

            void SetPosition(glm::vec3 position)
            {
                _position = position;
            }

            glm::vec3 GetPosition()
            {
                return _position;
            }

            void OnDestroy() override
            {
                GetScene()->GetSceneManager()->GetUmbrellaRoot()->RenderManager->RemoveRenderComponet(this);
            }

            virtual void Draw(){}
    };
}

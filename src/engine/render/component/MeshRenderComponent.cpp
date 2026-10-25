#include "MeshRenderComponent.h"

#include "../../scene/camera/Camera.h"
#include "../../scene/camera/CameraManager.h"
#include "../Material.h"
#include "../Mesh.h"

void Umbrella::MeshRenderComponent::SetMaterial(Umbrella::Material* material)
{
    _material = material;
}

Umbrella::Material* Umbrella::MeshRenderComponent::GetMaterial()
{
    if (HasMaterial())
        return _material;
    return nullptr;
}

bool Umbrella::MeshRenderComponent::HasMaterial()
{
    if (_material == nullptr)
        return false;
    return true;
}

void Umbrella::MeshRenderComponent::SetMesh(Mesh* mesh)
{
    _mesh = mesh;
}

Umbrella::Mesh* Umbrella::MeshRenderComponent::GetMesh()
{
    if (HasMesh())
        return _mesh;
    return nullptr;
}

bool Umbrella::MeshRenderComponent::HasMesh()
{
    if (_mesh == nullptr)
        return false;
    return true;
}

void Umbrella::MeshRenderComponent::Draw()
{
    if (!HasMesh())
        return;
    if (!HasMaterial())
        return;

    GetMaterial()->Use();

    glBindVertexArray(GetMesh()->GetVAO());
    glDrawArrays(GL_TRIANGLES, 0, GetMesh()->GetVerticesCount());
    glBindVertexArray(0);
}

Umbrella::Camera* Umbrella::MeshRenderComponent::GetCamera()
{
    std::string layer = GetScene()->GetSceneManager()->GetUmbrellaRoot()->RenderManager->GetComponentLayer(this);
    return GetScene()->GetSceneManager()->GetUmbrellaRoot()->CameraManager->GetCamera(layer);
}

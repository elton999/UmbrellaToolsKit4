#include "MeshRenderComponent.h"

#include "../Material.h"
#include "../Mesh.h"

void Umbrella::MeshRenderComponent::SetMaterial(Umbrella::Material)
{

}

Umbrella::Material Umbrella::MeshRenderComponent::GetMaterial()
{
    return nullptr;
}

bool Umbrella::MeshRenderComponent::HasMaterial()
{
    return false;
}

void Umbrella::MeshRenderComponent::SetMesh(Mesh mesh)
{
}

Umbrella::Mesh Umbrella::MeshRenderComponent::GetMesh()
{
    return nullptr;
}

bool Umbrella::MeshRenderComponent::HasMesh()
{
    return false;
}

void Umbrella::MeshRenderComponent::Draw()
{

}

#include "WorldObject.h"

WorldObject::WorldObject(WorldObjectType worldObjectType)
    : m_worldObjectType(worldObjectType)
{}

const char* WorldObject::GetWorldObjectTypeString(WorldObjectType worldObjectType)
{
    switch (worldObjectType)
    {
        case WorldObjectType::kFloor:
            return "Floor";
        case WorldObjectType::kRocket:
            return "Rocket";
        case WorldObjectType::kAssembler:
            return "Assembler";
        case WorldObjectType::kResource:
            return "Resource";
        default:
            return "Failed to find world Object...";
    }
}

const char* WorldObject::PrintComponentType(ComponentType componentType)
{
    switch (componentType)
    {
    case WorldObject::ComponentType::kCpu:
        return "CPU";
    case WorldObject::ComponentType::kEngine:
        return "Engine";
    case WorldObject::ComponentType::kBooster:
        return "Booster";
    default:
        return "Failed to find component...";
    }
}

const char* WorldObject::PrintResourceType(ResourceType resourceType)
{
    switch (resourceType)
    {
        case WorldObject::ResourceType::kIron:
            return "Iron";
        case WorldObject::ResourceType::kCopper:
            return "Copper";
        case WorldObject::ResourceType::kGold:
            return "Gold";
        case WorldObject::ResourceType::kCobalt:
            return "Cobalt";
        default:
            return "failed to find component....";
    }
}
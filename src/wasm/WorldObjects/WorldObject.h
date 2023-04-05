#pragma once
#include <iostream>
#include <unordered_map>
#include "IWorldObject.h"
class Player;

class WorldObject:
    public IWorldObject
{
public:
    enum class WorldObjectType
    {
        kFloor,
        kResource,
        kWOcount,
        kRocket,
        kAssembler,
        kComponent
    };
    enum class ComponentType
    {
        kNull,
        kCpu,
        kBooster,
        kEngine
    };

    enum class ResourceType
    {
        kNull,
        kIron,
        kCopper,
        kGold,
        kCobalt
    };

private:
    WorldObjectType m_worldObjectType;
public:
    WorldObject(WorldObjectType worldObjectType);

    void Draw() override {};

    void Action(Player& player) override {};

    static const char* GetWorldObjectTypeString(WorldObjectType worldObjectType);

    const WorldObjectType& GetWorldObjectType() { return m_worldObjectType; }

    static const char* PrintComponentType(ComponentType componentType);

    static const char* PrintResourceType(ResourceType resourceType);
};


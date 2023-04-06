#pragma once
#include "../WorldObject.h"
#include "../../Player/Player.h"

class Component: public WorldObject
{
private:
    const WorldObject::ComponentType m_kComponent;
public:
    Component(WorldObject::ComponentType kComponent);

    void Draw() override;

    void Action(Player& player) override;

    const ComponentType& ComponentType() { return m_kComponent; }
};


#pragma once
#include <iostream>
#include "../WorldObject.h"
#include "../../Player/Player.h"

class Resource :
    public WorldObject
{
private:
    const ResourceType m_kResource;
    int m_amount;
public:
    Resource(ResourceType type, int amount);

    void Draw() override;

    const int& GetAmount() { return m_amount; };

    void Action(Player& player) override;

    const ResourceType& GetResourceType() { return m_kResource; }
};


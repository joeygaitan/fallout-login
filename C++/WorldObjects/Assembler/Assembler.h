#pragma once
#include <iostream>
#include "WorldObject.h"
#include "Player.h"
#include <map>

class Assembler :
    public WorldObject
{
private:
    std::map<ComponentType, std::map<ResourceType, int>> m_storeInventory;

public:
    Assembler(std::map<ComponentType, std::map<ResourceType, int>> storeInventory);

    void Draw() override;

    // Player Interface
    void Action(Player& player) override;

    // Displays the player store.
    void DisplayStore();
};


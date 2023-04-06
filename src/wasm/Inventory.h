#pragma once
#include <iostream>
#include "WorldObject.h"
#include <vector>
#include <map>

class Inventory
{
public:
    enum class InventoryActionType
    {
        kAddOne
    };

    // Test Data.
    constexpr static inline int s_kPopulateInventory = 0;
private:
    std::vector<std::pair<WorldObject*, int>> m_inventory;

public:
    Inventory();
    
    ~Inventory();

    // Displays your inventory at the top of the screen.
    void DisplayInventory();

    // Allows the user the ability to pick up an item.
    void ModifyItem(WorldObject* pWorldObject, InventoryActionType inventoryAction, int amount);

    // Find and add a resource or it will add a new one to your inventory.
    void FindResource(WorldObject* pWorldObject);

    // Find adn add a component by component enum type.
    void FindComponentByType(WorldObject::ComponentType componentType);

    // Finds component by Inventory if not found it will then create a new slot for you.
    void FindComponent(WorldObject* pWorldObject);

    // It looks to see if you have this component already in your inventory.
    bool FindComponentItem(WorldObject::ComponentType componentType);

    // Checks if you can afford it by a price map. If you can it returns true.
    bool CanAfford(std::map<WorldObject::ResourceType, int> amount);

    // Handles the purchasing functionality for Assembling something.
    void Purchase(WorldObject::ComponentType componentType, std::map<WorldObject::ResourceType, int> amount);
};


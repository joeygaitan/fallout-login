#include "Inventory.h"
#include "../../WorldObjects/Resource/Resource.h"
#include "../../WorldObjects/Component/Component.h"

Inventory::Inventory()
    : m_inventory({})
{
    if (s_kPopulateInventory)
    {
        m_inventory = { {new Component(WorldObject::ComponentType::kCpu), 5}, {new Component(WorldObject::ComponentType::kBooster), 5}, {new Component(WorldObject::ComponentType::kEngine), 5} };
    }
}

Inventory::~Inventory()
{
    for (auto& [object, amount] : m_inventory)
    {
        delete object;
        object = nullptr;
    }
    m_inventory.clear();
}

void Inventory::DisplayInventory()
{
    int count = 0;
    for (auto& [pWorldObject, amount] : m_inventory)
    {
        std::cout << " [ ";
        pWorldObject->Draw();
        std::cout << ": " << amount << "] ";
        ++count;
    }
    if (count <= 0)
    {
        std::cout << "Inventory is empty :/....";
    }
    std::cout << "\n";
}

void Inventory::ModifyItem(WorldObject* pWorldObject, InventoryActionType inventoryAction, int amount)
{
    if (
        pWorldObject->GetWorldObjectType() == WorldObject::WorldObjectType::kComponent 
        || pWorldObject->GetWorldObjectType() == WorldObject::WorldObjectType::kResource
        )
    switch (inventoryAction)
    {
        case Inventory::InventoryActionType::kAddOne:
            switch (pWorldObject->GetWorldObjectType())
            {
            case WorldObject::WorldObjectType::kResource:
                FindResource(pWorldObject);
                break;
            case WorldObject::WorldObjectType::kComponent:
                FindComponent(pWorldObject);
                break;
            }
            break;
    }
}

void Inventory::FindResource(WorldObject* pWorldObject)
{
    Resource* pResource = dynamic_cast<Resource*>(pWorldObject);
    for (auto& [pInventoryObject, amount] : m_inventory)
    {
        if (pInventoryObject->GetWorldObjectType() == WorldObject::WorldObjectType::kResource)
        {
            Resource* pInventoryResource = dynamic_cast<Resource*>(pInventoryObject);
            if (pInventoryResource->GetResourceType() == pResource->GetResourceType())
            {
                if (pResource->GetAmount() > 0)
                {
                    amount++;
                }
                return;
            }

        }
    }
    m_inventory.push_back({ new Resource(pResource->GetResourceType(), 100), 1});
}

void Inventory::FindComponent(WorldObject* pWorldObject)
{
    Component* pComponent = dynamic_cast<Component*>(pWorldObject);
    for (auto& [pInventoryObject, amount] : m_inventory)
    {
        Component* pInventoryComponent = dynamic_cast<Component*>(pInventoryObject);
        if (pInventoryComponent->GetWorldObjectType() == pComponent->GetWorldObjectType())
        {
            amount++;
            return;
        }
    }
    m_inventory.push_back({ new Component(pComponent->ComponentType()), 1 });
}

void Inventory::FindComponentByType(WorldObject::ComponentType componentType)
{
    for (auto& [pInventoryObject, amount] : m_inventory)
    {
        if (pInventoryObject->GetWorldObjectType() == WorldObject::WorldObjectType::kComponent)
        {
            Component* pInventoryComponent = dynamic_cast<Component*>(pInventoryObject);
            if (pInventoryComponent->ComponentType() == componentType)
            {
                amount++;
                return;
            }
        }
    }
    m_inventory.push_back({ new Component(componentType), 1 });
}

bool Inventory::FindComponentItem(WorldObject::ComponentType componentType)
{
    for (auto [worldObject, amount] : m_inventory)
    {
        if (worldObject->GetWorldObjectType() == WorldObject::WorldObjectType::kComponent)
        {
            Component* pComponent = dynamic_cast<Component*>(worldObject);
            if (pComponent->ComponentType() == componentType)
            {
                return true;
            }
        }
    }
    return false;
}

bool Inventory::CanAfford(std::map<WorldObject::ResourceType, int> amount)
{
    for (auto [resourceType, amount] : amount)
    {
        for (auto [worldObject, inventoryAmount] : m_inventory)
        {
            if (worldObject->GetWorldObjectType() == WorldObject::WorldObjectType::kResource)
            {
                Resource* pInventoryResource = dynamic_cast<Resource*>(worldObject);
                if (pInventoryResource->GetResourceType() == resourceType)
                {
                    if (inventoryAmount < amount)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Inventory::Purchase(WorldObject::ComponentType componentType, std::map<WorldObject::ResourceType, int> amount)
{
    if (CanAfford(amount))
    {
        for (auto [resourceType, amount] : amount)
        {
            for (auto& [worldObject, inventoryAmount] : m_inventory)
            {
                if (worldObject->GetWorldObjectType() == WorldObject::WorldObjectType::kResource)
                {
                    Resource* pInventoryResource = dynamic_cast<Resource*>(worldObject);
                    if (pInventoryResource->GetResourceType() == resourceType)
                    {
                        inventoryAmount -= amount;
                    }
                }

            }
        }

        FindComponentByType(componentType);
        return;
    }
    std::cout << "cant afford component :/........ \n";
    system("pause");
}
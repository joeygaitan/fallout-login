#include "Resource.h"

Resource::Resource(ResourceType type, int amount)
    : WorldObject(WorldObject::WorldObjectType::kResource)
    , m_kResource(type)
    , m_amount(amount)
{}

void Resource::Draw()
{
    if (m_amount > 0)
    {
        switch (m_kResource)
        {
            case WorldObject::ResourceType::kIron:
                std::cout << "+";
                break;
            case WorldObject::ResourceType::kCopper:
                std::cout << "0";
                break;
            case WorldObject::ResourceType::kGold:
                std::cout << "&";
                break;
            case WorldObject::ResourceType::kCobalt:
                std::cout << "#";
                break;
        }
    }
    else
    {
        std::cout << 'e';
    }
}

void Resource::Action(Player& player)
{
    if (m_amount > 0)
    {
        player.ModifyInventory(this, Inventory::InventoryActionType::kAddOne, 1);
        m_amount--;
    }
}
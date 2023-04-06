#include "Assembler.h"

Assembler::Assembler(std::map<ComponentType, std::map<ResourceType, int>> storeInventory)
    : WorldObject(WorldObject::WorldObjectType::kAssembler)
    , m_storeInventory(storeInventory)
{}

void Assembler::Draw()
{
    std::cout << "$";
}

void Assembler::DisplayStore()
{
    int count = 1;
    for (auto [componentType, componentPriceMap] : m_storeInventory)
    {
        std::cout << WorldObject::PrintComponentType(componentType);
        std::cout << " price selection " << count << ": \n";
        for (auto [resoureType, amount] : componentPriceMap)
        {
            std::cout << WorldObject::PrintResourceType(resoureType);
            std::cout << ": " << amount << "\n";
        }
        std::cout << "\n";
        count++;
    }
    std::cout << "\n";
}

// Player Interface
void Assembler::Action(Player& player)
{
    system("cls");
    int choice;
    DisplayStore();

    std::cout << "please pick an option or quit with -1 \n" << "input: ";
    std::cin >> choice;
    int currentOption = 1;
    for (auto [componentType, componentPriceMap] : m_storeInventory)
    {
        if (choice == currentOption)
        {
            player.Purchase(componentType, componentPriceMap);
            return;
        }
        else if (choice == -1)
        {
            return;
        }
        ++currentOption;
    }
    std::cout << "please pick a valid option :)....." << "\n";
}
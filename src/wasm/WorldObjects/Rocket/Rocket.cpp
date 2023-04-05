#include "Rocket.h"
#include "Player.h"
#include "Game.h"

Rocket::Rocket(std::map<WorldObject::ComponentType, int> amountRequired)
    : WorldObject(WorldObject::WorldObjectType::kRocket)
    , m_amountRequired(amountRequired)
{}

void Rocket::DisplayComponents()
{
    for (auto [componentType, amount] : m_amountRequired)
    {
        std::cout << WorldObject::PrintComponentType(componentType) << ": " << amount << "\n";
    }
    std::cout << "\n";
}

void Rocket::Draw()
{
    std::cout << "^";
}

void Rocket::Action(Player& player)
{
    for (auto& [type, amount] : m_amountRequired)
    {
       if (player.GetInventory().FindComponentItem(type) == false)
       {
           system("cls");
           std::cout << "You still are missing components :/...." << "\n";
           DisplayComponents();
           system("pause");
           return;
       }
    }

    std::cout << "you won the game!!" << "\n";
    system("pause");
    Game::s_gameOver = true;
}
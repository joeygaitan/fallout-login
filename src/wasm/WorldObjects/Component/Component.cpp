#include "Component.h"

Component::Component(WorldObject::ComponentType m_kComponent)
    : WorldObject(WorldObjectType::kComponent)
    , m_kComponent(m_kComponent)
{}

void Component::Draw()
{
    switch (m_kComponent)
    {
    case ComponentType::kCpu:
        std::cout << "*";
        break;
    case ComponentType::kBooster:
        std::cout << "!";
        break;
    case ComponentType::kEngine:
        std::cout << "%";
        break;
    case ComponentType::kNull:
        std::cout << "Something failed to setup";
        system("pause");
        return;
    }
}

void Component::Action(Player& player)
{

}
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
    }
}

void Component::Action(Player& player)
{

}
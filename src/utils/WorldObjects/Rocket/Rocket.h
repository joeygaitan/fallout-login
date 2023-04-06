#pragma once
#include <iostream>
#include "../WorldObject.h"
class Player;
#include <map>


class Rocket :
    public WorldObject
{
    std::map<WorldObject::ComponentType, int> m_amountRequired;
public:
    Rocket(std::map<WorldObject::ComponentType, int> amountRequired);

    void DisplayComponents();

    void Draw() override;

    void Action(Player& player) override;
};


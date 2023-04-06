#pragma once
#include <iostream>
#include "../WorldObject.h"
class Boulder :
    public WorldObject
{
public:
    Boulder() : WorldObject(WorldObject::WorldObjectType::kBoulder) {};

    void Draw() override { std::cout << "o"; }
};


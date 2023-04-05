#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Game.h"
#include <unordered_map>

int main()
{
    srand((unsigned int)time(nullptr));
    /*
        New game input types.
        int playerX
        , int playerY
        , int width
        , int height
        , std::unordered_map<WorldObject::ComponentType, std::unordered_map<WorldObject::ResourceType, int>> storeInventory
        , std::map<WorldObject::ComponentType, int> rocketComponents
    */
    Game newGame(
        0
        , 0
        , 20
        , 20
        , { 
                {
                 WorldObject::ComponentType::kCpu, {
                    { WorldObject::ResourceType::kCopper, 5 }
                    , { WorldObject::ResourceType::kGold, 5 }
                    , { WorldObject::ResourceType::kCobalt, 5 }
                 }
                }
                , {
                 WorldObject::ComponentType::kBooster, {
                    { WorldObject::ResourceType::kIron, 10 }
                    , { WorldObject::ResourceType::kGold, 5 }
                 }
                }
                , {
                 WorldObject::ComponentType::kEngine, {
                    { WorldObject::ResourceType::kIron, 5 }
                    , { WorldObject::ResourceType::kCopper, 10 }
                 }
                }
        }
        , {
            {
                { WorldObject::ComponentType::kCpu, rand() % 2 + 1 }
                , { WorldObject::ComponentType::kEngine, rand() % 2 + 1 }
                , { WorldObject::ComponentType::kBooster, rand() % 2 + 1 }
            }
        });

    newGame.GameLoop();
}
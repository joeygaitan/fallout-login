#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "WorldObject.h"
#include "Player.h"
#include "Resource.h"
#include "Rocket.h"
#include "Assembler.h"

class Grid
{
public:
    using ComponentType = WorldObject::ComponentType;
    using ResourceType = WorldObject::ResourceType;
    using WOType = WorldObject::WorldObjectType;
    using TileProbability = std::pair<int, WOType>;


private:
    static inline const TileProbability s_tileProbabilities[(int)WOType::kWOcount] = {
        TileProbability(800, WOType::kFloor),
        TileProbability(400, WOType::kResource),
    };

    static inline int s_height = 0;
    static inline int s_width = 0;
    std::vector<WorldObject*> m_pGrid;
public:
    Grid(
        int width
        , int height
        , std::map<ComponentType, std::map<ResourceType, int>> storeInventory
        , std::map<ComponentType, int> rocketComponents
    );

    ~Grid();

    // Intialize the grid with null pointers for ground placement.
    void IntializeGrid(int width, int height);

    // Populates the grid with random locations of resources.
    void PopulateDynamicGrid(std::map<ComponentType, std::map<ResourceType, int>> storeInventory
        , std::map<ComponentType, int> rocketComponents);

    // Displays the grid and also deals with the player controller.
    void DisplayGrid(Player& player);

    // checks if the player goes out of range.
    static bool CheckOutOfRange(int x, int y, const std::vector<WorldObject*>& kGrid);

    WorldObject* GetObject(int x, int y);
private:
    WorldObject* GeObjectByIndex(int index) { return m_pGrid[index]; }
};


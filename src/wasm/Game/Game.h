#pragma once
#include <map>
#include "../Player/Player.h"
#include "../WorldObjects/WorldObject.h"
#include "../GameMap/Grid/Grid.h"

class Game
{
    Grid m_grid;
    Player m_player;

public:
    Game(
        int playerX
        , int playerY
        , int width
        , int height
        , std::map<WorldObject::ComponentType, std::map<WorldObject::ResourceType, int>> storeInventory
        , std::map<WorldObject::ComponentType, int> rocketComponents
    );

    // Game introduction 
    void StartInfo();

    // Main game loop.
    void GameLoop();
    
    // Ends the game.
    void EndGame();

    static inline bool s_gameOver = false;
};

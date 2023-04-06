#include "Game.h"

Game::Game(
    int playerX
    , int playerY
    , int width
    , int height
    , std::map<WorldObject::ComponentType, std::map<WorldObject::ResourceType, int>> storeInventory
    , std::map<WorldObject::ComponentType, int> rocketComponents
)
    : m_player(10, playerX, playerY)
    , m_grid(height, width, storeInventory, rocketComponents)
{}

void Game::StartInfo()
{
    std::cout << "Welcome to rocket escape" << "\n" << "your goal is to mine for resources (stand on resource and press e). \n";
    std::cout << " then build parts at the assembler (bottom right of the screen) in order to fix your rocket to leave the planet. \n";
    std::cout << "You have an inventory at the top of the screen and can figure out what everything is by pressing e. \n";
    system("pause");
    system("cls");
}

void Game::GameLoop()
{
    StartInfo();

    while (!s_gameOver && m_player.IsAlive())
    {
        m_grid.DisplayGrid(m_player);
    }

    EndGame();
}

void Game::EndGame()
{
    if (m_player.IsAlive())
    {
        std::cout << "You've won the Game and escaped into space returning home....";
    }
    else
    {
        std::cout << "you died.....";
    }
}
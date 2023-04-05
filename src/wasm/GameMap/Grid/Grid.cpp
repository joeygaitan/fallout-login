#include "Grid.h"

Grid::Grid(
    int width
    , int height
    , std::map<ComponentType, std::map<ResourceType, int>> storeInventory
    , std::map<ComponentType, int> rocketComponents
)
{
    IntializeGrid(width, height);
    PopulateDynamicGrid(storeInventory, rocketComponents);
}

Grid::~Grid()
{
    if (m_pGrid.size() > 0)
    {
        for (IWorldObject* pObject : m_pGrid)
        {
            delete pObject;
        }
    }
}

void Grid::IntializeGrid(int width, int height)
{
    if (m_pGrid.size() > 0)
    {
        for (int i = 0; i < width * height; ++i)
        {
            delete m_pGrid[i];
            m_pGrid.clear();
        }
    }

    for (int i = 0; i < height * height; ++i)
    {
        m_pGrid.emplace_back(nullptr);
    }

    Grid::s_width = width;
    Grid::s_height = height;
}

void Grid::PopulateDynamicGrid(std::map<ComponentType, std::map<ResourceType, int>> storeInventory
    , std::map<ComponentType, int> rocketComponents)
{
    // calculate the max probability
    int maxProbability = 0;
    for (int i = 0; i < (int)WOType::kWOcount; ++i)
    {
        maxProbability += s_tileProbabilities[i].first;
    }

    // set last index for rocket and assembler to placed.
    int lastIndex = m_pGrid.size() - 1;

    m_pGrid[lastIndex - 1] = new Assembler(storeInventory);
    m_pGrid[lastIndex] = new Rocket(rocketComponents);

   // double checks to see if the first index is a nullptr.
    if (m_pGrid[0] != nullptr)
    {
        delete m_pGrid[0];
        m_pGrid[0] = nullptr;
    }

    // populate the rest of the world
    for (int tileIndex = 1; tileIndex < (s_width * s_height) - 2; ++tileIndex)
    {
        // skip this tile if we've already set it
        if (GeObjectByIndex(tileIndex) != nullptr)
            continue;

        int roll = rand() % maxProbability;
        int probabilityIndex = 0;
        while (true)
        {
            roll -= s_tileProbabilities[probabilityIndex].first;
            if (roll < 0)
                break;
            ++probabilityIndex;
        }

        // Switch case basically will auto generate a floor with 4 random resource types.
        switch (s_tileProbabilities[probabilityIndex].second)
        {
        case WOType::kFloor:
            m_pGrid[tileIndex] = nullptr;
            break;
        case WOType::kResource:
            switch (rand() % 4 + 1)
            {
                case 1:
                    m_pGrid[tileIndex] = new Resource(ResourceType::kIron, rand() % 140);
                    break;
                case 2:
                    m_pGrid[tileIndex] = new Resource(ResourceType::kCopper, rand() % 100);
                    break;
                case 3:
                    m_pGrid[tileIndex] = new Resource(ResourceType::kGold, rand() % 50);
                    break;
                case 4:
                    m_pGrid[tileIndex] = new Resource(ResourceType::kCobalt, rand() % 120);
                    break;
                default:
                    std::cout << "random generation failed :/ \n";
                    break;
            }
            break;
        default:
            std::cout << "ERROR: Invalid type type." << "\n";
            break;
        }
    }
}

void Grid::DisplayGrid(Player& player)
{
    system("cls");
    std::cout << "Check game info by pressing f on your keyboard" << "\n";
    player.PlayerStats();
    player.DisplayInventory();

    for (int y = 0; y < s_height; ++y)
    {
        for (int x = 0; x < s_width; ++x)
        {
            if (player.GetX() == x && player.GetY() == y)
            {
                player.Draw();
            }
            else
            {
                int index = (y * s_width) + x;
                if (m_pGrid[index] != nullptr)
                    m_pGrid[index]->Draw();
                else
                    std::cout << ".";
            }
        }
        std::cout << "\n";
    }

    player.PrintWhatPlayerStandsOn(GetObject(player.GetX(), player.GetY()));

    player.PlayerController(GetObject(player.GetX(), player.GetY()), m_pGrid);
}

bool Grid::CheckOutOfRange(int x, int y, const std::vector<WorldObject*>& kGrid)
{
    if (x < 0 || x >= s_width)
        return true;
    if (y < 0 || y >= s_height)
        return true;

    return false;
}

WorldObject* Grid::GetObject(int x, int y)
{
    int index = (y * s_width) + x;
    return m_pGrid[index];
}
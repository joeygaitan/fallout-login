#include "Player.h"
#include "../GameMap/Grid/Grid.h"
#include "../WorldObjects/WorldObject.h"
#include "Inventory/Inventory.h"

Player::Player(int health, int x, int y)
    : m_health(health)
    , m_inventory()
    , m_x(x)
    , m_y(y)
{}

bool Player::PlayerController(WorldObject* pWorldObject, std::vector<WorldObject*>& grid)
{
    if (m_health <= 0)
        return false;

    char input;

    std::cout << "character Choice: ";
    
    std::scanf("%c", &input);

    switch (input)
    {
    case 'q':
        return false;  // quitting
    case 'w':
        // const std::vector<WorldObject*>& kGrid, WorldObject* pWorldObject, int dX, int dY
        PlayerMovement(grid, pWorldObject, 0, -1);
        break;

    case 'a':
        PlayerMovement(grid, pWorldObject, -1, 0);
        break;

    case 's':
        PlayerMovement(grid, pWorldObject, 0, 1);
        break;

    case 'd':
        PlayerMovement(grid, pWorldObject, 1, 0);
        break;
    case 'e':
        PlayerAction(pWorldObject);
        break;
    case 'f':
        DisplayGameInfo();
        break;
    default:
        std::cout << "Invalid input";
        break;
    }

    return true;
}

void Player::PlayerMovement(std::vector<WorldObject*>& grid, WorldObject* pWorldObject, int dX, int dY)
{
    if (Grid::CheckOutOfRange(dX + m_x, dY + m_y, grid))
        return;

    MovePlayer(dX, dY);
}

void Player::MovePlayer(int dX, int dY)
{
    m_x += dX;
    m_y += dY;
}

void Player::PlayerAction(WorldObject* pWorldObject)
{
    if (pWorldObject != nullptr)
    {
        switch (pWorldObject->GetWorldObjectType())
        {
        case WorldObject::WorldObjectType::kResource:
            pWorldObject->Action(*this);
            break;
        case WorldObject::WorldObjectType::kRocket:
            pWorldObject->Action(*this);
            break;
        case WorldObject::WorldObjectType::kAssembler:
            pWorldObject->Action(*this);
            break;
        default:
            return;
        }
    }
}

void Player::DisplayGameInfo()
{
    system("cls");
    std::cout << "'.': floor type \n" << "'+': iron resource type\n" << "'0': copper resource type\n" << "'#': cobalt resource type\n" << "'&': Gold Resource Type";
    std::cout << "'^': Rocket \n" << "'$': Assembler \n" << "'e': depleted resource\n";
    std::cout << "'pressing e': will interact with that object you are standing on.";
    system("pause");
    system("cls");
}

bool Player::IsAlive()
{
    return m_health > 0;
}

void Player::PrintWhatPlayerStandsOn(WorldObject* pObject)
{
    if (pObject != nullptr)
    {
        std::cout << "Standing on: ";
        if (pObject->GetWorldObjectType() == WorldObject::WorldObjectType::kResource)
        {
            std::cout << pObject->PrintResourceType(dynamic_cast<Resource*>(pObject)->GetResourceType()) << "\n";
            std::cout << "amount: " << dynamic_cast<Resource*>(pObject)->GetAmount() << "\n";
        }
        else
        {
            std::cout << pObject->GetWorldObjectTypeString(pObject->GetWorldObjectType()) << "\n";
        }
    }
    else
    {
        std::cout << "Standing on: moon dirt\n";
    }
}
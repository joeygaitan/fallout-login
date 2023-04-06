#pragma once
#include <iostream>
#include <stdio.h>
#include "./Inventory/Inventory.h"

class Grid;
class WorldObject;


class Player
{
    int m_x;
    int m_y;
    int m_health;

    Inventory m_inventory;
public:
    Player(int health, int x, int y);

    void Draw() { std::cout << "@"; }

    const int& GetX() { return m_x; }
    const int& GetY() { return m_y; }

    // Displays personal health.
    void PlayerStats() { std::cout << "Player Health: " << m_health << "\n"; }

    // Displays inventory.
    void DisplayInventory() { m_inventory.DisplayInventory(); }

    // This handles all the players possible actions.
    bool PlayerController(WorldObject* pWorldObject, std::vector<WorldObject*>& kGrid);

    // Handles player Movement and checks to see if they can actually move.s
    void PlayerMovement(std::vector<WorldObject*>& grid, WorldObject* pWorldObject, int dX, int dY);

    // moves the player in a xy grid.
    void MovePlayer(int dX, int dY);

    // Gets the inventory for the player
    Inventory& GetInventory() { return m_inventory; }

    // Allows the player to purchase a new component.
    void Purchase(WorldObject::ComponentType componentType, std::map<WorldObject::ResourceType, int> amount) { m_inventory.Purchase(componentType, amount); }

    // Displays game info
    void DisplayGameInfo();

    // Checks to see if the player is still alive.
    bool IsAlive();

    // Handles the players interaction with the map. Specifically when the player presses e.
    void PlayerAction(WorldObject* pWorldObject);

    // Modifies the inventory of the player.
    void ModifyInventory(WorldObject* pWorldObject, Inventory::InventoryActionType inventoryAction, int amount) { m_inventory.ModifyItem(pWorldObject, inventoryAction, amount); }

    // Prints out what the player is standing on and displays information about it.
    void PrintWhatPlayerStandsOn(WorldObject* pObject);
};





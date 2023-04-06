#pragma once
class Player;

struct IWorldObject
{
    // Displays the current objects visual form.
    virtual void Draw() = 0;

    // handles player interactions for world objects.
    virtual void Action(Player& player) = 0;

    virtual ~IWorldObject() {};
};
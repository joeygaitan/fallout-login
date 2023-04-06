#pragma once

struct IPlayer
{
    virtual void UpdateLocation(int x, int y) = 0;
};
#pragma once
#include "WorldObject.h"

/*
        kIron,
        kCopper,
        kGold,
        kCobalt
*/

/*
    enum class ComponentType
    {
        kNull,
        kCpu,
        kBooster,
        kEngine
    };
*/

struct WorldObjectBuilder
{
    static inline WorldObject* BuildIronResource();
    static inline WorldObject* BuildCopperResource();
    static inline WorldObject* BuildGoldResource();
    static inline WorldObject* BuildCobaltResource();

    static inline WorldObject* BuildCpuComponent();
    static inline WorldObject* BuildBoosterComponent();
    static inline WorldObject* BuildEngineComponent();

    static inline WorldObject* BuildBoulder();
};


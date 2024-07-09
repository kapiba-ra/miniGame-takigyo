#pragma once
#include "BULLETS.h"

class BOSS_BULLETS :
    public BULLETS
{
public:
    BOSS_BULLETS(class GAME* game);
    void create();
};


#pragma once
#include "BULLETS.h"

class PLAYER_BULLETS :
    public BULLETS
{
public:
    PLAYER_BULLETS(class GAME* game);
    void create();
    void powerUpBullets();
    void powerDownBullets();
};


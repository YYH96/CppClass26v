#pragma once

#include "GameInfo.h"

class CApple
{
private:
    POS mPos;

public:
    CApple();

    POS GetApplePos() const
    {
        return mPos;
    }

    void Respawn();
};

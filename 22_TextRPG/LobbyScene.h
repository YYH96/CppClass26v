#pragma once

#include "BaseScene.h"

class CLobbyScene : public CBaseScene
{
public:
    void Enter() override;
    void Draw() const override;
    void Update() override;
};


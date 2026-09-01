#pragma once

#include "BaseScene.h"

class CGameScene : public CBaseScene
{
public:
    void Enter() override;
    void Exit() override;
    void Draw() const override;
    void Update() override;
};


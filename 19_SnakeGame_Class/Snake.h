#pragma once

#include "GameInfo.h"
#include <vector>

class CGameManager;

class CSnake
{
    // 게임 매니저는 화면에 꼬리를 그리고 충돌을 검사해야 하므로 몸통을 읽을 수 있다.
    friend class CGameManager;

private:
    std::vector<POS> mSnake;
    DIR mDir;

public:
    CSnake();

    void Move();
    void LevelUp();

    void SetDir(DIR direction)
    {
        mDir = direction;
    }

    POS GetHeadPos() const
    {
        return mSnake.front();
    }
};

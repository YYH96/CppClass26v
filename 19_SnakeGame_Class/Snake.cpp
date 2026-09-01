#include "Snake.h"

CSnake::CSnake()
    : mDir(DIR::PAUSE)
{
    // 시작 위치는 게임판의 중앙이다.
    mSnake.push_back({ GAME_WIDTH / 2, GAME_HEIGHT / 2 });
}

void CSnake::Move()
{
    if (mDir == DIR::PAUSE)
    {
        return;
    }

    // 이동할 머리의 다음 위치를 먼저 계산한다.
    POS nextHead = mSnake[0];

    switch (mDir)
    {
    case DIR::LEFT:
        --nextHead.PosX;
        break;
    case DIR::RIGHT:
        ++nextHead.PosX;
        break;
    case DIR::UP:
        --nextHead.PosY;
        break;
    case DIR::DOWN:
        ++nextHead.PosY;
        break;
    default:
        break;
    }

    // 꼬리부터 앞으로 한 칸씩 이동해야 이전 좌표가 사라지지 않는다.
    for (int i = static_cast<int>(mSnake.size()) - 1; i > 0; --i)
    {
        mSnake[i] = mSnake[i - 1];
    }

    mSnake[0] = nextHead;
}

void CSnake::LevelUp()
{
    // 마지막 꼬리 위치를 하나 더 추가한다. 다음 Move에서 자연스럽게 따라간다.
    mSnake.push_back(mSnake.back());
}

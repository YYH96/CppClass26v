#pragma once

// 게임판에서 사용하는 한 칸의 좌표다.
struct sPosition
{
    int PosX = 0;
    int PosY = 0;
};

using POS = sPosition;

enum class eDirection
{
    PAUSE = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

using DIR = eDirection;

#define GAME_WIDTH 20
#define GAME_HEIGHT 20
#define GAME_DELAY_MILLISECOND 200

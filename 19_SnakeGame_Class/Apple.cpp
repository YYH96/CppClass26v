#include "Apple.h"
#include <cstdlib>

CApple::CApple()
{
    Respawn();
}

void CApple::Respawn()
{
    // 테두리(0, GAME_WIDTH - 1)에는 벽이 있으므로 안쪽 칸에만 사과를 만든다.
    mPos.PosX = (std::rand() % (GAME_WIDTH - 2)) + 1;
    mPos.PosY = std::rand() % GAME_HEIGHT;
}

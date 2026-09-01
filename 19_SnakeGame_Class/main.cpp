/*
    19번 스네이크 게임

    CGameManager가 전체 흐름을 관리하고,
    CSnake와 CApple이 각자의 데이터와 기능을 담당한다.
*/

#include "GameManager.h"

#include <cstdlib>
#include <ctime>

int main()
{
    // 실행할 때마다 사과 위치가 달라지도록 현재 시간을 난수 시드로 사용한다.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    CGameManager gameManager;
    gameManager.GameRun();

    return 0;
}

/*
    20번 빙고 클래스화 실습

    싱글턴 게임 매니저가 게임 전체를 실행하고,
    플레이어와 AI는 공통 부모 CObject의 빙고 기능을 상속받는다.
*/

#include "GameManager.h"

int main()
{
    CGameManager::GetInstance()->Run();
    return 0;
}

/*
    TextRPG 씬 전환 실습

    시작 시 로비 씬이 실행된다.
    로비에서 캐릭터를 만들면 SceneManager를 통해 인게임 씬으로 전환된다.
*/

#include "GameInfo.h"
#include "GameManager.h"

int main()
{
    CGameManager::GetInstance()->GameRun();
    return 0;
}

#include "GameInfo.h"
#include "CombatScene.h"

#include "GameManager.h"
#include "Monster.h"
#include "Player.h"
#include "SceneManager.h"

#include <iostream>

void CCombatScene::Draw() const
{
    CGameManager* gameManager = CGameManager::GetInstance();
    CPlayer* player = gameManager->GetPlayer();
    CMonster* monster = gameManager->GetMonster();

    if (player == nullptr || monster == nullptr)
    {
        std::cout << "전투에 필요한 객체가 없습니다.\n";
        return;
    }

    std::cout << "============= 전투 씬 =============\n";
    player->PrintInfo();
    monster->PrintInfo();
    std::cout << "[1] 공격  [2] 방어  [3] 도망  [0] 게임 종료\n";
}

void CCombatScene::Update()
{
    CGameManager* gameManager = CGameManager::GetInstance();
    CPlayer* player = gameManager->GetPlayer();
    CMonster* monster = gameManager->GetMonster();

    if (player == nullptr || monster == nullptr)
    {
        gameManager->GetSceneManager()->ChangeScene(eSceneType::GAME);
        return;
    }

    int inputNumber = -1;
    std::cout << "행동을 선택하세요: ";
    std::cin >> inputNumber;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    bool shouldShowResult = false;

    switch (inputNumber)
    {
    case 1:
        monster->TakeDamage(player->GetAttack());
        std::cout << player->GetName() << "의 공격! " << monster->GetName()
            << "에게 " << player->GetAttack() << "의 피해를 주었습니다.\n";

        if (monster->IsDead())
        {
            const int goldReward = monster->GetGoldReward();
            const int expReward = monster->GetExpReward();
            std::cout << monster->GetName() << "을(를) 쓰러뜨렸습니다!\n";

            gameManager->CombatEnd();
            std::cout << goldReward << "골드와 경험치 " << expReward << "을(를) 얻었습니다.\n";
            gameManager->GetSceneManager()->ChangeScene(eSceneType::GAME);
        }
        else
        {
            player->TakeDamage(monster->GetAttack(), false);
            std::cout << monster->GetName() << "의 반격! " << monster->GetAttack()
                << "의 피해를 받았습니다.\n";
        }
        shouldShowResult = true;
        break;

    case 2:
        player->TakeDamage(monster->GetAttack(), true);
        std::cout << "방어했습니다. " << monster->GetName() << "의 공격 피해가 절반으로 줄었습니다.\n";
        shouldShowResult = true;
        break;

    case 3:
        std::cout << "전투에서 도망쳤습니다.\n";
        gameManager->DeleteMonster();
        gameManager->GetSceneManager()->ChangeScene(eSceneType::GAME);
        shouldShowResult = true;
        break;

    case 0:
        gameManager->GetSceneManager()->RequestExit();
        break;

    default:
        std::cout << "잘못된 입력입니다.\n";
        shouldShowResult = true;
        break;
    }

    if (player->IsDead())
    {
        std::cout << player->GetName() << "이(가) 쓰러졌습니다. 게임을 종료합니다.\n";
        gameManager->GetSceneManager()->RequestExit();
        shouldShowResult = true;
    }

    if (shouldShowResult)
    {
        ConsoleUtils::WaitForEnter();
    }
}

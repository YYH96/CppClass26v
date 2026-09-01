#include "GameInfo.h"
#include "GameScene.h"

#include "GameManager.h"
#include "Player.h"
#include "SceneManager.h"

#include <cstdlib>
#include <iostream>

void CGameScene::Draw() const
{
    CGameManager* gameManager = CGameManager::GetInstance();
    CPlayer* player = gameManager->GetPlayer();

    if (player == nullptr)
    {
        std::cout << "플레이어 정보가 없습니다.\n";
        return;
    }

    std::cout << "========== 인게임 씬 ==========" << '\n';
    player->PrintInfo();
    std::cout << "현재 층: " << gameManager->GetStageLevel()
        << "층\t이번 층 최대 골드: " << gameManager->GetMaxGoldReward() << "G\n";
    std::cout << "[1] 탐색  [2] 휴식  [3] 로비로  [4] 저장하기  [0] 게임 종료\n";
}

void CGameScene::Update()
{
    CGameManager* gameManager = CGameManager::GetInstance();
    CPlayer* player = gameManager->GetPlayer();

    if (player == nullptr)
    {
        gameManager->GetSceneManager()->ChangeScene(eSceneType::LOBBY);
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
    {
        // COUNT를 제외한 0~3 중 하나를 eEventType으로 변환한다.
        const eEventType eventType = static_cast<eEventType>(
            std::rand() % static_cast<int>(eEventType::COUNT));

        switch (eventType)
        {
        case eEventType::NONE:
            std::cout << "아무것도 찾지 못했습니다.\n";
            break;
        case eEventType::GOLD:
        {
            const int goldReward = gameManager->GetRandomGoldReward();
            player->AddGold(goldReward);
            std::cout << "보물 상자를 찾아 " << goldReward << "골드를 얻었습니다.\n";
            break;
        }
        case eEventType::BATTLE:
            gameManager->CreateMonster();
            std::cout << "몬스터를 발견했습니다. 전투를 시작합니다!\n";
            gameManager->GetSceneManager()->ChangeScene(eSceneType::COMBAT);
            break;
        case eEventType::NEXT_STAGE:
            std::cout << "다음 층으로 올라가는 계단을 찾았습니다!\n";
            gameManager->NextStage();
            break;
        default:
            break;
        }
        shouldShowResult = true;
        break;
    }
    case 2:
        player->Rest();
        shouldShowResult = true;
        break;
    case 3:
        gameManager->GetSceneManager()->ChangeScene(eSceneType::LOBBY);
        break;
    case 4:
        if (gameManager->SaveGame())
        {
            std::cout << "게임을 저장했습니다.\n";
        }
        else
        {
            std::cout << "저장 파일을 만들지 못했습니다.\n";
        }
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

    // 결과를 확인한 뒤 사용자가 Enter를 누를 때 다음 게임 루프의 cls가 실행된다.
    if (shouldShowResult)
    {
        ConsoleUtils::WaitForEnter();
    }
}

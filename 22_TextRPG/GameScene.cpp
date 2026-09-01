#include "GameScene.h"

#include "GameManager.h"
#include "Player.h"
#include "SceneManager.h"

#include <cstdlib>
#include <iostream>
#include <Windows.h>

void CGameScene::Enter()
{
    std::cout << "인게임 씬으로 전환했습니다.\n";
}

void CGameScene::Exit()
{
    std::cout << "인게임 씬을 나갑니다.\n";
}

void CGameScene::Draw() const
{
    CPlayer* player = CGameManager::GetInstance()->GetPlayer();

    if (player == nullptr)
    {
        std::cout << "플레이어 정보가 없습니다.\n";
        return;
    }

    std::cout << "========== 인게임 씬 ==========" << '\n';
    player->PrintInfo();
    std::cout << "[1] 탐색  [2] 휴식  [3] 로비로  [0] 게임 종료\n";
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
        const int event = std::rand() % 3;

        if (event == 0)
        {
            std::cout << "아무것도 찾지 못했습니다.\n";
        }
        else if (event == 1)
        {
            player->AddGold(30);
            std::cout << "보물 상자를 찾아 30골드를 얻었습니다.\n";
        }
        else
        {
            player->AddGold(10);
            player->AddExp(40);
            std::cout << "몬스터의 흔적을 발견해 10골드와 경험치 40을 얻었습니다.\n";
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
    case 0:
        gameManager->GetSceneManager()->RequestExit();
        break;
    default:
        std::cout << "잘못된 입력입니다.\n";
        shouldShowResult = true;
        break;
    }

    // 결과를 확인하기 전에 다음 게임 루프의 system("cls")가 실행되지 않도록 대기한다.
    if (shouldShowResult)
    {
        Sleep(RESULT_DISPLAY_MILLISECOND);
    }
}

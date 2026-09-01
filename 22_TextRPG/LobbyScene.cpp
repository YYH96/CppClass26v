#include "LobbyScene.h"

#include "GameManager.h"
#include "SceneManager.h"

#include <iostream>
#include <string>

void CLobbyScene::Enter()
{
    std::cout << "로비 씬으로 전환했습니다.\n";
}

void CLobbyScene::Draw() const
{
    std::cout << "=====================================\n";
    std::cout << "            멸망의 탑 TextRPG\n";
    std::cout << "=====================================\n";
    std::cout << "새 캐릭터를 만들면 인게임 씬으로 전환됩니다.\n\n";
}

void CLobbyScene::Update()
{
    std::string name;
    std::cout << "이름을 입력하세요: ";
    std::cin >> name;

    int jobNumber = 0;

    while (jobNumber < 1 || jobNumber > 4)
    {
        std::cout << "직업 선택 [1]전사 [2]마법사 [3]도적 [4]궁수: ";
        std::cin >> jobNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            jobNumber = 0;
        }
    }

    CGameManager* gameManager = CGameManager::GetInstance();
    gameManager->CreatePlayer(name, static_cast<eJobClass>(jobNumber));

    // 로비 씬은 플레이어 생성까지만 담당한다.
    // 실제 화면 전환은 씬 매니저에게 요청한다.
    gameManager->GetSceneManager()->ChangeScene(eSceneType::GAME);
}


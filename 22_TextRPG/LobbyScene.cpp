#include "GameInfo.h"
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
    std::cout << "[1] 새 게임\n";
    std::cout << "[2] 이어하기\n\n";
}

void CLobbyScene::Update()
{
    int menuNumber = 0;
    std::cout << "메뉴를 선택하세요: ";
    std::cin >> menuNumber;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    CGameManager* gameManager = CGameManager::GetInstance();

    if (menuNumber == 2)
    {
        // 파일이 없거나 공백뿐이거나 형식이 손상됐다면 이어하기를 허용하지 않는다.
        if (gameManager->LoadGame())
        {
            std::cout << "저장된 게임을 불러왔습니다.\n";
            gameManager->GetSceneManager()->ChangeScene(eSceneType::GAME);
            ConsoleUtils::WaitForEnter();
            return;
        }

        std::cout << "저장된 내용이 없습니다. 새 게임을 시작합니다.\n";
        menuNumber = 1; // 이어하기를 골라도 새 게임 입력으로 강제 전환한다.
    }

    if (menuNumber != 1)
    {
        std::cout << "1 또는 2를 입력해주세요.\n";
        ConsoleUtils::WaitForEnter();
        return;
    }

    std::string name;
    std::cout << "이름을 입력하세요: ";
    std::cin >> name;

    int jobNumber = 0;

    while (jobNumber < 1
        || jobNumber > static_cast<int>(eJobClass::COUNT))
    {
        std::cout << "직업 선택 ";

        // 직업 표를 이용해 메뉴도 자동으로 만든다.
        for (int jobIndex = static_cast<int>(eJobClass::WARRIOR);
            jobIndex < static_cast<int>(eJobClass::COUNT);
            ++jobIndex)
        {
            const eJobClass job = static_cast<eJobClass>(jobIndex);
            std::cout << '[' << jobIndex + 1 << ']' << GetJobStat(job).name << ' ';
        }

        std::cout << ": ";
        std::cin >> jobNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            jobNumber = 0;
        }
    }

    // 메뉴 번호는 1부터 보여 주고, enum/배열 인덱스는 0부터 사용한다.
    gameManager->CreatePlayer(name, static_cast<eJobClass>(jobNumber - 1));

    // 로비 씬은 플레이어 생성까지만 담당한다.
    // 실제 화면 전환은 씬 매니저에게 요청한다.
    gameManager->GetSceneManager()->ChangeScene(eSceneType::GAME);
}

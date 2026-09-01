#include "GameManager.h"

#include "AI.h"
#include "Object.h"
#include "Player.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

CGameManager::~CGameManager()
{
    Release();
}

void CGameManager::Run()
{
    if (!Init())
    {
        std::cout << "초기화에 실패했습니다.\n";
        return;
    }

    while (mIsGameLoop)
    {
        Draw();

        if (!mIsGameLoop)
        {
            break;
        }

        Update();

        // AI가 고른 숫자를 확인할 수 있게 다음 화면을 그리기 전에 잠시 멈춘다.
        system("pause");
    }

    Release();
}

bool CGameManager::Init()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    mObjects.resize(static_cast<int>(eObjectType::COUNT), nullptr);
    mObjects[static_cast<int>(eObjectType::PLAYER)] = new CPlayer;
    mObjects[static_cast<int>(eObjectType::AI)] = new CAI;

    for (CObject* object : mObjects)
    {
        if (object == nullptr)
        {
            return false;
        }
    }

    return true;
}

void CGameManager::Update()
{
    CPlayer* player = dynamic_cast<CPlayer*>(mObjects[static_cast<int>(eObjectType::PLAYER)]);
    CAI* ai = dynamic_cast<CAI*>(mObjects[static_cast<int>(eObjectType::AI)]);

    // 플레이어가 고른 숫자는 두 빙고판에서 모두 표시한다.
    player->BingoMarking(mInputNumber);
    ai->BingoMarking(mInputNumber);

    // AI가 고른 숫자도 두 빙고판에서 모두 표시한다.
    const int aiInputNumber = ai->GetInputNumber();
    if (aiInputNumber != 0)
    {
        std::cout << "AI가 선택한 숫자: " << aiInputNumber << '\n';
        player->BingoMarking(aiInputNumber);
        ai->BingoMarking(aiInputNumber);
    }

    player->UpdateBingoCount();
    ai->UpdateBingoCount();
}

void CGameManager::Draw()
{
    system("cls");
    PrintBingoBoard();

    const eFinishResultType result = FinishCheck();
    if (result != eFinishResultType::NONE)
    {
        mIsGameLoop = false;
        return;
    }

    if (Input() == eFinishResultType::GAME_FINISH)
    {
        mIsGameLoop = false;
    }
}

void CGameManager::Release()
{
    for (CObject*& object : mObjects)
    {
        delete object;
        object = nullptr;
    }

    mObjects.clear();
}

void CGameManager::PrintBingoBoard() const
{
    const CPlayer* player = dynamic_cast<const CPlayer*>(mObjects[static_cast<int>(eObjectType::PLAYER)]);
    const CAI* ai = dynamic_cast<const CAI*>(mObjects[static_cast<int>(eObjectType::AI)]);

    const std::vector<int>& playerBingo = player->GetBingoData();
    const std::vector<int>& aiBingo = ai->GetBingoData();

    std::cout << "========== 플레이어 ==========  ||  ============= AI =============\n";

    for (int row = 0; row < BINGO_LINE_LENGTH; ++row)
    {
        for (int column = 0; column < BINGO_LINE_LENGTH; ++column)
        {
            const int number = playerBingo[row * BINGO_LINE_LENGTH + column];
            std::cout << (number == MARKED_NUMBER ? "*" : std::to_string(number)) << '\t';
        }

        std::cout << "||\t";

        for (int column = 0; column < BINGO_LINE_LENGTH; ++column)
        {
            const int number = aiBingo[row * BINGO_LINE_LENGTH + column];
            std::cout << (number == MARKED_NUMBER ? "*" : std::to_string(number)) << '\t';
        }

        std::cout << '\n';
    }

    std::cout << "빙고: " << player->GetBingoCount()
        << "\t\t\t\t빙고: " << ai->GetBingoCount() << "\n\n";
}

eFinishResultType CGameManager::FinishCheck() const
{
    const CObject* player = mObjects[static_cast<int>(eObjectType::PLAYER)];
    const CObject* ai = mObjects[static_cast<int>(eObjectType::AI)];

    if (player->GetBingoCount() >= BINGO_LINE_LENGTH && ai->GetBingoCount() >= BINGO_LINE_LENGTH)
    {
        std::cout << "무승부입니다. 게임을 종료합니다.\n";
        return eFinishResultType::DRAW;
    }

    if (player->GetBingoCount() >= BINGO_LINE_LENGTH)
    {
        std::cout << "승리했습니다! 게임을 종료합니다.\n";
        return eFinishResultType::PLAYER_WIN;
    }

    if (ai->GetBingoCount() >= BINGO_LINE_LENGTH)
    {
        std::cout << "AI가 승리했습니다. 게임을 종료합니다.\n";
        return eFinishResultType::AI_WIN;
    }

    return eFinishResultType::NONE;
}

eFinishResultType CGameManager::Input()
{
    while (true)
    {
        std::cout << "숫자를 입력하세요 (1~25, 0: 종료): ";
        int inputNumber = 0;
        std::cin >> inputNumber;

        if (std::cin.fail())
        {
            // 숫자가 아닌 입력으로 fail 상태가 되면 다음 입력을 위해 상태와 버퍼를 비운다.
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "숫자로 입력해주세요.\n";
            continue;
        }

        if (inputNumber == 0)
        {
            std::cout << "게임을 종료합니다.\n";
            return eFinishResultType::GAME_FINISH;
        }

        if (inputNumber < 1 || inputNumber > BINGO_BOARD_SIZE)
        {
            std::cout << "1~25 범위에서 입력해주세요.\n";
            continue;
        }

        CObject* player = mObjects[static_cast<int>(eObjectType::PLAYER)];
        if (player->FindUnmarkedNumber(inputNumber) == INVALID_BINGO_INDEX)
        {
            std::cout << "이미 표시한 숫자입니다. 다시 입력해주세요.\n";
            continue;
        }

        mInputNumber = inputNumber;
        return eFinishResultType::NONE;
    }
}

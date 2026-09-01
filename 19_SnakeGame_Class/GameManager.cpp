#include "GameManager.h"

#include "Apple.h"
#include "GameInfo.h"
#include "Snake.h"

#include <conio.h>
#include <iostream>
#include <Windows.h>

CGameManager::~CGameManager()
{
    delete mPSnake;
    delete mPApple;
}

bool CGameManager::Init()
{
    mPSnake = new CSnake;
    mPApple = new CApple;

    // 처음 생성한 사과도 뱀의 시작 위치와 겹치지 않게 한다.
    while (IsSnakePosition(mPApple->GetApplePos().PosX, mPApple->GetApplePos().PosY))
    {
        mPApple->Respawn();
    }

    HideCursor();
    return true;
}

void CGameManager::HideCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void CGameManager::Input()
{
    // _kbhit: 키가 눌렸는지 확인, _getch: 눌린 키를 가져온다.
    if (!_kbhit())
    {
        return;
    }

    const int key = _getch();

    switch (key)
    {
    case 'w':
    case 'W':
        mPSnake->SetDir(DIR::UP);
        break;
    case 'a':
    case 'A':
        mPSnake->SetDir(DIR::LEFT);
        break;
    case 's':
    case 'S':
        mPSnake->SetDir(DIR::DOWN);
        break;
    case 'd':
    case 'D':
        mPSnake->SetDir(DIR::RIGHT);
        break;
    case 'x':
    case 'X':
        mIsGameOver = true;
        break;
    default:
        break;
    }
}

void CGameManager::Draw()
{
    system("cls");

    const POS snakeHeadPos = mPSnake->GetHeadPos();
    const POS applePos = mPApple->GetApplePos();

    for (int x = 0; x < GAME_WIDTH; ++x)
    {
        std::cout << '*';
    }
    std::cout << '\n';

    for (int y = 0; y < GAME_HEIGHT; ++y)
    {
        for (int x = 0; x < GAME_WIDTH; ++x)
        {
            if (x == 0 || x == GAME_WIDTH - 1)
            {
                std::cout << '*';
            }
            else if (x == snakeHeadPos.PosX && y == snakeHeadPos.PosY)
            {
                std::cout << 'W';
            }
            else if (x == applePos.PosX && y == applePos.PosY)
            {
                std::cout << '@';
            }
            else if (IsSnakeTailPosition(x, y))
            {
                std::cout << '#';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    for (int x = 0; x < GAME_WIDTH; ++x)
    {
        std::cout << '*';
    }
    std::cout << "\nW/A/S/D: 이동, X: 종료\n";
}

bool CGameManager::IsSnakeTailPosition(int x, int y) const
{
    // 0번은 머리이며 Draw에서 이미 처리했으므로 1번부터 꼬리다.
    for (int i = 1; i < static_cast<int>(mPSnake->mSnake.size()); ++i)
    {
        if (mPSnake->mSnake[i].PosX == x && mPSnake->mSnake[i].PosY == y)
        {
            return true;
        }
    }

    return false;
}

bool CGameManager::IsSnakePosition(int x, int y) const
{
    // 머리까지 포함해 뱀이 차지한 모든 칸을 검사한다.
    for (int i = 0; i < static_cast<int>(mPSnake->mSnake.size()); ++i)
    {
        if (mPSnake->mSnake[i].PosX == x && mPSnake->mSnake[i].PosY == y)
        {
            return true;
        }
    }

    return false;
}

void CGameManager::Update()
{
    mPSnake->Move();

    const POS snakeHeadPos = mPSnake->GetHeadPos();

    // 좌우 벽 또는 위아래 범위를 벗어나면 게임 오버다.
    if (snakeHeadPos.PosX <= 0 || snakeHeadPos.PosX >= GAME_WIDTH - 1
        || snakeHeadPos.PosY < 0 || snakeHeadPos.PosY >= GAME_HEIGHT)
    {
        mIsGameOver = true;
        return;
    }

    // 머리가 꼬리와 같은 좌표가 되었는지 검사한다.
    if (IsSnakeTailPosition(snakeHeadPos.PosX, snakeHeadPos.PosY))
    {
        mIsGameOver = true;
        return;
    }

    const POS applePos = mPApple->GetApplePos();
    if (snakeHeadPos.PosX == applePos.PosX && snakeHeadPos.PosY == applePos.PosY)
    {
        mPSnake->LevelUp();

        // 새 사과가 뱀 위에 생기지 않도록 다시 뽑는다.
        do
        {
            mPApple->Respawn();
        } while (IsSnakePosition(mPApple->GetApplePos().PosX, mPApple->GetApplePos().PosY));
    }
}

void CGameManager::GameRun()
{
    if (!Init())
    {
        return;
    }

    while (!mIsGameOver)
    {
        Draw();
        Input();

        if (mIsGameOver)
        {
            break;
        }

        Update();
        Sleep(GAME_DELAY_MILLISECOND);
    }

    std::cout << "게임 오버입니다.\n";
    system("pause");
}

#include "GameManager.h"

#include "Player.h"
#include "SceneManager.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

CGameManager::~CGameManager()
{
    Release();
}

bool CGameManager::Init()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    mSceneManager = new CSceneManager;

    if (!mSceneManager->Init())
    {
        return false;
    }

    return true;
}

void CGameManager::GameRun()
{
    if (!Init())
    {
        std::cout << "게임 초기화에 실패했습니다.\n";
        return;
    }

    while (mSceneManager->IsRunning())
    {
        std::system("cls");
        mSceneManager->Draw();
        mSceneManager->Update();
    }

    Release();
}

void CGameManager::CreatePlayer(const std::string& name, eJobClass job)
{
    // 로비로 돌아가 새 게임을 시작하면 기존 플레이어를 먼저 정리한다.
    delete mPlayer;
    mPlayer = new CPlayer;
    mPlayer->Initialize(name, job);
}

CPlayer* CGameManager::GetPlayer() const
{
    return mPlayer;
}

CSceneManager* CGameManager::GetSceneManager() const
{
    return mSceneManager;
}

void CGameManager::Release()
{
    delete mSceneManager;
    mSceneManager = nullptr;

    delete mPlayer;
    mPlayer = nullptr;
}


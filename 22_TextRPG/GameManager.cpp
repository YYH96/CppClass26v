#include "GameInfo.h"
#include "GameManager.h"

#include "Player.h"
#include "Monster.h"
#include "SaveSystem.h"
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
    mStageLevel = START_STAGE;
    mMaxGoldReward = START_MAX_GOLD;

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

bool CGameManager::HasSaveData() const
{
    return SaveSystem::HasSaveData();
}

bool CGameManager::LoadGame()
{
    SaveData saveData;

    if (!SaveSystem::LoadGame(saveData))
    {
        return false;
    }

    delete mPlayer;
    mPlayer = new CPlayer;
    mPlayer->LoadFromSaveData(saveData);
    mStageLevel = saveData.stageLevel;
    mMaxGoldReward = saveData.maxGoldReward;
    return true;
}

bool CGameManager::SaveGame() const
{
    if (mPlayer == nullptr)
    {
        return false;
    }

    SaveData saveData;
    mPlayer->CopyToSaveData(saveData);
    saveData.stageLevel = mStageLevel;
    saveData.maxGoldReward = mMaxGoldReward;

    return SaveSystem::SaveGame(saveData);
}

bool CGameManager::CreateMonster()
{
    // 전투마다 새로운 몬스터 하나만 유지한다.
    DeleteMonster();
    mMonster = new CMonster;
    mMonster->InitializeRandom();
    return true;
}

void CGameManager::DeleteMonster()
{
    delete mMonster;
    mMonster = nullptr;
}

void CGameManager::CombatEnd()
{
    if (mPlayer == nullptr || mMonster == nullptr)
    {
        return;
    }

    // 몬스터를 삭제하기 전에 보상 정보를 플레이어에게 전달한다.
    mPlayer->AddGold(mMonster->GetGoldReward());
    mPlayer->AddExp(mMonster->GetExpReward());
    DeleteMonster();
}

void CGameManager::NextStage()
{
    ++mStageLevel;

    // int로 저장하므로 소수점 이하는 버린다.
    // 예: 100 -> 150 -> 225 -> 337 ...
    mMaxGoldReward = static_cast<int>(mMaxGoldReward * GOLD_MAX_INCREASE_RATE);

    std::cout << mStageLevel << "층에 도착했습니다. ";
    std::cout << "이번 층의 최대 골드 획득량: " << mMaxGoldReward << "G\n";
}

int CGameManager::GetRandomGoldReward() const
{
    // 0골드는 보상으로 느껴지지 않으므로 1부터 최대 골드까지 얻는다.
    return (std::rand() % mMaxGoldReward) + 1;
}

CPlayer* CGameManager::GetPlayer() const
{
    return mPlayer;
}

CMonster* CGameManager::GetMonster() const
{
    return mMonster;
}

CSceneManager* CGameManager::GetSceneManager() const
{
    return mSceneManager;
}

int CGameManager::GetStageLevel() const
{
    return mStageLevel;
}

int CGameManager::GetMaxGoldReward() const
{
    return mMaxGoldReward;
}

void CGameManager::Release()
{
    delete mSceneManager;
    mSceneManager = nullptr;

    delete mPlayer;
    mPlayer = nullptr;

    DeleteMonster();
}

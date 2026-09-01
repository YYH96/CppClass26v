#pragma once

#include "GameInfo.h"
#include <string>

class CPlayer;
class CMonster;
class CSceneManager;

class CGameManager
{
private:
    CPlayer* mPlayer = nullptr;
    CMonster* mMonster = nullptr;
    CSceneManager* mSceneManager = nullptr;
    int mStageLevel = START_STAGE;
    int mMaxGoldReward = START_MAX_GOLD;

    CGameManager() = default;
    ~CGameManager();

    bool Init();
    void Release();

public:
    CGameManager(const CGameManager&) = delete;
    CGameManager& operator=(const CGameManager&) = delete;

    static CGameManager* GetInstance()
    {
        static CGameManager instance;
        return &instance;
    }

    void GameRun();
    void CreatePlayer(const std::string& name, eJobClass job);
    bool HasSaveData() const;
    bool LoadGame();
    bool SaveGame() const;
    bool CreateMonster();
    void DeleteMonster();
    void CombatEnd();
    void NextStage();
    int GetRandomGoldReward() const;

    CPlayer* GetPlayer() const;
    CMonster* GetMonster() const;
    CSceneManager* GetSceneManager() const;
    int GetStageLevel() const;
    int GetMaxGoldReward() const;
};

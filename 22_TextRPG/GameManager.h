#pragma once

#include "GameInfo.h"
#include <string>

class CPlayer;
class CSceneManager;

class CGameManager
{
private:
    CPlayer* mPlayer = nullptr;
    CSceneManager* mSceneManager = nullptr;

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

    CPlayer* GetPlayer() const;
    CSceneManager* GetSceneManager() const;
};


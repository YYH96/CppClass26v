#pragma once

#include "GameInfo.h"
#include <vector>

class CBaseScene;

class CSceneManager
{
private:
    std::vector<CBaseScene*> mScenes;
    CBaseScene* mCurrentScene = nullptr;
    bool mIsRunning = true;

public:
    ~CSceneManager();

    bool Init();
    void ChangeScene(eSceneType nextSceneType);
    void Draw() const;
    void Update();
    void RequestExit();
    bool IsRunning() const;
    void Release();
};


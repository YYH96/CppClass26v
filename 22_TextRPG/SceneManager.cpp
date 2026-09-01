#include "GameInfo.h"
#include "SceneManager.h"

#include "BaseScene.h"
#include "CombatScene.h"
#include "GameScene.h"
#include "LobbyScene.h"

CSceneManager::~CSceneManager()
{
    Release();
}

bool CSceneManager::Init()
{
    // eSceneType의 COUNT만큼 공간을 확보한 뒤, 각 씬을 미리 생성한다.
    mScenes.resize(static_cast<int>(eSceneType::COUNT), nullptr);
    mScenes[static_cast<int>(eSceneType::LOBBY)] = new CLobbyScene;
    mScenes[static_cast<int>(eSceneType::GAME)] = new CGameScene;
    mScenes[static_cast<int>(eSceneType::COMBAT)] = new CCombatScene;

    for (CBaseScene* scene : mScenes)
    {
        if (scene == nullptr)
        {
            return false;
        }
    }

    ChangeScene(eSceneType::LOBBY);
    return true;
}

void CSceneManager::ChangeScene(eSceneType nextSceneType)
{
    const int nextIndex = static_cast<int>(nextSceneType);

    if (nextIndex < 0 || nextIndex >= static_cast<int>(mScenes.size()))
    {
        return;
    }

    CBaseScene* nextScene = mScenes[nextIndex];

    if (nextScene == nullptr || nextScene == mCurrentScene)
    {
        return;
    }

    if (mCurrentScene != nullptr)
    {
        mCurrentScene->Exit();
    }

    mCurrentScene = nextScene;
    mCurrentScene->Enter();
}

void CSceneManager::Draw() const
{
    if (mCurrentScene != nullptr)
    {
        mCurrentScene->Draw();
    }
}

void CSceneManager::Update()
{
    if (mCurrentScene != nullptr)
    {
        mCurrentScene->Update();
    }
}

void CSceneManager::RequestExit()
{
    mIsRunning = false;
}

bool CSceneManager::IsRunning() const
{
    return mIsRunning;
}

void CSceneManager::Release()
{
    for (CBaseScene*& scene : mScenes)
    {
        delete scene;
        scene = nullptr;
    }

    mScenes.clear();
    mCurrentScene = nullptr;
    mIsRunning = false;
}

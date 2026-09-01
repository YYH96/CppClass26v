#pragma once

#include "GameInfo.h"
#include <vector>

class CObject;

// 게임의 전체 흐름을 하나만 관리하는 싱글턴 클래스다.
class CGameManager
{
private:
    bool mIsGameLoop = true;
    int mInputNumber = 0;
    std::vector<CObject*> mObjects;

    CGameManager() = default;
    ~CGameManager();

    bool Init();
    void Update();
    void Draw();
    void Release();

    void PrintBingoBoard() const;
    eFinishResultType FinishCheck() const;
    eFinishResultType Input();

public:
    CGameManager(const CGameManager&) = delete;
    CGameManager& operator=(const CGameManager&) = delete;

    static CGameManager* GetInstance()
    {
        // 함수 안의 static 지역 변수는 프로그램이 끝날 때까지 한 번만 만들어진다.
        static CGameManager instance;
        return &instance;
    }

    void Run();
};

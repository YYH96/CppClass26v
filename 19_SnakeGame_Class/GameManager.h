#pragma once

class CSnake; // 전방 선언: 헤더에서는 포인터 이름만 알면 된다.
class CApple;

class CGameManager
{
private:
    CSnake* mPSnake = nullptr;
    CApple* mPApple = nullptr;
    bool mIsGameOver = false;

    bool Init();
    void HideCursor();
    void Input();
    void Draw();
    void Update();
    bool IsSnakeTailPosition(int x, int y) const;
    bool IsSnakePosition(int x, int y) const;

public:
    CGameManager() = default;
    ~CGameManager();

    void GameRun();
};

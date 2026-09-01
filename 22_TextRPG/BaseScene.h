#pragma once

// 모든 씬이 공통으로 가지는 인터페이스다.
class CBaseScene
{
public:
    virtual ~CBaseScene() = default;

    // 씬으로 들어갈 때와 나갈 때 한 번씩 호출된다.
    virtual void Enter() {}
    virtual void Exit() {}

    virtual void Draw() const = 0;
    virtual void Update() = 0;
};


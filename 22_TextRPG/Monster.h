#pragma once

#include "GameInfo.h"
#include <string>

class CMonster
{
private:
    // 반환형 void, 매개변수 없음 형태의 함수 포인터다.
    // 몬스터 종류에 따라 서로 다른 콘솔 그림 출력 함수를 가리킨다.
    using MonsterImageFunction = void (*)();

    eMonsterType mType = eMonsterType::SLIME;
    std::string mName;
    int mHP = 0;
    int mMaxHP = 0;
    int mAttack = 0;
    int mGoldReward = 0;
    int mExpReward = 0;
    MonsterImageFunction mDrawMonsterImage = nullptr;

public:
    void InitializeRandom();
    void PrintInfo() const;
    void TakeDamage(int damage);

    bool IsDead() const { return mHP <= 0; }
    const std::string& GetName() const { return mName; }
    int GetAttack() const { return mAttack; }
    int GetGoldReward() const { return mGoldReward; }
    int GetExpReward() const { return mExpReward; }

private:
    void SetStats(const std::string& name, int hp, int attack, int goldReward, int expReward);
    const char* GetTypeName() const;
};

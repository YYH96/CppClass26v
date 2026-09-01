#pragma once

#include "GameInfo.h"
#include <string>

class CPlayer
{
private:
    std::string mName;
    eJobClass mJob = eJobClass::WARRIOR;
    int mHP = START_MAX_HP;
    int mMaxHP = START_MAX_HP;
    int mAttack = START_ATTACK;
    int mGold = START_GOLD;
    int mLevel = 1;
    int mExp = 0;

public:
    void Initialize(const std::string& name, eJobClass job);
    void PrintInfo() const;
    void Rest();
    void AddGold(int gold);
    void AddExp(int exp);

    const std::string& GetName() const { return mName; }
    int GetGold() const { return mGold; }
    int GetLevel() const { return mLevel; }

private:
    const char* GetJobName() const;
};


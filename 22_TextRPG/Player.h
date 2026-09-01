#pragma once

#include "GameInfo.h"
#include <string>

struct SaveData;

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
    int mMaxExp = START_MAX_EXP;

public:
    void Initialize(const std::string& name, eJobClass job);
    void PrintInfo() const;
    void Rest();
    void AddGold(int gold);
    void AddExp(int exp);
    void TakeDamage(int damage, bool isDefending);
    void CopyToSaveData(SaveData& outSaveData) const;
    void LoadFromSaveData(const SaveData& saveData);

    const std::string& GetName() const { return mName; }
    int GetHP() const { return mHP; }
    int GetGold() const { return mGold; }
    int GetLevel() const { return mLevel; }
    int GetAttack() const { return mAttack; }
    bool IsDead() const { return mHP <= 0; }

private:
    const char* GetJobName() const;
};

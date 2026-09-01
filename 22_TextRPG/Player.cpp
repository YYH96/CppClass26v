#include "Player.h"

#include <iostream>

void CPlayer::Initialize(const std::string& name, eJobClass job)
{
    mName = name;
    mJob = job;
    mHP = START_MAX_HP;
    mMaxHP = START_MAX_HP;
    mAttack = START_ATTACK;
    mGold = START_GOLD;
    mLevel = 1;
    mExp = 0;

    // 직업마다 시작 능력치를 다르게 준다.
    switch (mJob)
    {
    case eJobClass::WARRIOR:
        mMaxHP = 150;
        mAttack = 12;
        break;
    case eJobClass::WIZARD:
        mMaxHP = 80;
        mAttack = 18;
        break;
    case eJobClass::THIEF:
        mMaxHP = 100;
        mAttack = 14;
        break;
    case eJobClass::ARCHER:
        mMaxHP = 110;
        mAttack = 15;
        break;
    }

    mHP = mMaxHP;
}

void CPlayer::PrintInfo() const
{
    std::cout << "========== 플레이어 정보 ==========\n";
    std::cout << "이름: " << mName << "\t직업: " << GetJobName() << '\n';
    std::cout << "레벨: " << mLevel << "\t경험치: " << mExp << "\n";
    std::cout << "HP: " << mHP << " / " << mMaxHP << "\t공격력: " << mAttack << '\n';
    std::cout << "골드: " << mGold << "\n";
    std::cout << "===================================\n";
}

void CPlayer::Rest()
{
    mHP += RESTORE_HP;

    if (mHP > mMaxHP)
    {
        mHP = mMaxHP;
    }

    std::cout << "휴식했습니다. HP가 회복되었습니다.\n";
}

void CPlayer::AddGold(int gold)
{
    mGold += gold;
}

void CPlayer::AddExp(int exp)
{
    mExp += exp;

    if (mExp >= 100)
    {
        ++mLevel;
        mExp -= 100;
        std::cout << "레벨이 올랐습니다! 현재 레벨: " << mLevel << '\n';
    }
}

const char* CPlayer::GetJobName() const
{
    switch (mJob)
    {
    case eJobClass::WARRIOR:
        return "전사";
    case eJobClass::WIZARD:
        return "마법사";
    case eJobClass::THIEF:
        return "도적";
    case eJobClass::ARCHER:
        return "궁수";
    }

    return "알 수 없음";
}


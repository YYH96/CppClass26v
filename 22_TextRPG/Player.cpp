#include "GameInfo.h"
#include "Player.h"

#include "SaveSystem.h"

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
    mMaxExp = START_MAX_EXP;

    // 열거형 값을 배열 인덱스로 바꿔 직업 능력치 표에서 가져온다.
    const JobStat& jobStat = GetJobStat(mJob);
    mMaxHP = jobStat.maxHP;
    mAttack = jobStat.attack;
    mHP = mMaxHP;
}

void CPlayer::PrintInfo() const
{
    std::cout << "========== 플레이어 정보 ==========\n";
    std::cout << "이름: " << mName << "\t직업: " << GetJobName() << '\n';
    std::cout << "레벨: " << mLevel << "\t경험치: " << mExp << "\t다음 레벨까지: " << mMaxExp - mExp << '\n';
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

    // 한 번에 큰 경험치를 얻어도 필요한 횟수만큼 계속 레벨업한다.
    while (mExp >= mMaxExp)
    {
        ++mLevel;
        mExp -= mMaxExp;
        std::cout << "레벨이 올랐습니다! 현재 레벨: " << mLevel << '\n';

		mMaxHP = static_cast<int>(mMaxHP * STAT_INCREASE_RATE);
		mHP = mMaxHP; // 레벨업 시 HP를 최대치로 회복
		mAttack = static_cast<int>(mAttack * STAT_INCREASE_RATE);
		mMaxExp = static_cast<int>(mMaxExp * STAT_INCREASE_RATE);
		//std::cout << "최대 HP: " << mMaxHP << ", 공격력: " << mAttack << ", 다음 레벨까지 필요 경험치: " << mMaxExp << '\n';

    }
}

void CPlayer::TakeDamage(int damage, bool isDefending)
{
    int finalDamage = damage;

    if (isDefending)
    {
        // 방어를 선택한 턴에는 피해를 절반으로 줄인다.
        finalDamage /= 2;
    }

    if (finalDamage < 1)
    {
        finalDamage = 1;
    }

    mHP -= finalDamage;

    if (mHP < 0)
    {
        mHP = 0;
    }
}

void CPlayer::CopyToSaveData(SaveData& outSaveData) const
{
    outSaveData.playerName = mName;
    // 저장 파일에는 사람이 읽기 쉬운 직업 번호(1~4)를 기록한다.
    outSaveData.jobValue = static_cast<int>(mJob) + 1;
    outSaveData.hp = mHP;
    outSaveData.maxHP = mMaxHP;
    outSaveData.attack = mAttack;
    outSaveData.gold = mGold;
    outSaveData.level = mLevel;
    outSaveData.exp = mExp;
}

void CPlayer::LoadFromSaveData(const SaveData& saveData)
{
    mName = saveData.playerName;
    // 저장 파일의 1~4 번호를 enum/배열의 0~3 인덱스로 되돌린다.
    mJob = static_cast<eJobClass>(saveData.jobValue - 1);
    mHP = saveData.hp;
    mMaxHP = saveData.maxHP;
    mAttack = saveData.attack;
    mGold = saveData.gold;
    mLevel = saveData.level;
    mExp = saveData.exp;
}

const char* CPlayer::GetJobName() const
{
    return GetJobStat(mJob).name;
}

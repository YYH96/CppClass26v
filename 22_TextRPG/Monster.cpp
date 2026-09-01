#include "GameInfo.h"
#include "Monster.h"

#include <cstdlib> // std::rand, std::srand
#include <iostream> // std::cout

void CMonster::InitializeRandom()
{
    mType = static_cast<eMonsterType>(std::rand() % static_cast<int>(eMonsterType::COUNT));

    switch (mType)
    {
    case eMonsterType::SLIME:
        SetStats("슬라임", 40, 5, 20, 30);
        mDrawMonsterImage = GlobalFunc::PrintSlimeImage;
        break;
    case eMonsterType::GOBLIN:
        SetStats("고블린", 70, 9, 45, 55);
        mDrawMonsterImage = GlobalFunc::PrintGoblinImage;
        break;
    case eMonsterType::ORC:
        SetStats("오크", 120, 14, 90, 90);
        mDrawMonsterImage = GlobalFunc::PrintOrcImage;
        break;
    default:
        break;
    }
}

void CMonster::PrintInfo() const
{
    std::cout << "========== 몬스터 정보 ==========\n";
    std::cout << "이름: " << mName << "\t종족: " << GetTypeName() << '\n';
    std::cout << "HP: " << mHP << " / " << mMaxHP << "\t공격력: " << mAttack << '\n';

    // 함수 포인터가 가리키는 몬스터 전용 그림 함수를 호출한다.
    if (mDrawMonsterImage != nullptr)
    {
        mDrawMonsterImage();
    }

    std::cout << "===============================\n";
}

void CMonster::TakeDamage(int damage)
{
    // 이 예제에서는 방어력 없이 받은 피해만큼 HP를 줄인다.
    mHP -= damage;

    if (mHP < 0)
    {
        mHP = 0;
    }
}

void CMonster::SetStats(const std::string& name, int hp, int attack, int goldReward, int expReward)
{
    mName = name;
    mMaxHP = hp;
    mHP = mMaxHP;
    mAttack = attack;
    mGoldReward = goldReward;
    mExpReward = expReward;
}

const char* CMonster::GetTypeName() const
{
    switch (mType)
    {
    case eMonsterType::SLIME:
        return "하급";
    case eMonsterType::GOBLIN:
        return "중급";
    case eMonsterType::ORC:
        return "상급";
    default:
        return "알 수 없음";
    }
}

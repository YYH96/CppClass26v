#pragma once

#include <Windows.h>
#include <ShlObj.h>

#include <cassert>
#include <fstream>
#include <iostream>

// 게임 시작 능력치
#define START_MAX_HP 100
#define START_ATTACK 10
#define START_GOLD 0
#define RESTORE_HP 30
#define START_STAGE 1
#define START_MAX_GOLD 100
#define START_MAX_EXP 100
#define GOLD_MAX_INCREASE_RATE 1.5F // 다음 층으로 갈 때 최대 골드에 곱할 배율
#define STAT_INCREASE_RATE 1.2F // 레벨업 시 증가하는 능력치에 곱할 배율

enum class eSceneType
{
    LOBBY = 0,
    GAME,
    COMBAT,
    COUNT
};

enum class eJobClass
{
    WARRIOR = 0,
    WIZARD,
    THIEF,
    ARCHER,
    COUNT
};

// 직업을 추가하거나 능력치를 변경할 때는 이 표만 수정한다.
// eJobClass는 0부터 시작하므로 열거형 값과 배열 인덱스가 바로 대응한다.
struct JobStat
{
    const char* name;
    int maxHP;
    int attack;
};

static const JobStat JOB_STAT_TABLE[] =
{
    { "전사",   150, 100 },
    { "마법사",  80, 180 },
    { "도적",   100, 140 },
    { "궁수",   110, 150 }
};

// enum에 직업만 추가하고 표 데이터를 빼먹으면 컴파일 단계에서 알려 준다.
static_assert(
    sizeof(JOB_STAT_TABLE) / sizeof(JOB_STAT_TABLE[0])
    == static_cast<int>(eJobClass::COUNT));

inline const JobStat& GetJobStat(eJobClass job)
{
    const int jobIndex = static_cast<int>(job);

    assert(jobIndex >= 0 && jobIndex < static_cast<int>(eJobClass::COUNT));
    return JOB_STAT_TABLE[jobIndex];
}

enum class eMonsterType
{
    SLIME = 0,
    GOBLIN,
    ORC,
    COUNT
};

// 탐색할 때 발생하는 사건이다.
// 숫자 대신 의미 있는 이름을 사용하면 switch의 각 분기가 무엇인지 쉽게 알 수 있다.
enum class eEventType
{
    NONE,
    GOLD,
    BATTLE,
    NEXT_STAGE,
    COUNT
};

// 메뉴 번호 입력 뒤 남은 줄바꿈을 버린 뒤, 새 Enter 입력을 기다린다.
// 여러 씬에서 공통으로 쓰는 간단한 콘솔 기능이므로 GameInfo.h에 함께 둔다.
namespace ConsoleUtils
{
    inline void WaitForEnter()
    {
        std::cout << "\n계속하려면 Enter를 누르세요...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }
}

// 몬스터별 콘솔 그림
// static 함수이므로 이 헤더를 포함한 각 cpp 파일 안에서만 사용되는 함수가 만들어진다.
// CMonster는 아래 함수의 주소를 함수 포인터에 저장해 전투 화면에서 호출한다.
namespace GlobalFunc
{
    static void PrintSlimeImage()
    {
        std::cout << R"(
      .-"""-.
     /       \
    |  o   o  |
    |    ^    |
     \  ---  /
      `-----`
)" << '\n';
    }

    static void PrintGoblinImage()
    {
        std::cout << R"(
       ,___,
      (o.o)
      / V \
     /|   |\
      |   |
     *W___W*
)" << '\n';
    }

    static void PrintOrcImage()
    {
        std::cout << R"(
      ,     ,
     | \*// |
     | o o  |
     (  -   )
      /| |\
     /_| |_\
)" << '\n';
    }
}

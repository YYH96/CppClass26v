#pragma once

// 게임 시작 능력치
#define START_MAX_HP 100
#define START_ATTACK 10
#define START_GOLD 0
#define RESTORE_HP 30
#define RESULT_DISPLAY_MILLISECOND 3000 // 행동 결과를 화면에 보여 줄 시간

enum class eSceneType
{
    LOBBY = 0,
    GAME,
    COUNT
};

enum class eJobClass
{
    WARRIOR = 1,
    WIZARD,
    THIEF,
    ARCHER
};

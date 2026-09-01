#pragma once

#include <climits>

// 빙고판의 한 변 길이와 전체 칸 수
#define BINGO_LINE_LENGTH 5
#define BINGO_BOARD_SIZE (BINGO_LINE_LENGTH * BINGO_LINE_LENGTH)
#define DEFAULT_SHUFFLE_COUNT 100
#define MARKED_NUMBER INT_MAX       // 숫자를 지운(표시한) 칸에 저장할 특별한 값
#define INVALID_BINGO_INDEX -1      // 빙고판에서 찾지 못했을 때의 인덱스

enum class eObjectType
{
    PLAYER = 0,
    AI,
    COUNT // 객체 목록 vector의 크기로 사용한다.
};

enum class eFinishResultType
{
    NONE,
    PLAYER_WIN,
    AI_WIN,
    DRAW,
    GAME_FINISH
};


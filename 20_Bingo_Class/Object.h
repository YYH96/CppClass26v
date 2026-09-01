#pragma once

#include "GameInfo.h"
#include <vector>

// 플레이어와 AI가 공통으로 사용하는 빙고판 기능을 모은 부모 클래스다.
class CObject
{
protected:
    std::vector<int> mBingo;
    int mBingoCount = 0;

    void Shuffle(int shuffleCount = DEFAULT_SHUFFLE_COUNT);

public:
    CObject();
    virtual ~CObject() = default; // 부모 포인터로 delete하기 위해 virtual이 필요하다.

    const std::vector<int>& GetBingoData() const
    {
        // 복사하지 않고 읽기 전용 참조로 반환한다.
        return mBingo;
    }

    int GetBingoCount() const
    {
        return mBingoCount;
    }

    bool BingoMarking(int inputNumber);
    int FindUnmarkedNumber(int inputNumber) const;

    int UpdateBingoCount();
    int CheckRowColumn() const;
    int CheckCross() const;
};


#include "Object.h"

#include <cstdlib>

CObject::CObject()
{
    // resize는 실제 원소 개수(size)를 25로 만든다.
    // reserve와 달리 []로 바로 접근할 수 있는 25개의 int 원소가 생긴다.
    mBingo.resize(BINGO_BOARD_SIZE);

    for (int i = 0; i < BINGO_BOARD_SIZE; ++i)
    {
        mBingo[i] = i + 1;
    }

    Shuffle();
}

void CObject::Shuffle(int shuffleCount)
{
    for (int i = 0; i < shuffleCount; ++i)
    {
        const int firstIndex = std::rand() % BINGO_BOARD_SIZE;
        const int secondIndex = std::rand() % BINGO_BOARD_SIZE;

        const int temp = mBingo[firstIndex];
        mBingo[firstIndex] = mBingo[secondIndex];
        mBingo[secondIndex] = temp;
    }
}

bool CObject::BingoMarking(int inputNumber)
{
    const int index = FindUnmarkedNumber(inputNumber);

    if (index == INVALID_BINGO_INDEX)
    {
        return false;
    }

    mBingo[index] = MARKED_NUMBER;
    return true;
}

int CObject::FindUnmarkedNumber(int inputNumber) const
{
    for (int i = 0; i < BINGO_BOARD_SIZE; ++i)
    {
        if (mBingo[i] == inputNumber)
        {
            return i;
        }
    }

    return INVALID_BINGO_INDEX;
}

int CObject::UpdateBingoCount()
{
    mBingoCount = CheckRowColumn() + CheckCross();
    return mBingoCount;
}

int CObject::CheckRowColumn() const
{
    int totalLineCount = 0;

    for (int rowOrColumn = 0; rowOrColumn < BINGO_LINE_LENGTH; ++rowOrColumn)
    {
        int markedRowCount = 0;
        int markedColumnCount = 0;

        for (int index = 0; index < BINGO_LINE_LENGTH; ++index)
        {
            if (mBingo[rowOrColumn * BINGO_LINE_LENGTH + index] == MARKED_NUMBER)
            {
                ++markedRowCount;
            }

            if (mBingo[rowOrColumn + index * BINGO_LINE_LENGTH] == MARKED_NUMBER)
            {
                ++markedColumnCount;
            }
        }

        if (markedRowCount == BINGO_LINE_LENGTH)
        {
            ++totalLineCount;
        }

        if (markedColumnCount == BINGO_LINE_LENGTH)
        {
            ++totalLineCount;
        }
    }

    return totalLineCount;
}

int CObject::CheckCross() const
{
    int totalLineCount = 0;
    int markedMainDiagonalCount = 0;
    int markedReverseDiagonalCount = 0;

    for (int i = 0; i < BINGO_LINE_LENGTH; ++i)
    {
        if (mBingo[i * BINGO_LINE_LENGTH + i] == MARKED_NUMBER)
        {
            ++markedMainDiagonalCount;
        }

        if (mBingo[i * BINGO_LINE_LENGTH + (BINGO_LINE_LENGTH - 1 - i)] == MARKED_NUMBER)
        {
            ++markedReverseDiagonalCount;
        }
    }

    if (markedMainDiagonalCount == BINGO_LINE_LENGTH)
    {
        ++totalLineCount;
    }

    if (markedReverseDiagonalCount == BINGO_LINE_LENGTH)
    {
        ++totalLineCount;
    }

    return totalLineCount;
}


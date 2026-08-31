/*
    배열 실습 - 빙고 게임 (플레이어 vs AI)

    1차원 배열 25칸을 5 x 5 빙고판처럼 사용한다.
    행 i, 열 j의 위치는 i * 5 + j로 계산한다.
    예: 2행 3열은 2 * 5 + 3, 즉 13번째 칸이다.

    - 플레이어와 AI는 각각 숫자 1~25를 섞은 빙고판을 가진다.
    - 선택된 숫자는 INT_MAX로 바꾸고 화면에는 *로 표시한다.
    - 가로 5줄, 세로 5줄, 대각선 2줄을 모두 검사한다.
    - 빙고 줄이 5개 이상이면 승리한다.
*/

#include <climits> // INT_MAX
#include <cstdlib> // rand, srand, system
#include <iostream>
#include <time.h>  // time

int main()
{
    srand((unsigned int)time(0));

    int nNumbers[25] = {};   // 플레이어 빙고판
    int nAINumbers[25] = {}; // AI 빙고판

    // 1~25를 두 빙고판에 각각 저장한다.
    for (int i = 0; i < 25; ++i)
    {
        nNumbers[i] = i + 1;
        nAINumbers[i] = i + 1;
    }

    // 두 빙고판을 각각 섞는다.
    for (int i = 0; i < 100; ++i)
    {
        int nIndex1 = rand() % 25;
        int nIndex2 = rand() % 25;
        int nTemp = nNumbers[nIndex1];
        nNumbers[nIndex1] = nNumbers[nIndex2];
        nNumbers[nIndex2] = nTemp;

        nIndex1 = rand() % 25;
        nIndex2 = rand() % 25;
        nTemp = nAINumbers[nIndex1];
        nAINumbers[nIndex1] = nAINumbers[nIndex2];
        nAINumbers[nIndex2] = nTemp;
    }

    int nLineCount = 0;
    int nAILineCount = 0;
    int nAISelect[25] = {}; // AI가 아직 선택할 수 있는 숫자 목록

    while (true)
    {
        system("cls");

        std::cout << "================ 플레이어 ================     ================== AI ==================\n";
        for (int i = 0; i < 5; ++i)
        {
            // 플레이어 빙고판 한 줄 출력
            for (int j = 0; j < 5; ++j)
            {
                if (nNumbers[i * 5 + j] == INT_MAX)
                {
                    std::cout << "*\t";
                }
                else
                {
                    std::cout << nNumbers[i * 5 + j] << '\t';
                }
            }

            std::cout << "||\t";

            // AI 빙고판 한 줄 출력
            for (int j = 0; j < 5; ++j)
            {
                if (nAINumbers[i * 5 + j] == INT_MAX)
                {
                    std::cout << "*\t";
                }
                else
                {
                    std::cout << nAINumbers[i * 5 + j] << '\t';
                }
            }
            std::cout << '\n';
        }

        std::cout << "플레이어 빙고: " << nLineCount
            << "\t\tAI 빙고: " << nAILineCount << "\n";

        if (nLineCount >= 5)
        {
            std::cout << "플레이어 승리!\n";
            break;
        }
        if (nAILineCount >= 5)
        {
            std::cout << "AI 승리!\n";
            break;
        }

        std::cout << "숫자를 입력하세요. (0: 게임 종료): ";
        int nInput = 0;
        std::cin >> nInput;

        if (nInput == 0)
        {
            std::cout << "게임을 종료합니다.\n";
            break;
        }
        if (nInput < 1 || nInput > 25)
        {
            std::cout << "1~25 사이의 숫자를 입력하세요.\n";
            system("pause");
            continue;
        }

        // 플레이어 빙고판에서 입력한 숫자를 찾아 *로 바꾼다.
        bool bFound = false;
        for (int i = 0; i < 25; ++i)
        {
            if (nNumbers[i] == nInput)
            {
                nNumbers[i] = INT_MAX;
                bFound = true;
                break;
            }
        }

        // 이미 선택한 숫자는 더 이상 고를 수 없다.
        if (bFound == false)
        {
            std::cout << "이미 선택한 숫자입니다.\n";
            system("pause");
            continue;
        }

        // 같은 숫자를 AI 빙고판에서도 찾아 *로 바꾼다.
        for (int i = 0; i < 25; ++i)
        {
            if (nAINumbers[i] == nInput)
            {
                nAINumbers[i] = INT_MAX;
                break;
            }
        }

        // AI 빙고판에서 아직 *이 아닌 숫자만 nAISelect 배열에 담는다.
        int nAISelectCount = 0;
        for (int i = 0; i < 25; ++i)
        {
            if (nAINumbers[i] != INT_MAX)
            {
                nAISelect[nAISelectCount] = nAINumbers[i];
                ++nAISelectCount;
            }
        }

        // 남은 숫자 중 하나를 AI가 무작위로 선택한다.
        if (nAISelectCount == 0)
        {
            break;
        }

        int nAIInput = nAISelect[rand() % nAISelectCount];
        std::cout << "AI가 선택한 숫자: " << nAIInput << '\n';

        // AI가 고른 숫자를 두 빙고판에서 모두 *로 바꾼다.
        for (int i = 0; i < 25; ++i)
        {
            if (nNumbers[i] == nAIInput)
            {
                nNumbers[i] = INT_MAX;
                break;
            }
        }
        for (int i = 0; i < 25; ++i)
        {
            if (nAINumbers[i] == nAIInput)
            {
                nAINumbers[i] = INT_MAX;
                break;
            }
        }

        // 빙고 줄 개수는 매 턴 새로 센다.
        nLineCount = 0;
        nAILineCount = 0;

        // 가로 5줄과 세로 5줄 검사
        for (int i = 0; i < 5; ++i)
        {
            int nPlayerRowStar = 0;
            int nPlayerColumnStar = 0;
            int nAIRowStar = 0;
            int nAIColumnStar = 0;

            for (int j = 0; j < 5; ++j)
            {
                if (nNumbers[i * 5 + j] == INT_MAX) // 가로: i행 j열
                {
                    ++nPlayerRowStar;
                }
                if (nNumbers[j * 5 + i] == INT_MAX) // 세로: j행 i열
                {
                    ++nPlayerColumnStar;
                }
                if (nAINumbers[i * 5 + j] == INT_MAX)
                {
                    ++nAIRowStar;
                }
                if (nAINumbers[j * 5 + i] == INT_MAX)
                {
                    ++nAIColumnStar;
                }
            }

            if (nPlayerRowStar == 5)
            {
                ++nLineCount;
            }
            if (nPlayerColumnStar == 5)
            {
                ++nLineCount;
            }
            if (nAIRowStar == 5)
            {
                ++nAILineCount;
            }
            if (nAIColumnStar == 5)
            {
                ++nAILineCount;
            }
        }

        // 왼쪽 위 -> 오른쪽 아래 대각선: 인덱스 0, 6, 12, 18, 24
        int nPlayerDiagonalStar = 0;
        int nAIDiagonalStar = 0;
        for (int i = 0; i < 25; i += 6)
        {
            if (nNumbers[i] == INT_MAX)
            {
                ++nPlayerDiagonalStar;
            }
            if (nAINumbers[i] == INT_MAX)
            {
                ++nAIDiagonalStar;
            }
        }
        if (nPlayerDiagonalStar == 5)
        {
            ++nLineCount;
        }
        if (nAIDiagonalStar == 5)
        {
            ++nAILineCount;
        }

        // 오른쪽 위 -> 왼쪽 아래 대각선: 인덱스 4, 8, 12, 16, 20
        nPlayerDiagonalStar = 0;
        nAIDiagonalStar = 0;
        for (int i = 4; i <= 20; i += 4)
        {
            if (nNumbers[i] == INT_MAX)
            {
                ++nPlayerDiagonalStar;
            }
            if (nAINumbers[i] == INT_MAX)
            {
                ++nAIDiagonalStar;
            }
        }
        if (nPlayerDiagonalStar == 5)
        {
            ++nLineCount;
        }
        if (nAIDiagonalStar == 5)
        {
            ++nAILineCount;
        }

        system("pause");
    }

    return 0;
}

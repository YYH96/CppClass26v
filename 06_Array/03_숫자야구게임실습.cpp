/*
    베이스볼 게임
    규칙
    - 숫자 3개를 맞추는 게임
    - 숫자는 1~9까지 사용한다.
    - 같은 숫자는 없다.

    - 위치까지 맞으면 스트라이크
    - 숫자만 맞으면 볼
    - 3볼이면 아웃
    - 3스트라이크면 게임 종료
*/

#include <cstdlib> // rand, srand
#include <iostream>
#include <time.h>  // time

int main()
{
    // 현재 시간으로 시드값을 결정한다.
    // 실행할 때마다 다른 랜덤 숫자가 나오도록 설정한다.
    srand((unsigned int)time(0));

    int nRandomNumbers[3] = { 0, }; // 랜덤 숫자 3개를 담을 배열
    int nPlayerNumbers[3] = { 0, }; // 플레이어가 입력한 숫자 3개를 담을 배열
    int nTotalCount = 0;             // 총 시도 횟수

    // 랜덤 숫자 3개를 만든다.
    for (int i = 0; i < 3; ++i)
    {
        nRandomNumbers[i] = (rand() % 9) + 1; // 1~9까지의 숫자

        // 앞에서 뽑은 숫자와 중복되는지 검사한다.
        for (int j = 0; j < i; ++j)
        {
            if (nRandomNumbers[i] == nRandomNumbers[j])
            {
                --i; // i값을 감소시켜서 같은 위치의 숫자를 다시 뽑는다.
                break;
            }
        }
    }

    while (true)
    {
        int nStrike = 0; // 스트라이크 개수
        int nBall = 0;   // 볼 개수

        // 플레이어가 숫자 3개를 입력한다.
        std::cout << "숫자 3개를 입력하세요 (1~9, 중복 없음): ";
        std::cin >> nPlayerNumbers[0] >> nPlayerNumbers[1] >> nPlayerNumbers[2];

        // 입력값 검증은 조건문 단원에서 배운 뒤 추가해 본다.

        // 스트라이크와 볼의 개수를 센다.
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (nPlayerNumbers[i] == nRandomNumbers[j]) // 숫자가 같은 경우
                {
                    if (i == j) // 위치도 같은 경우
                    {
                        ++nStrike;
                    }
                    else // 위치는 다르고 숫자만 같은 경우
                    {
                        ++nBall;
                    }
                }
            }
        }

        ++nTotalCount;
        std::cout << nStrike << " 스트라이크, " << nBall << " 볼\n";

        if (nStrike == 3)
        {
            std::cout << "3 스트라이크! 게임 종료!\n";
            std::cout << "총 시도 횟수: " << nTotalCount << '\n';
            break;
        }

        if (nBall == 3)
        {
            std::cout << "3 볼! 아웃! 다음 시도를 해보세요.\n";
        }
    }

    return 0;
}

/*
    짝수 맞추기 게임

    1~10 숫자가 각각 두 장씩, 총 20장의 카드에 들어 있다.
    두 카드의 인덱스를 선택해 값이 같으면 카드를 계속 공개한다.
    10개의 페어를 모두 맞추면 게임이 종료된다.
    -1을 입력하면 게임을 종료한다.
*/

#include <cstdlib> // rand, srand, system
#include <iostream>
#include <time.h>  // time

int main()
{
    srand((unsigned int)time(0));

    int nShuffle[20] = {};
    for (int i = 0; i < 10; ++i)
    {
        nShuffle[i] = i + 1;      // 1~10을 한 번 저장
        nShuffle[i + 10] = i + 1; // 1~10을 한 번 더 저장
    }

    /*
        셔플(Shuffle) 알고리즘

        1. 0~19 중 무작위 인덱스 두 개를 뽑는다.
        2. 두 인덱스에 있는 카드의 값을 서로 교환한다.
        3. 이 과정을 여러 번 반복하면 카드 위치가 섞인다.

        nTemp가 필요한 이유:
        nShuffle[nIndex1]의 값을 바로 덮어쓰면 원래 값을 잃어버린다.
        따라서 임시 변수 nTemp에 먼저 보관한 뒤 두 값을 교환한다.

        이 예제는 교환을 100번 반복하는 간단한 셔플 방식이다.
        매번 완전히 동일한 확률을 보장하는 정교한 셔플은 아니지만,
        배열의 인덱스와 값 교환을 연습하기에 적합하다.
    */
    for (int i = 0; i < 100; ++i)
    {
        // 예: nIndex1이 3, nIndex2가 15라면 3번 카드와 15번 카드의 자리를 바꾼다.
        int nIndex1 = rand() % 20;
        int nIndex2 = rand() % 20;

        int nTemp = nShuffle[nIndex1];
        nShuffle[nIndex1] = nShuffle[nIndex2];
        nShuffle[nIndex2] = nTemp;
    }

    bool bOpened[20] = {}; // 맞춰서 계속 공개할 카드인지 표시한다.
    int nInput = 0;
    int nPrevIndex = -1;   // 첫 번째로 선택한 카드의 인덱스
    int nSelectCount = 0;  // 이번 차례에 선택한 카드 수
    int nPair = 0;         // 맞춘 페어 수

    while (true)
    {
        system("cls"); // Windows 콘솔 화면을 지운 뒤 다시 출력한다.

        // 20장의 카드를 10 x 2 형태로 출력한다.
        for (int i = 0; i < 2; ++i)
        {
            // 카드 번호(인덱스)를 먼저 출력한다.
            for (int j = 0; j < 10; ++j)
            {
                std::cout << j + i * 10 << '\t';
            }
            std::cout << '\n';

            // 맞춘 카드는 숫자로, 아직 가려진 카드는 *로 출력한다.
            for (int j = 0; j < 10; ++j)
            {
                int nCurrentIndex = i * 10 + j;
                if (bOpened[nCurrentIndex] == true)
                {
                    std::cout << nShuffle[nCurrentIndex] << '\t';
                }
                else
                {
                    std::cout << "*\t";
                }
            }
            std::cout << "\n\n";
        }

        if (nPair == 10)
        {
            std::cout << "모든 페어를 맞추셨습니다! 게임 종료!\n";
            break;
        }

        // 두 번째 카드를 고른 다음 반복에서 두 카드가 같은지 확인한다.
        if (nSelectCount == 2)
        {
            if (nShuffle[nPrevIndex] == nShuffle[nInput])
            {
                std::cout << "짝을 맞추셨습니다!\n";
                ++nPair;
            }
            else
            {
                std::cout << "짝이 맞지 않습니다.\n";
                bOpened[nPrevIndex] = false;
                bOpened[nInput] = false;
            }

            nPrevIndex = -1;
            nSelectCount = 0;
            system("pause"); // 결과를 확인한 뒤 다음 화면으로 넘어간다.
            continue;
        }

        std::cout << "현재 맞춘 페어의 개수: " << nPair << '\n';
        std::cout << "카드 번호를 입력하세요. (-1: 종료): ";
        std::cin >> nInput;

        if (nInput == -1)
        {
            std::cout << "게임을 종료합니다.\n";
            break;
        }
        else if (nInput < 0 || nInput >= 20)
        {
            std::cout << "잘못된 입력입니다. 다시 입력하세요.\n";
            system("pause");
            continue;
        }
        else if (nInput == nPrevIndex)
        {
            std::cout << "같은 카드를 두 번 선택할 수 없습니다.\n";
            system("pause");
            continue;
        }
        else if (bOpened[nInput] == true)
        {
            std::cout << "이미 열린 카드입니다. 다시 입력하세요.\n";
            system("pause");
            continue;
        }

        bOpened[nInput] = true;

        if (nPrevIndex == -1) // 첫 번째 카드를 고른 경우
        {
            nPrevIndex = nInput;
        }

        ++nSelectCount;
    }

    return 0;
}

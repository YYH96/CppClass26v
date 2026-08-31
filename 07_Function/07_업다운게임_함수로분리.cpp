#include <cstdlib>
#include <iostream>
#include <time.h>

/*
    업다운 게임 - 함수를 사용해 분리한 버전

    main()에는 게임의 전체 순서만 남긴다.
    숫자 만들기, 입력, 정답 확인처럼 역할이 다른 코드는 각각 함수로 분리한다.
*/

// 함수 선언: 함수 정의를 main() 아래에 작성하기 위해 미리 알린다.
int CreateSecretNumber();
int GetUserGuess();
bool CheckGuess(int secretNumber, int userGuess);

int main()
{
    srand((unsigned int)time(0));

    int secretNumber = CreateSecretNumber();
    int guessCount = 0;

    std::cout << "1부터 100까지의 숫자를 맞혀보세요!\n";

    while (true)
    {
        int userGuess = GetUserGuess();
        ++guessCount;

        // CheckGuess가 true를 반환하면 정답이므로 게임을 끝낸다.
        if (CheckGuess(secretNumber, userGuess))
        {
            std::cout << "정답! " << guessCount << "번 만에 맞혔습니다.\n";
            break;
        }
    }

    return 0;
}

int CreateSecretNumber()
{
    return rand() % 100 + 1; // 1~100
}

int GetUserGuess()
{
    int userGuess = 0;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> userGuess;
    return userGuess;
}

bool CheckGuess(int secretNumber, int userGuess)
{
    if (userGuess < secretNumber)
    {
        std::cout << "UP! 비밀 숫자보다 작습니다.\n";
        return false;
    }

    if (userGuess > secretNumber)
    {
        std::cout << "DOWN! 비밀 숫자보다 큽니다.\n";
        return false;
    }

    return true;
}

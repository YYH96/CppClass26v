#include <cstdlib>
#include <iostream>
#include <time.h>

/*
    업다운 게임 - main()만 사용한 버전

    1~100 사이의 비밀 숫자를 맞힌다.
    입력값이 비밀 숫자보다 작으면 UP, 크면 DOWN을 출력한다.
    이 파일은 모든 게임 흐름을 main() 안에 작성한 비교용 예제다.
*/

int main()
{
    srand((unsigned int)time(0));

    int secretNumber = rand() % 100 + 1; // 1~100
    int guessCount = 0;
    bool isGameOver = false;

    std::cout << "1부터 100까지의 숫자를 맞혀보세요!\n";

    while (isGameOver == false)
    {
        int userGuess = 0;
        std::cout << "숫자를 입력하세요: ";
        std::cin >> userGuess;

        ++guessCount;

        if (userGuess < secretNumber)
        {
            std::cout << "UP! 비밀 숫자보다 작습니다.\n";
        }
        else if (userGuess > secretNumber)
        {
            std::cout << "DOWN! 비밀 숫자보다 큽니다.\n";
        }
        else
        {
            std::cout << "정답! " << guessCount << "번 만에 맞혔습니다.\n";
            isGameOver = true;
        }
    }

    return 0;
}
